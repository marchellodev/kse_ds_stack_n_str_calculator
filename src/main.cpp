#include <iostream>
#include <vector>
#include <cmath>

#include "lib/Stack.h"
#include "Token.cpp"

using namespace std;

// + - = 1
// * / = 2
// todo move into the enum
int tokenPriority(const Token t) {

    if(t.type == ParenthesisOpen || t.type == ParenthesisClose){
        return 0;
    }

    if (t.type == OperatorPlus || t.type == OperatorMinus) {
        return 1;
    }

    if (t.type == OperatorMultiply || t.type == OperatorDivide) {
        return 2;
    }

    if(t.type == OperatorPower){
        return 3;
    }

    throw invalid_argument("not applicable");
}

// 9, 3, - => 9-3
int performOperation(int val1, int val2, TokenType operation){
    if(operation == OperatorPlus){
        return val1+val2;
    }

    if(operation == OperatorMinus){
        return val1-val2;
    }

    if(operation == OperatorMultiply){
        return val1*val2;
    }

    if(operation == OperatorDivide){
        return val1 / val2;
    }

    if(operation == OperatorPower){
        return pow(val1, val2);;
    }

    throw invalid_argument("not applicable");
}


vector<Token> tokenify(const string &str) {
    vector<Token> result;

    // buffer for temporary data
    vector<Token> numBuffer;

    for (char c: str) {
        if (c == ' ') {
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

vector<Token> shuntingYardOrdering(const vector<Token> tokens) {
    vector<Token> queue;
    Stack<Token> stack;

    for (Token t: tokens) {
        if (t.type == Value) {
            queue.push_back(t);
            continue;
        }

        if(t.type == ParenthesisOpen){
            stack.push(t);
            continue;
        }

        // if the stack is empty
        if(!stack.canPop()){
            stack.push(t);
            continue;
        }

        if (t.type == ParenthesisClose){
            while(stack.canPop()){
                auto tt = stack.pop();

                if(tt.type == ParenthesisOpen){
                    break;
                }

                queue.push_back(tt);
            }
            continue;
        }

        // type is an operator
        auto prev = stack.pop();

        // if * > +
        if (tokenPriority(t) > tokenPriority(prev)) {
            // add to the stack and move on
            stack.push(prev);
            stack.push(t);
            continue;
        } else {
            // move the stack to the queue
            // add operator to the stack
            queue.push_back(prev);
            while (stack.canPop()) {
                auto pop = stack.pop();
                if(pop.type == ParenthesisOpen || tokenPriority(t) > tokenPriority(pop)){
                    stack.push(pop);
                    break;
                    //or continue
                }
                queue.push_back(stack.pop());
            }

            stack.push(t);
        }

    }

    while (stack.canPop()) {
        queue.push_back(stack.pop());
    }

    return queue;
}

int calculate(const string &str) {
    auto tokens = tokenify(str);
    tokens = shuntingYardOrdering(tokens);


    Stack<int> stack;
    // todo tokens to postfix format & actual calculation algorithm
    for (Token t: tokens) {
//        cout << t.type << " | " << t.value.value_or(-1) << endl;

        if(t.type == Value){
            stack.push(t.value.value());
            continue;
        }

        int val1 = stack.pop();
        int val2 = stack.pop();

        stack.push(performOperation(val2, val1, t.type));

    }

    return stack.pop();
}


// todo implement parentheses & power
int main() {
//    cout << 6/2 << endl;

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
