#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isRightAssociative (char op){
    return op == '^';
}

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}


//Standard Array Postfix

std::string postfix (const std::string& infix){
    std::string postfix = ""; 
    char top = -1;
    char operatorStack[100];
    for (char token : infix){
        if (token == ' ') continue;
        
        if (isalnum(token)){
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
    for (char token : infix){
        if (token == ' ') continue;
        
        if (isalnum(token)){
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
            while (top > -1 && operatorStack[top] != '(' &&
            ((!isRightAssociative(token) && getPrecedence(operatorStack[top]) >= getPrecedence(token)) ||
            (isRightAssociative(token) && getPrecedence(operatorStack[top]) > getPrecedence(token)))){
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

    int n; 
    std::string expression = "";
    int total = 0;
    std::cout << "Input Infix Notation: ";
    std::getline(std::cin, expression);
    std::cout <<"What conversion do you want? [1] Prefix Notation, [2] Postfix Notation";
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


    
    return 0;
}