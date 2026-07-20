#include <iostream>
#include <cctype>
#include <string>
#include <stack>
#include <algorithm>

bool isOperand(char c) {
    return std::isalnum(static_cast<unsigned char>(c));
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return -1;
}

// Validates infix expression and fills errorMsg if invalid
bool validateInfix(const std::string& exp, std::string& errorMsg) {
    int balance = 0;
    bool expectOperand = true; // Expecting an operand or '('

    if (exp.empty()) {
        errorMsg = "Error: Unexpected end of expression / missing operand";
        return false;
    }

    for (size_t i = 0; i < exp.length(); ++i) {
        char c = exp[i];

        if (c == '(') {
            // Check for empty parentheses: ()
            if (i + 1 < exp.length() && exp[i + 1] == ')') {
                errorMsg = "Error: Empty parenthetical expression";
                return false;
            }
            if (!expectOperand) {
                errorMsg = "Error: Missing operator before open parenthesis";
                return false;
            }
            balance++;
        } 
        else if (c == ')') {
            balance--;
            if (balance < 0) {
                errorMsg = "Error: Unmatched close parenthesis / stack underflow";
                return false;
            }
            if (expectOperand) {
                errorMsg = "Error: Unexpected operator or empty expression inside parentheses";
                return false;
            }
            expectOperand = false; 
        } 
        else if (isOperand(c)) {
            if (!expectOperand) {
                errorMsg = "Error: Missing operator between operands";
                return false;
            }
            expectOperand = false;
        } 
        else if (isOperator(c)) {
            if (expectOperand) {
                errorMsg = "Error: Consecutive binary operators";
                return false;
            }
            expectOperand = true;
        } 
        else {
            errorMsg = std::string("Error: Invalid character '") + c + "'";
            return false;
        }
    }

    if (balance > 0) {
        errorMsg = "Error: Unmatched open parenthesis";
        return false;
    }

    if (expectOperand) {
        errorMsg = "Error: Unexpected end of expression / missing operand";
        return false;
    }

    return true;
}

std::string postfix(const std::string& exp) {
    std::stack<char> operatorStack;
    std::string postfixStr = "";

    for (char c : exp) {
        if (isOperand(c)) {
            postfixStr.push_back(c);
        }
        else if (c == '(') {
            operatorStack.push(c);
        }
        else if (c == ')') {
            while (!operatorStack.empty()) {
                if (operatorStack.top() == '(') {
                    operatorStack.pop();
                    break;
                }
                else {
                    postfixStr.push_back(operatorStack.top());
                    operatorStack.pop();
                }
            }
        }
        else if (isOperator(c)) {
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfixStr.push_back(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        postfixStr.push_back(operatorStack.top());
        operatorStack.pop();
    }

    return postfixStr;
}

std::string prefix(std::string exp) {
    std::stack<char> operatorStack;
    std::string prefixStr = "";

    std::reverse(exp.begin(), exp.end());

    for (char c : exp) {
        if (isOperand(c)) {
            prefixStr.push_back(c);
        }
        else if (c == ')') {
            operatorStack.push(c);
        }
        else if (c == '(') {
            while (!operatorStack.empty()) {
                if (operatorStack.top() == ')') {
                    operatorStack.pop();
                    break;
                }
                else {
                    prefixStr.push_back(operatorStack.top());
                    operatorStack.pop();
                }
            }
        }
        else if (isOperator(c)) {
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                prefixStr.push_back(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        prefixStr.push_back(operatorStack.top());
        operatorStack.pop();
    }

    std::reverse(prefixStr.begin(), prefixStr.end());
    return prefixStr;
}

int main() {
    std::string inputExp;

    std::cout << "Input Infix Expression: ";
    std::getline(std::cin, inputExp);

    // It removes the spaces
    std::string exp = "";
    for (char c : inputExp) {
        if (c != ' ' && c != '\t') {
            exp += c;
        }
    }

    std::string errorMsg;
    if (!validateInfix(exp, errorMsg)) {
        std::cout << errorMsg << "\n";
    } 
    else {
        std::cout << "Postfix Notation: " << postfix(exp) << "\n";
        std::cout << "Prefix Notation:  " << prefix(exp) << "\n";
    }

    return 0;
}