#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <stack>
#include <iomanip>

bool isOperand(char c){
    return std::isalnum(c);
}
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isRightAssociative (char op){
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
//USING POSTFIX STACK

std::string convertToPostfix(const std::string& infix) {
    std::stack<char> opStack;
    std::string result = "";

    std::cout << "\n--- Infix to Postfix Steps ---\n";
    std::cout << std::left << std::setw(12) << "ICP" 
              << std::setw(20) << "ISP" 
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

//USING PREFIX STACK

std::string convertToPrefix(std::string infix) {
    std::stack<char> opStack;
    std::string reversedResult = "";


    std::reverse(infix.begin(), infix.end());

    std::cout << "\n--- Infix to Prefix Steps (Reversed Processing) ---\n";
    std::cout << std::left << std::setw(12) << "ICP" 
              << std::setw(20) << "Operator ISP" 
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

//Standard Array Postfix

std::string postfix (const std::string& infix){
    std::string postfix = ""; 
    char top = -1;
    char operatorStack[100];
    for (char token : infix){
        if (token == ' ') continue;
        
        if (isOperand(token)){
            postfix += token;
        }
        else if (token == '('){
            top++;
            operatorStack[top] = token;
        }
        else if (token == ')'){
            while (top > -1 && operatorStack[top] != '('){
                postfix += operatorStack[top];
                top--;
            }
            if (top > -1) {
                top--;
            }
        }
        else if (isOperator(token)){
            while (top > -1 && operatorStack[top] != '(' &&
            ((!isRightAssociative(token) && getPrecedence(operatorStack[top]) >= getPrecedence(token)) ||
            (isRightAssociative(token) && getPrecedence(operatorStack[top]) > getPrecedence(token)))){
                postfix += operatorStack[top];
                top--;
            }
            top++;
            operatorStack[top] = token;
        }
    }
    while (top > -1){
        postfix += operatorStack[top];
        top --;
    }
    return postfix;
}

//Standard Array Prefix

std::string prefix (const std::string& infix){
    std::string reversedResult = ""; 
    int top = -1;
    char operatorStack[100];
    std::string reversedInfix = infix;
    std::reverse(reversedInfix.begin(), reversedInfix.end());
    for (char token : reversedInfix){
        if (token == ' ') continue;
        
        if (isOperand(token)){
            reversedResult += token;
        }
        else if (token == ')'){
            top++;
            operatorStack[top] = token;
        }
        else if (token == '('){
            while (top > -1 && operatorStack[top] != ')'){
                reversedResult += operatorStack[top];
                top--;
            }
            if (top > -1) {
                top--;
            }
        }
        else if (isOperator(token)){
            while (top > -1 && operatorStack[top] != ')' &&
            ((!isRightAssociative(token) && getPrecedence(operatorStack[top]) > getPrecedence(token)) ||
            (isRightAssociative(token) && getPrecedence(operatorStack[top]) >= getPrecedence(token)))){
                reversedResult += operatorStack[top];
                top--;
            }
            top++;
            operatorStack[top] = token;
        }
    }
    while (top > -1){
        reversedResult += operatorStack[top];
        top --;
    }
    std::string prefix = reversedResult;
    std::reverse(prefix.begin(), prefix.end());
    return prefix;
}


int main(){

    int n = 0; 
    std::string expression = "(a+b)*D+E/( F + ( G + A * D ) ) + c";
    int total = 0;
    char ans = 'Y';
    
    std::cout << "Infix Expression = ( a + b ) * D + E / ( F + ( G + A * D ) ) + c";
    std::getline(std::cin >> std::ws, expression);

    while (ans == 'y' || ans == 'Y'){
    std::cout <<"Options:\n"
              <<"[1] Prefix Notation\n"
              <<"[2] Postfix Notation\n"
              <<"[3] Using Stack \n";
    std::cout << "Enter your choice: ";
    std::cin >> n;
        if (n == 1){
        std::cout << "\n" << std::string(50, '=') << "\n";
        std::cout << "FINAL RESULTS:\n";
        std::cout << "Infix:   " << expression << "\n";
        std::cout << "Prefix:  " << prefix(expression) << "\n";
        }

        else if (n == 2){  
        std::cout << "\n" << std::string(50, '=') << "\n";
        std::cout << "FINAL RESULTS:\n";
        std::cout << "Infix:   " << expression << "\n";
        std::cout << "Postfix:  " << postfix(expression)<< "\n";
        }

        else if (n == 3){
        std::cout << "\n" << std::string(50, '=') << "\n";
        std::cout << "FINAL RESULTS USING STACK\n";
        std::cout << "Infix:   " << expression << "\n";
        std::cout << "Postfix:  " << convertToPostfix(expression)<< "\n\n";
        std::cout << "Prefix:  " << convertToPrefix(expression) << "\n";
        }
        std::cout << "Do you want to convert again? (Y/N)";
        std::cin >> ans;
    }
    return 0;
}