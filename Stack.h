#pragma once

class Stack {
private:
    int *arr;
    int size = 2;
    int pointer = 0;

public:
    Stack();
    ~Stack();

    void push(int el);

    int pop();
};
