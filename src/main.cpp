#include <iostream>
#include <vector>
#include <cmath>

#include "lib/Stack.h"
#include "Token.cpp"
#include <readline/readline.h>
#include <readline/history.h>

using namespace std;

// + - = 1
// * / = 2
// todo move into the enum
int tokenPriority(const Token t) {

    if(t.type == ParenthesisOpen || t.type == ParenthesisClose){
        return 0;
    }

    if (t.type == OperatorPlus) {
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
//
//    if(operation == OperatorMinus){
//        return val1-val2;
//    }

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


bool numBufferContainsMinusesButNoNumbersYet(vector<Token> buffer){
    bool minuses = false;
    bool numbers = false;

    for(Token t : buffer){
        if(t.type == ModifierMinus){
            minuses = true;
        }
        if(t.type == Value){
            numbers = true;
        }
    }

    return minuses && !numbers;
}


bool numBufferContainsMinuses(vector<Token> buffer){

    for(Token t : buffer){
        if(t.type == ModifierMinus){
            return true;
        }
    }

    return false;
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
            // dangerous
            // if numBuffer contains minuses, but no numbers yet
            if (token.type == Value || (token.type == ModifierMinus && numBufferContainsMinusesButNoNumbersYet(numBuffer))) {
                // if current value is a number, add it to the buffer
                numBuffer.push_back(token);
                continue;
            } else {
                auto combined = Token::combineNumericTokens(numBuffer);

                if(numBufferContainsMinuses(numBuffer)){
                    // placing + before if negative value, so we can actually compute the value
                    result.push_back(Token('+'));
                }
                result.push_back(combined);
                numBuffer.clear();
            }
        }

        if (token.type == Value || token.type == ModifierMinus) {
            numBuffer.push_back(token);
            continue;
        }

        result.push_back(token);
    }


    if (!numBuffer.empty()) {
        if(numBufferContainsMinuses(numBuffer)){
            // placing + before if negative value, so we can actually compute the value
            result.push_back(Token('+'));
        }
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
//    tokens.insert(tokens.begin(), Token('0'));

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
//        cout << "> ";

//        str = readline("> ");
        str = readline("> ");

        int result = calculate(str);

        cout << "> " << result << endl;


//        cout << "> " << Token(str[0]).type << endl;
//        cout << "> " << Token(str[0]).value.value_or(-1) << endl;
//        cout << tokenify(str).size() << endl;

        cout << endl;
    }


    return 0;
}

// TODO > 132 - -123
