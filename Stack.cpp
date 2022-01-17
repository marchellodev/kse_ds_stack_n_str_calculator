#include <iostream>
#include <cstring>
#include "Stack.h"

void Stack::push(int el) {

    // resizing the array
    if (pointer >= size) {
        int newSize = this->size * 2;
        int *arr2 = new int[newSize];

        memcpy(arr2, this->arr, sizeof(int) * this->size);
        this->size = newSize;

//        for (int i = 0; i <= pointer; i++) {
//            arr2[i] = this->arr[i];
//        }

        this->arr = arr2;
        std::cout << "Resizing for " << el << " " << pointer << " " << size << std::endl;
    }

    this->arr[pointer] = el;
    pointer++;
}

int Stack::pop() {
    this->pointer--;

    return this->arr[pointer];
}

Stack::Stack() {
    this->arr = new int[size];
}

Stack::~Stack() {
    delete[] this->arr;
}