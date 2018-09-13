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
    Runnable() {}
    virtual void execute() {}
    // TODO: delete constructurs
};

class TestRunnable : public Runnable {
private:
    int id;
public:
    TestRunnable(int i) : id(i){}

    void execute() {
        cout << "Hello from runnable: " << id << endl;
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
    {
        coordinator = thread([this]{ this->coordinate(); });

        for(int i = 0; i < numThreads; i++) {
            workers.push_back(thread([this, i]{ this->work(i); }));
        }
    }

    void queueWork(shared_ptr<Runnable> r) {
        lock_guard guard(queueMutex);
        coordCv.notify_all();
    }

    ~ThreadPool() {
        for(int i = 0; i < workers.size(); i++) {
            workers[i].join();
        }
    }
private:
    void coordinate() {
        mutex coordMutex;
        while(1) {
            std::unique_lock<std::mutex> lck(coordMutex);
            coordCv.wait(lck);

            shared_ptr<Runnable> runnable;
            runnable = runnableQueue.front();
            runnableQueue.pop();

            workerCv.notify_all();
        }
    }

    void work(const int id) {
        while(1) {
            std::unique_lock<std::mutex> lck(workerMutex);
            workerCv.wait(lck);

            auto runnable = queuePop();
            if(runnable)
                runnable->execute();
        }
    }

    shared_ptr<Runnable> queuePop() {
        lock_guard guard(queueMutex);
        if(runnableQueue.empty()) 
            return nullptr;

        auto runnable = runnableQueue.front();
        runnableQueue.pop();
        return runnable;
    }
    void queuePush(shared_ptr<Runnable> runnable) {
        lock_guard guard(queueMutex);
        runnableQueue.push(runnable);
    }  
private:
    int numThreads;

    condition_variable coordCv;
    mutex queueMutex;

    queue<shared_ptr<Runnable>> runnableQueue;

    thread coordinator;
    vector<thread> workers;
    condition_variable workerCv;
    mutex workerMutex;
};

int main() {
    int numThreads = 5;
    ThreadPool tp(numThreads);

    while(numThreads-- > 0) {
        shared_ptr<TestRunnable> testRunnable = make_shared<TestRunnable>(new TestRunnable(numThreads));
        tp.queueWork(static_pointer_cast<Runnable>(testRunnable));
    }
    // wait for a few seconds
    
    return 0;
}