#include <iostream>
#include <vector>

#include "lib/Stack.h"
#include "Token.cpp"

using namespace std;


vector<Token> tokenify(const string &str) {
    vector<Token> result;

    // buffer for temporary data
    vector<Token> numBuffer;

    for (char c: str) {
        if(c == ' '){
            continue;
        }

        auto token = Token(c);

        // if prev value was a number
        if (!numBuffer.empty()) {
            if (token.type == Value) {
                // if current value is a number, add it to the buffer
                numBuffer.push_back(token);
                continue;
            } else {
                result.push_back(Token::combineNumericTokens(numBuffer));
                numBuffer.clear();
            }
        }

        if (token.type == Value) {
            numBuffer.push_back(token);
            continue;
        }

        result.push_back(token);
    }


    if (!numBuffer.empty()) {
        result.push_back(Token::combineNumericTokens(numBuffer));
    }

    return result;
}

int calculate(const string &str) {
    auto tokens = tokenify(str);

    for (Token t: tokens) {
        cout << t.type << " | " << t.value.value_or(-1) << endl;
    }

    return 0;
}


int main() {

    while (true) {
        string str;
        cout << "> ";

        getline(cin, str);

        int result = calculate(str);

        cout << "> " << result << endl;


//        cout << "> " << Token(str[0]).type << endl;
//        cout << "> " << Token(str[0]).value.value_or(-1) << endl;
//        cout << tokenify(str).size() << endl;

        cout << endl;
    }


    return 0;
}
