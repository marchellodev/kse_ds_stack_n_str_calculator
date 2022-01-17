#include <iostream>
#include <vector>

#include "Stack.h"

using namespace std;

int main() {
    Stack<int> stack{};

//    for(int i =0; i < 100000; i++){
//        for(int j =0; j < 100000; j++) {
//            stack.push(20);
//            stack.push(30);
//            stack.push(40);
//            stack.push(50);
//            stack.push(60);
//        }
//    }

    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);

    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    return 0;
}
