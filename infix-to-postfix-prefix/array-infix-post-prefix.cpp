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

std::string postfix (char expression[], int total){
    std::string postfix = ""; 
    char temporaryStack;
    char topStack = '\0';
    char operatorStack[10];
    for (int i = 0 ; i < total; i++){
        if (isalnum(expression[i])){
            postfix += expression[i];
        }
        else if (expression[i] == '('){
            temporaryStack = expression[i];
        }
        else if (expression[i] == ')' && temporaryStack == '('){
            temporaryStack = '\0';
            for (int y = 0; y < i+1 ; y++){
                postfix += operatorStack;
            }
        }
        else if (isOperator(expression[i])){
            while (temporaryStack != '(' &&
                  ((!isRightAssociative(expression[i]) && getPrecedence(topStack) >= getPrecedence(expression[i])) ||
                   (isRightAssociative(expression[i]) && getPrecedence(topStack) > getPrecedence(expression[i])))) {
                        if (topStack == '\0' || topStack < expression[i]){
                            topStack = expression[i];
                        }
                    postfix += topStack;
        }
        
    }

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