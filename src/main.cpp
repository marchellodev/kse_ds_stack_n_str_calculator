#include <iostream>
#include <vector>

#include "lib/Stack.h"
#include "Token.cpp"

using namespace std;


vector<Token> tokenify(string str) {
    vector<Token> result;

    // buffer containing temporary data
    vector<Token> numBuffer;

    for (char &c: str) {
        auto token = Token(c);

        // if prev value was a number
        if (!numBuffer.empty()) {

            if (token.type == Value) {
                // if current value is a number, add it to the buffer
                numBuffer.push_back(token);
            } else {
                // if not, combine the buffer into one token
                // FIXME: see above
                cout << "FIXME" << endl;
//                result.push_back(numBuffer);
            }

            numBuffer.clear();
        }

        if (token.type == Value) {
            numBuffer.push_back(token);
            continue;
        }

        result.push_back(token);

        // for debug purposes
        cout << token.type << "| " << token.value.value_or(-1) << " - " << c << endl;

//        cout << c << endl;

    }

    if (!numBuffer.empty()) {
        cout << "FIXME" << endl;
    }


    return result;
}

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
//        cout << "> " << Token(str[0]).type << endl;
//        cout << "> " << Token(str[0]).value.value_or(-1) << endl;
        cout << tokenify(str).size() << endl;

        cout << endl;
    }


    return 0;
}
