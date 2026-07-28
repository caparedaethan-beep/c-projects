#include <iostream>
#include <cctype>
#include <string>
#include <stack>
#include <algorithm>
#include <iomanip>

// Helper functions
bool isOperand(char c) {
    return std::isalnum(c);
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isRightAssociative(char op) {
    return op == '^';
}

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return -1;
}


std::string getStackString(std::stack<char> s) {
    std::string str = "";
    while (!s.empty()) {
        str += s.top();
        s.pop();
    }
    std::reverse(str.begin(), str.end());
    return str;
}


std::string convertToPostfix(const std::string& infix) {
    std::stack<char> opStack;
    std::string result = "";

    std::cout << "\n--- Infix to Postfix Steps ---\n";
    std::cout << std::left << std::setw(12) << "Symbol" 
              << std::setw(20) << "Operator Stack" 
              << "Postfix Output\n";
    std::cout << std::string(50, '-') << "\n";

    for (char token : infix) {
        if (token == ' ') continue;

        if (isOperand(token)) {
            result.push_back(token);
        } 
        else if (token == '(') {
            opStack.push(token);
        } 
        else if (token == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                result.push_back(opStack.top());
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop(); 
        } 
        else if (isOperator(token)) {
            while (!opStack.empty() && opStack.top() != '(' &&
                  ((!isRightAssociative(token) && getPrecedence(opStack.top()) >= getPrecedence(token)) ||
                   (isRightAssociative(token) && getPrecedence(opStack.top()) > getPrecedence(token)))) {
                result.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }

    
        std::cout << std::left << std::setw(12) << token 
                  << std::setw(20) << getStackString(opStack) 
                  << result << "\n";
    }


    while (!opStack.empty()) {
        result.push_back(opStack.top());
        opStack.pop();
        
        std::cout << std::left << std::setw(12) << "End" 
                  << std::setw(20) << getStackString(opStack) 
                  << result << "\n";
    }

    return result;
}


std::string convertToPrefix(std::string infix) {
    std::stack<char> opStack;
    std::string reversedResult = "";


    std::reverse(infix.begin(), infix.end());

    std::cout << "\n--- Infix to Prefix Steps (Reversed Processing) ---\n";
    std::cout << std::left << std::setw(12) << "Symbol" 
              << std::setw(2    0) << "Operator Stack" 
              << "Reversed Output\n";
    std::cout << std::string(50, '-') << "\n";

    for (char token : infix) {
        if (token == ' ') continue;

        if (isOperand(token)) {
            reversedResult.push_back(token);
        } 
        else if (token == ')') { 
            opStack.push(token);
        } 
        else if (token == '(') {
            while (!opStack.empty() && opStack.top() != ')') {
                reversedResult.push_back(opStack.top());
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop();
        } 
        else if (isOperator(token)) {
            while (!opStack.empty() && opStack.top() != ')' &&
                  ((!isRightAssociative(token) && getPrecedence(opStack.top()) > getPrecedence(token)) ||
                   (isRightAssociative(token) && getPrecedence(opStack.top()) >= getPrecedence(token)))) {
                reversedResult.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }

        std::cout << std::left << std::setw(12) << token 
                  << std::setw(20) << getStackString(opStack) 
                  << reversedResult << "\n";
    }

    while (!opStack.empty()) {
        reversedResult.push_back(opStack.top());
        opStack.pop();

        std::cout << std::left << std::setw(12) << "End" 
                  << std::setw(20) << getStackString(opStack) 
                  << reversedResult << "\n";
    }

    std::string prefixResult = reversedResult;
    std::reverse(prefixResult.begin(), prefixResult.end());
    
    return prefixResult;
}

int main() {
    std::string expression;
    int n;

    std::cout << "Enter Infix Expression: ";
    std::getline(std::cin, expression);

    std::cout << "What conversion do you want? [1] Prefix Notation, [2] Postfix Notation, Using Stack Tracing[3]";
    std::cin >> n;

    if (n == 1){
    std::string prefix = convertToPrefix(expression);
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "FINAL RESULTS:\n";
    std::cout << "Infix:   " << expression << "\n";
    std::cout << "Prefix:  " << prefix << "\n";
    }
    else if (n == 2){
    std::string postfix = convertToPostfix(expression);
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "FINAL RESULTS:\n";
    std::cout << "Infix:   " << expression << "\n";
    std::cout << "Postfix: " << postfix << "\n";
    }
    else if (n == 3){
    std::string postfix = convertToPostfix(expression);
    std::string prefix = convertToPrefix(expression);
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "FINAL RESULTS:\n";
    std::cout << "Infix:   " << expression << "\n";
    std::cout << "Prefix:  " << prefix << "\n";
    std::cout << "Postfix:  " << postfix << "\n";
    }
    

    
    return 0;
}