#include <iostream>
#include "InhStack.h"
#include "InhQueue.h"

using namespace std;

int main()
{
    InhStack<int> aStack;
    InhQueue<int> aQueue;

    aStack.push(1);
    aStack.push(2);
    aStack.push(3);

    cout << "Stack: " << aStack.toString() << endl;

    aStack.pop();

    cout << "Stack: " << aStack.toString() << endl;

    aQueue.enqueue(1);
    aQueue.enqueue(2);
    aQueue.enqueue(3);

    cout << "Queue: " << aQueue.toString() << endl;

    aQueue.dequeue();

    cout << "Queue: " << aQueue.toString() << endl;

    return 0;
}
