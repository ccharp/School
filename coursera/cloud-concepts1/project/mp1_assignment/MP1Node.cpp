/**********************************
 * FILE NAME: MP1Node.cpp
 *
 * DESCRIPTION: Membership protocol run by this Node.
 *                 Definition of MP1Node class functions.
 **********************************/

#include "MP1Node.h"
#include <algorithm>

/*
 * Note: You can change/add any functions in MP1Node.{h,cpp}
 */



/**
 * Overloaded Constructor of the MP1Node class
 * You can add new members to the class if you think it
 * is necessary for your logic to work
 */
MP1Node::MP1Node(Member *member, Params *params, EmulNet *emul, Log *log, Address *address) {
    for( int i = 0; i < 6; i++ ) {
        NULLADDR[i] = 0;
    }
    this->memberNode = member;
    this->emulNet = emul;
    this->log = log;
    this->par = params;
    this->memberNode->addr = *address;
}

/**
 * Destructor of the MP1Node class
 */
MP1Node::~MP1Node() {}

/**
 * FUNCTION NAME: recvLoop
 *
 * DESCRIPTION: This function receives message from the network and pushes into the queue
 *                 This function is called by a node to receive messages currently waiting for it
 */
int MP1Node::recvLoop() {
    if ( memberNode->bFailed ) {
        return false;
    }
    else {
        return emulNet->ENrecv(&(memberNode->addr), enqueueWrapper, NULL, 1, &(memberNode->mp1q));
    }
}

/**
 * FUNCTION NAME: enqueueWrapper
 *
 * DESCRIPTION: Enqueue the message from Emulnet into the queue
 */
int MP1Node::enqueueWrapper(void *env, char *buff, int size) {
    Queue q;
    return q.enqueue((queue<q_elt> *)env, (void *)buff, size);
}

/**
 * FUNCTION NAME: nodeStart
 *
 * DESCRIPTION: This function bootstraps the node
 *                 All initializations routines for a member.
 *                 Called by the application layer.
 */
void MP1Node::nodeStart(char *servaddrstr, short servport) {
    Address joinaddr;
    joinaddr = getJoinAddress();

    // Self booting routines
    if( initThisNode(&joinaddr) == -1 ) {
#ifdef DEBUGLOG
        log->LOG(&memberNode->addr, "init_thisnode failed. Exit.");
#endif
        exit(1);
    }

    if( !introduceSelfToGroup(&joinaddr) ) {
        finishUpThisNode();
#ifdef DEBUGLOG
        log->LOG(&memberNode->addr, "Unable to join self to group. Exiting.");
#endif
        exit(1);
    }

    return;
}

/**
 * FUNCTION NAME: initThisNode
 *
 * DESCRIPTION: Find out who I am and start up
 */
int MP1Node::initThisNode(Address *joinaddr) {
    /*
     * This function is partially implemented and may require changes
     */
    // CSC: not needed here? int id = *(int*)(&memberNode->addr.addr);
    // int port = *(short*)(&memberNode->addr.addr[4]);

    memberNode->bFailed = false;
    memberNode->inited = true;
    memberNode->inGroup = false;
    // node is up!
    memberNode->nnb = 0;
    memberNode->heartbeat = 0;
    memberNode->pingCounter = TFAIL;
    memberNode->timeOutCounter = -1;

    initMemberListTable(memberNode);

    // CSC: membership list is initizliaed via reception of messages

    // Initialized this node's address
    //emulNet->ENinit(&memberNode->addr, port);

    return SUCCESS;
}

/**
 * FUNCTION NAME: introduceSelfToGroup
 *
 * DESCRIPTION: Join the distributed system
 */
int MP1Node::introduceSelfToGroup(Address *joinaddr) {
    MessageHdr *msg;

/*CSC
        log->LOG(&memberNode->addr, "membernode:" );
        sprintf(s, "%i", *(int*)(&memberNode->addr.addr[0]));
        log->LOG(&memberNode->addr, s);

        log->LOG(&memberNode->addr, "joinaddr:");
        sprintf(s, "%i", *(int*)(&joinaddr->addr[0]));
        log->LOG(&memberNode->addr, s);
*/

    if ( 0 == memcmp((char *)&(memberNode->addr.addr), (char *)&(joinaddr->addr), sizeof(memberNode->addr.addr))) {
        // I am the group booter (first process to join the group). Boot up the group
#ifdef DEBUGLOG
        log->LOG(&memberNode->addr, "Starting up group...");
#endif
        memberNode->inGroup = true;
    }
    else {
        //size_t msgsize = sizeof(MessageHdr) + sizeof(joinaddr->addr) + sizeof(long) + 1;
        //msg = (MessageHdr *) malloc(msgsize);

        // create JOINREQ message: format of data is {struct Address myaddr}
        //msg->msgType = JOINREQ;
        //memcpy((char *)(msg+1), &memberNode->addr.addr, sizeof(memberNode->addr.addr));
        //memcpy((char *)(msg+1) + 1 + sizeof(memberNode->addr.addr), &memberNode->heartbeat, sizeof(long));

        Message m(JOINREQ, memberNode->addr, memberNode->heartbeat, NULL, 0);
        /*
#ifdef DEBUGLOG
        sprintf(s, "Trying to join...");
        log->LOG(&memberNode->addr, s);
#endif
        #ifdef DEBUGLOG
        char six[6];
        m.getAddr(&six[0]);
        char buf[256];
        sprintf(
            buf, "Addr %i, member list", 
            *(int*)(&six[0])
            //*(int*)(&memberNode->addr.addr[0])
        );
        log->LOG(joinaddr, buf);

        #endif*/

        // send JOINREQ message to introducer member
        emulNet->ENsend(&memberNode->addr, joinaddr, m.getAllData(), m.getSize());
        memberNode->inGroup = true;
        
//        free(m.getAllData());
    }

    return 1;

}

/**
 * FUNCTION NAME: finishUpThisNode
 *
 * DESCRIPTION: Wind up this node and clean up state
 */
int MP1Node::finishUpThisNode(){
   /*
    * Your code goes here
    */
#ifdef DEBUGLOG
        log->LOG(&memberNode->addr, "in FINISH UP.");
#endif
    return 0;
}

/**
 * FUNCTION NAME: nodeLoop
 *
 * DESCRIPTION: Executed periodically at each member
 *                 Check your messages in queue and perform membership protocol duties
 */
void MP1Node::nodeLoop() {
    if (memberNode->bFailed) {
        return;
    }

    // Check my messages
    checkMessages();

    // Wait until you're in the group...
    if( !memberNode->inGroup ) {
        return;
    }

    // ...then jump in and share your responsibilites!
    nodeLoopOps();

    return;
}

/**
 * FUNCTION NAME: checkMessages
 *
 * DESCRIPTION: Check messages in the queue and call the respective message handler
 */
void MP1Node::checkMessages() {
    void *ptr;
    int size;

    // Pop waiting messages from memberNode's mp1q
    while ( !memberNode->mp1q.empty() ) {
        ptr = memberNode->mp1q.front().elt;
        size = memberNode->mp1q.front().size;
        memberNode->mp1q.pop();
        recvCallBack((void *)memberNode, (char *)ptr, size);
    }
    return;
}

Address MP1Node::createAddress(const int id, const short port) {
    Address addr;

    memcpy(addr.addr, &id, sizeof(id));
    memcpy(addr.addr + sizeof(id), &port, sizeof(port));

    return addr;
}

void MP1Node::memberListMerge(vector<MemberListEntry>& v) {
    // CSC: yeah, it's pretty inefficient
    for(auto candidate : v) {  
        
        bool exists = false;
        // see if a node with this ID exists already in the list
        for(int i =0; i < memberNode->memberList.size(); i++) {
            MemberListEntry* mle = &memberNode->memberList[i];

            if(candidate.id == mle->id) {
                exists = true;
                
            #ifdef DEBUGLOG
                Address addr = createAddress(candidate.id, candidate.port);
                //log->LOG(&addr, "Updating heartbeat!!!!!.");
            #endif
                mle->heartbeat = std::max(candidate.heartbeat, mle->heartbeat);
                //mle->timeout   = std::max(candidate.timeout, mle->timeout);
            }
        }

        if(!exists) {
            Address addr = createAddress(candidate.id, candidate.port);

            log->logNodeAdd(&memberNode->addr, &addr);
            memberNode->memberList.push_back(candidate);
        }
    }
}

/**
 * FUNCTION NAME: recvCallBack
 *
 * DESCRIPTION: Message handler for different message types
 */
bool MP1Node::recvCallBack(void *env, char *data, int size ) {
    Address addr;

    Message mReceived(data, size);

    MessageHdr msgHdr = mReceived.getMessageHdr();
    mReceived.getAddr(addr.addr);
    
    switch(msgHdr.msgType) {
        case JOINREQ: 
        {
            // Add to member list
            MemberListEntry mle; 
            mle.id   = *(int*)(addr.addr);
            mle.port = *(short*)(&addr.addr[4]);
            memberNode->memberList.push_back(mle);

            log->logNodeAdd(&memberNode->addr, &addr);
                
            Message mSend(
                JOINREP, 
                memberNode->addr, 
                memberNode->heartbeat,
                (char*)&memberNode->memberList[0],
                (sizeof(MemberListEntry) * memberNode->memberList.size())
            );
            
            emulNet->ENsend(&memberNode->addr, &addr, mSend.getAllData(), mSend.getSize());
            break;
        }
        case ALLTOALL:
            
        case JOINREP:
        {
            MemberListEntry* memberData = (MemberListEntry*)mReceived.getMiscData(); 
            int numMembers = mReceived.getSizeMiscData() / sizeof(MemberListEntry);

            vector<MemberListEntry> tmp;
            for(int i = 0; i < numMembers; i++) {
                tmp.push_back(memberData[i]);
            }

            memberListMerge(tmp);

            break;
        }
        default:
        {
            #ifdef DEBUGLOG
            log->LOG(&addr, "Invalid Messager Type.");
            #endif

            break;
        }
    }

    return true;
}

// wait for 3 cycles without heartbeat
#define MAX_HEARTBEAT_WAIT 10 
#define MAX_TIMEOUT 20 

int MP1Node::findMemberListEntry(int id) {

    for(int i = 0; i < memberNode->memberList.size(); i++) {
        if(memberNode->memberList[i].id = id) {
            return i;
        }
    }

    return -1;
}

/**
 * FUNCTION NAME: nodeLoopOps
 *
 * DESCRIPTION: Check if any node hasn't responded within a timeout period and then delete
 *                 the nodes
 *                 Propagate your membership list
 */
void MP1Node::nodeLoopOps() {

    memberNode->timeOutCounter += 1;
    int currTime = memberNode->timeOutCounter;

    memberNode->heartbeat = currTime;

    // update this entry's heartbeat in the membership list
    int id = *(int*)(&memberNode->addr.addr);
    int index = findMemberListEntry(id);
    memberNode->memberList[index].heartbeat = currTime;

    // CSC: here, we'll implement a super inefficient all-t0-all proliferation scheme
    for(int i = 0; i < memberNode->memberList.size(); i++) {
        MemberListEntry* mle = &memberNode->memberList[i];

        Address addr = createAddress(mle->id, mle->port);

        // look for unrespnosive nodes
        //if(!mle->removed) {
        if(mle->timestamp != -1) {
            if(currTime - mle->heartbeat > MAX_HEARTBEAT_WAIT) {
                log->logNodeRemove(&memberNode->addr, &addr);
                //mle->timeout += 1; 

                mle->timestamp = -1;
            }/* else if(mle->timeout > MAX_TIMEOUT) {
                memberNode->memberList.erase(memberNode->memberList.begin() + i);
                #ifdef DEBUGLOG
                log->LOG(&addr, "Something timedout.");
                #endif
            } else {
                mle->timeout = 0;
            }*/
        }

        // don't message yourself
        if(!(memberNode->addr == addr)) {
            Message mSend(
                ALLTOALL, 
                memberNode->addr, 
                memberNode->heartbeat,
                (char*)&memberNode->memberList[0],
                (sizeof(MemberListEntry) * memberNode->memberList.size())
            );

            emulNet->ENsend(&memberNode->addr, &addr, mSend.getAllData(), mSend.getSize());
        }
    }

    return;
}

/**
 * FUNCTION NAME: isNullAddress
 *
 * DESCRIPTION: Function checks if the address is NULL
 */
int MP1Node::isNullAddress(Address *addr) {
    return (memcmp(addr->addr, NULLADDR, 6) == 0 ? 1 : 0);
}

/**
 * FUNCTION NAME: getJoinAddress
 *
 * DESCRIPTION: Returns the Address of the coordinator
 */
Address MP1Node::getJoinAddress() {
    Address joinaddr;

    memset(&joinaddr, 0, sizeof(Address));
    *(int *)(&joinaddr.addr) = 1;
    *(short *)(&joinaddr.addr[4]) = 0;

    return joinaddr;
}

/**
 * FUNCTION NAME: initMemberListTable
 *
 * DESCRIPTION: Initialize the membership list
 */
void MP1Node::initMemberListTable(Member *memberNode) {
    memberNode->memberList.clear();

    MemberListEntry mle;
    mle.setid(*(int*)(&memberNode->addr.addr));

    // add self to membership table
    memberNode->memberList.push_back(mle);

    log->logNodeAdd(&memberNode->addr, &memberNode->addr);
}

/**
 * FUNCTION NAME: printAddress
 *
 * DESCRIPTION: Print the Address
 */
void MP1Node::printAddress(Address *addr)
{
    printf("%d.%d.%d.%d:%d \n",  addr->addr[0],addr->addr[1],addr->addr[2],
                                                       addr->addr[3], *(short*)&addr->addr[4]) ;    
}
