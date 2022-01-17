#include <iostream>
#include <vector>

#include "lib/Stack.h"
#include "tokenization.cpp"

using namespace std;

int calculate(string str) {
    return 10;
}


int main() {

    while (true) {
        string str;
        cout << "> ";
        cin >> str;

//        int result = calculate(str);

//        cout << "> " << result << endl;
        cout << "> " << Token(str[0]).type << endl;
        cout << "> " << Token(str[0]).value.value_or(-1) << endl;

        cout << endl;
    }


    return 0;
}
