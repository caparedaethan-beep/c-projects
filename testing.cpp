#include <iostream>
#include <stack>


int main(){
    std::stack<char> operatorStack;
    std::string postfix = "";
    std::string infix = "A+B+C"
    
    for (int i = 0; i < infix.length(); i++) {
    char currentOp = infix[i]; // <--- HERE: currentOp gets the character at position i

    if (isOperator(currentOp)) {
        // Now you use currentOp in your precedence loop!
        while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(currentOp)) {
            postfix.push_back(operatorStack.top());
            operatorStack.pop();
        }
        
        operatorStack.push(currentOp); // Push currentOp onto the stack
    }
}


}