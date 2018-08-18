#include <iostream>
#include <thread>
#include <queue>
#include <memory>
#include <vector>
#include <mutex>
#include <condition_variable>

using namespace std;

class Runnable {
public:
    virtual void execute() = 0;
    // TODO: delete constructurs
};

class TestClass : Runnable {
public:
    static int id = 0;
    void execute() {
        cout << "Hello from runnable: " << id++ << endl;
    }
};

// Designed to be accessed by a single thread 
// TODO: make multi-threaded access possible
class ThreadPool {
public:
    ThreadPool() {
    }

    ThreadPool(const int n) 
    : numThreads(n) 
    , workerMutexes(vector<mutex>(n)) 
    , workerCvs(vector<condition_variable>(n)) 
    {
        this->coordinator = thread(this->coordinate);

        for(int i = 0; i < numThreads; i++) {
            workers.push_back(thread(this->work, this, i));
        }
    }

    void queueWork(shared_ptr<Runnable> r) {
        lock_guard guard(queueMutex);
        coordCv.notify_all();
    }

private:
    void coordinate() {
        while(1) {
            std::unique_lock<std::mutex> lck(queueMutex);
            coordCv.wait(lck);

            int threadId;
            shared_ptr<Runnable> runnable;

            runnable = runnableQueue.front();
            runnableQueue.pop();

            workerCvs[threadId].notify_all();
        }
    }

    void work(const int id) {
        while(1) {
            std::unique_lock<std::mutex> lck(workerMutexes[id]);
            workerCvs[id].wait(lck);

            auto runnable = queuePop();
            runnable->execute();
        }
    }

    ~ThreadPool() {
        for(int i = 0; i < workers.size(); i++) {
            workers[i].join();
        }
    }
private:
    shared_ptr<Runnable> queuePop() {
        lock_guard guard(queueMutex);
        auto runnable = runnableQueue.front();
        runnableQueue.pop();
        return runnable;
    }
    void queuePush(shared_ptr<Runnable> runnable) {
        lock_guard guard(queueMutex);
        runnableQueue.push(runnable);
    }  
private:

    condition_variable coordCv;
    mutex queueMutex;

    queue<shared_ptr<Runnable>> runnableQueue;

    int numThreads;
    thread coordinator;
    vector<thread> workers;
    vector<condition_variable> workerCvs;
    vector<mutex> workerMutexes;
};

int main() {
    ThreadPool tp(5);

    // wait for a few seconds
    
    return 0;
}