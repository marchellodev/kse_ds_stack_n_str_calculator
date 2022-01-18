#include <optional>
#include <stdexcept>
#include <vector>

using namespace std;

enum TokenType {
    // 0
    OperatorMinus,

    // 1
    OperatorPlus,

    // 2
    OperatorMultiply,

    // 3
    OperatorDivide,

    // 4
    ParenthesisOpen,

    // 5
    ParenthesisClose,

    // 6
    Value,
    None,
};




class Token {
public:
    TokenType type;
    optional<int> value;

    Token() = default;

    Token(TokenType type, optional<int> value) : type(type), value(value) {}

    Token(const char c) {
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

        int val = c - '0';
        if (val >= 0 && val <= 9) {
            type = Value;
            value = val;
        }

        if (type == None) {
            throw invalid_argument("unknown value");
        }
    }


    static Token combineNumericTokens(const vector<Token> &tokens) {
        int power = 1;
        int result = 0;
        for (int i = tokens.size() - 1; i >= 0; i--) {
//            cout << tokens[i].value.value_or(-1) << endl;
            result += tokens[i].value.value() * power;
            power *= 10;
        }

        return {Value, result};
    }

};
