#include <iostream>
#include <vector>

#include "Stack.h"

using namespace std;

int main() {
    Stack stack;

    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    return 0;
}
