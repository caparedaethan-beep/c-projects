#include <iostream>
#include <cctype>
#include <string>
#include <stack>


bool isOperand (char c){
    if (isalnum(c)){
        return true;
    }
    return false;
}

bool isOperator (char c){
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
        return true;
    }
    return false;
}


int getPrecedence(char op){
    if (op == '+' || op == '-'){
        return 1;
    }
    if(op == '*' || op == '/'){
        return 2;
    }
    if(op == '^'){
        return 3;
    }
    return -1;
}

// bool isRightAssociative(char op){
//     if (op == '^') {
//         return true;
//     }
//     return false;
// }

std::string postfix(char arr[], int total){
    std::stack<char> operatorStack;
    std::string postfix = "";
    for (int i = 0; i < total; i++){
        if (isOperand(arr[i])){
            postfix.push_back(arr[i]);
        }
        else if (arr[i] == '('){
            operatorStack.push(arr[i]);
        }
        else if (arr[i] == ')'){
            while (!operatorStack.empty()){
                if (operatorStack.top() == '(')
                    operatorStack.pop();
                else{
                postfix.push_back(operatorStack.top());
                operatorStack.pop();
                }
            }
        }
        else if (isOperator(arr[i])){
            while(!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(arr[i])){
                postfix.push_back(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.push(arr[i]);
        }
        
    }
    while (!operatorStack.empty()){
        postfix.push_back(operatorStack.top());
        operatorStack.pop();
    }

    return postfix;
}


    
    

int main(){

    std::string exp =" ";
    int n;
    int total = 0;
    
    
    std::cout << "Input Infix Expression: ";
    std::getline(std::cin, exp);

    char arr[total+1] = {'\0'};

    for(int i = 0; i < exp.length(); i++){
        if (exp[i] != ' '){
        arr[total] = exp[i];  
        total++;  
        }
    }

    std::cout<< "Postfix Notation: " <<postfix(arr, total);


    return 0;


}