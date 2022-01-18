#include <iostream>
#include <cstring>
#include "Stack.h"

template<typename T>
void Stack<T>::push(T el) {

    // resizing the array
    if (pointer >= size) {
        int newSize = this->size * 2;
        T *arr2 = new T[newSize];

        memcpy(arr2, this->arr, sizeof(T) * this->size);
        this->size = newSize;

        this->arr = arr2;
    }

    this->arr[pointer] = el;
    pointer++;
}

template<typename T>
T Stack<T>::pop() {
    this->pointer--;

    return this->arr[pointer];
}

template<typename T>
Stack<T>::Stack() {
    this->arr = new T[size];
}

template<typename T>
Stack<T>::~Stack() {
    delete[] this->arr;
}

template<typename T>
bool Stack<T>::canPop() {
    return pointer != 0;
}
