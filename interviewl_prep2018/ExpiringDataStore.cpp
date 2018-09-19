#include <iostream>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <priority_queue>

using namespace std;

// Design an efficient key/value store with an exiration. 
// For example, insert(key, expiration) where item is removed ater expiration seconds.

// Approaches:
// - Have a worker thread that wakes up every second and removes itmes that have expired
//      - need to keep track of when the item was inserted
//      - optimized for reads
// - Start a timer for each item inserted
//      - does not scale well to many writes
template<typename T, typename U>
class ExpiringMap {
public:
    ExpiringMap() {
        worker = Thread([ref(this)](){
            
        });
    }

    void insert(T key, U value, int expiration) {
        lock_guard<mutex> guard(mut);

    }

    ~ExpiringMap() {
        // TODO: gracefully exit worker
    }

private:
    struct ValTTL {
        U value;
        long insertTime;
        long ttl;
        KeyTTL(U val, long i, long t) : value(val), insertTime(i), ttl(t){};
    };

    unordered_map<T, ValTTL> hashTable;

    mutex mut;
    thread worker;
};