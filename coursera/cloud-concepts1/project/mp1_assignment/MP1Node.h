/**********************************
 * FILE NAME: MP1Node.cpp
 *
 * DESCRIPTION: Membership protocol run by this Node.
 *                 Header file of MP1Node class.
 **********************************/

#ifndef _MP1NODE_H_
#define _MP1NODE_H_

#include "stdincludes.h"
#include "Log.h"
#include "Params.h"
#include "Member.h"
#include "EmulNet.h"
#include "Queue.h"

/**
 * Macros
 */
#define TREMOVE 20
#define TFAIL 5

/*
 * Note: You can change/add any functions in MP1Node.{h,cpp}
 */

/**
 * Message Types
 */
enum MsgTypes{
    JOINREQ,
    JOINREP,
    ALLTOALL,
    DUMMYLASTMSGTYPE
};

/**
 * STRUCT NAME: MessageHdr
 *
 * DESCRIPTION: Header and content of a message
 */
typedef struct MessageHdr {
    enum MsgTypes msgType;
}MessageHdr;

/**
 * CLASS NAME: MP1Node
 *
 * DESCRIPTION: Class implementing Membership protocol functionalities for failure detection
 */
class MP1Node {
private:
    EmulNet *emulNet;
    Log *log;
    Params *par;
    Member *memberNode;
    char NULLADDR[6];

public:
    MP1Node(Member *, Params *, EmulNet *, Log *, Address *);
    Member * getMemberNode() {
        return memberNode;
    }
    int recvLoop();
    static int enqueueWrapper(void *env, char *buff, int size);
    void nodeStart(char *servaddrstr, short serverport);
    int initThisNode(Address *joinaddr);
    int introduceSelfToGroup(Address *joinAddress);
    int finishUpThisNode();
    void nodeLoop();
    void checkMessages();
    bool recvCallBack(void *env, char *data, int size);
    void nodeLoopOps();
    int isNullAddress(Address *addr);
    Address getJoinAddress();
    void initMemberListTable(Member *memberNode);
    void printAddress(Address *addr);
    void memberListMerge(vector<MemberListEntry>& v);
    Address createAddress(const int id, const short port);
    int findMemberListEntry(int id);
    virtual ~MP1Node();
};

// CSC: caller's responsibility to free
class Message {
public:
    Message(MsgTypes msgType, Address& addr, int heartbeat, char* data, size_t dataSize) {
        Base base;
        base.msgHdr.msgType = msgType;
        memcpy(&base.addr, addr.addr, sizeof(base.addr));
        base.heartbeat = heartbeat;

        mSize = sizeof(base) + dataSize;
        mBuffer = (char*)malloc(sizeof(base) + dataSize); 

        memcpy(mBuffer, &base, sizeof(base));

        if(data) {
            memcpy(mBuffer + sizeof(base), data, dataSize);
        }
    }

    Message(char* data, size_t size) {
        mBuffer = data;
        mSize = size;
    }

    MessageHdr getMessageHdr() {
        return ((Base*)mBuffer)->msgHdr;
    }

    void getAddr(char* output) {
        memcpy(output, ((Base*)mBuffer)->addr, 6);
    }

    int getHeartbeat() {
        return ((Base*)mBuffer)->heartbeat;
    }

    char* getMiscData() {
        return mBuffer + sizeof(Base);
    }

    char* getAllData() {
        return mBuffer;
    }

    size_t getSize() {
        return mSize;
    }

    size_t getSizeMiscData() {
        return mSize - sizeof(Base);
    }

    ~Message() {
        // CSC: caller's responsibility to free
        //free(mBuffer); 
    }

private:
    size_t mSize;
    char *mBuffer;

    struct Base {
        MessageHdr msgHdr;
        char addr[6];
        int heartbeat;
    };

    Message() {};
};

#endif /* _MP1NODE_H_ */
