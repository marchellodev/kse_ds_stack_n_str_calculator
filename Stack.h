#pragma once

class Stack {
private:
    int *arr;
    int size = 10;
    int pointer = 0;

public:
    Stack();
    ~Stack();

    void push(int el);

    int pop();
};
