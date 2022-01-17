#include <optional>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

enum TokenType {
    OperatorMinus,
    OperatorPlus,
    OperatorMultiply,
    OperatorDivide,
    ParenthesisOpen,
    ParenthesisClose,
    Value,
    None,
};


class Token {
public:
    TokenType type;
    optional<int> value;

    Token(TokenType type, optional<int> value) : type(type), value(value) {}

    Token(char c) {
        type = None;

        switch (c) {
            case '-':
                type = OperatorMinus;
                break;
            case '+':
                type = OperatorPlus;
                break;
            case '*':
                type = OperatorMultiply;
                break;
            case '/':
                type = OperatorDivide;
                break;
            case '(':
                type = ParenthesisOpen;
                break;
            case ')':
                type = ParenthesisClose;
                break;
        }

        int val =  c - '0';
        if(val >= 0 && val <= 9){
            type = Value;
            value = val;
        }

        if(type == None){
            throw std::invalid_argument("unknown value");
        }
    }

};

//Token* tokenify(string str){
//    for(char& c : str) {
//
//    }
//}

