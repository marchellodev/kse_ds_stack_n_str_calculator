#pragma once

template <typename T>

class Stack {
private:
    T *arr;
    int size = 10;
    int pointer = 0;

public:
    Stack();
    ~Stack();

    void push(T el);
    T pop();
    bool canPop();
};

#include "Stack.ipp"