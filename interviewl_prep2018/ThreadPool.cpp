#include <iostream>
#include <thread>
#include <queue>
#include <memory>
#include <vector>

using namespace std;

class Runnable {
    virtual void execute() = 0;
};

class TestClass : Runnable {
public:
    int id;
    void execute() {
        cout << "Hello from runnable: " << id << endl;
    }
};

class ThreadPool {
public:
    ThreadPool() {
    }

    ThreadPool(const int n) : numThreads(n) {
        
        this->coordinator = thread(this->coordinate);

        for(int i = 0; i < numThreads; i++) {
            workers.push_back(thread(this->work));
            workMappings.push_back(nullptr);
        }
    }

    void queueWork(shared_ptr<Runnable> r) {
        qRunnables.push(r);
        // signal coordinator
    }

private:
    void coordinate() {
        while(1) {
            // wait for signal that we have work
            if(qThreads.empty()) {
                // wait for signal from finished thread
            } else {
                int threadId; // = something
                auto runnable = qRunnables.front();
                qRunnables.pop();

                workMappings[threadId] = runnable;
                // signal thread to continue
            }
        }
    }

    void work(shared_ptr<Runnable> runnable) {

    }

private:
    queue<thread> qThreads;
    queue<shared_ptr<Runnable>> qRunnables;;

    int numThreads;
    thread coordinator;
    vector<thread> workers;
    vector<shared_ptr<Runnable>> workMappings;
};

int main() {
    ThreadPool tp(5);
    return 0;
}