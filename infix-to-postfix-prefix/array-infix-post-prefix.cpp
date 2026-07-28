#include <iostream>
#include <string>
#include <cctype>

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

std::string postfix (char expression[], int total){
    std::string postfix = ""; 
    char top = -1;
    char operatorStack[100];
    for (int i = 0 ; i < total; i++){
        if (isalnum(expression[i])){
            postfix += expression[i];
        }
        else if (expression[i] == '('){
            top++;
            operatorStack[top] = expression[i];
        }
        else if (expression[i] == ')'){
            while (top > -1 && operatorStack[top] != '('){
                postfix += operatorStack[top];
                top--;
            }
            if (top > -1) {
                top--;
            }
        }
        else if (isOperator(expression[i])){
            while (top > -1 && operatorStack[top] != '(' &&
            ((!isRightAssociative(expression[i]) && getPrecedence(operatorStack[top]) >= getPrecedence(expression[i])) ||
            (isRightAssociative(expression[i]) && getPrecedence(operatorStack[top]) > getPrecedence(expression[i])))){
                postfix += operatorStack[top];
                top--;
            }
            top++;
            operatorStack[top] = expression[i];
        }
    }
    while (top > -1){
        postfix += operatorStack[top];
        top --;
    }
    return postfix;
}

int main(){

    int n; 
    std::string convertExpression = "";
    int total = 0;
    std::cout << "Input Infix Notation: ";
    std::getline(std::cin, convertExpression);
    std::cout <<"What conversion do you want? [1] Prefix Notation, [2] Postfix Notation";
    std::cin >> n;

    char expression[total+1] = {'\0'};

    for (int i = 0; i <convertExpression.length(); i++){
        if (expression[i] != ' '){
            expression[total] = convertExpression[i];
            total++;
        }
    }

    std::cout << postfix(expression, total);

    // if (n == 1){
    // // std:: string prefix =
    // std::cout << "\n" << std::string(50, '=') << "\n";
    // std::cout << "FINAL RESULTS:\n";
    // std::cout << "Infix:   " << expression << "\n";
    // std::cout << "Prefix:  " << prefix << "\n";
    // }

    // else if (n == 2){

    // }
    // // std::string postfix = 
    // std::cout << "\n" << std::string(50, '=') << "\n";
    // std::cout << "FINAL RESULTS:\n";
    // std::cout << "Infix:   " << expression << "\n";
    // std::cout << "Postfix:  " << postfix << "\n";
    // }
    




    
    return 0;
}