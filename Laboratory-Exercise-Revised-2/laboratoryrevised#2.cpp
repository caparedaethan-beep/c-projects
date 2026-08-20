#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <cctype>

// prototypes so main knows these exist below
bool isOperator(char);
bool isOperand(char);
std::string stackState(const std::string [], int);
std::string getStackString(std::stack<char>);
bool isRightAssociative (char);
int getPrecedence (char);
std::string convertPostfixToInfixArray (const std::string &);
std::string convertPrefixToInfixArray (const std::string &);
std::string convertToPrefixStack (const std::string &);
std::string convertToPostfixStack(const std::string &);


int main(){
    int opt;
    char ans = 'y';
    // test expressions to run through the conversions
    std::string prefix = "++*+abD/E+F+G*ADc", postfix = "ab+D*EFGAD*++/+c+", infix = "(a+b)*D+E/(F+(G+A*D))+c";
    std::string prefixToInfix, postfixToInfix;
    std::string prefixStack, postfixStack;
    
    while (ans == 'Y' || ans == 'y'){
    // pick how you want to process the expressions
    std::cout << "Options:\n (1) Prefix (Array)\n (2) Postfix (Array)\n (3) Using Stack\n";
    std::cout << "Pick your Option: ";
    std::cin >> opt;
    
    std::cin.ignore(); // flush leftover '\n' so it doesn't break later inputs

    
        // option 1: turn prefix into infix using our array stack
        if (opt == 1){
        prefixToInfix = convertPrefixToInfixArray(prefix);
        std::cout << "\nPrefix Expression: " << prefix << "\n";
        std::cout << "Infix Expression: " << prefixToInfix << "\n";
        }
        // option 2: turn postfix into infix using our array stack
        else if (opt == 2){
        postfixToInfix = convertPostfixToInfixArray(postfix);
        std::cout << "\nPostfix Expression: " << postfix << "\n";
        std::cout << "Infix Expression: " << postfixToInfix << "\n";
        }
        // option 3: convert standard infix into both postfix and prefix using stack
        else if (opt == 3){
            std::string result = convertToPostfixStack(infix);
            std::string result1 = convertToPrefixStack(infix);
            std::cout << "\n" << std::string(50, '=') << "\n";
            std::cout << "FINAL RESULTS USING STACK\n";
            std::cout << "Infix:   " << infix << "\n";
            std::cout << "Postfix:  " << result<< "\n\n";
            std::cout << "Prefix:  " << result1 << "\n";
        }
        std::cout << "Do you want to pick a different option? (Y/N)";
        std::cin >> ans;
    }
  
    return 0;
}

// quick check if a character is a math operator
bool isOperator (char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// check if character is a letter or number
bool isOperand (char c){
    return std::isalnum(c);
}

// exponents are right-associative (like 2^3^2 is 2^(3^2))
bool isRightAssociative (char op){
    return op == '^';
}

// precedence rules: ^ is highest, then */, then +-
int getPrecedence (char op){
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return -1;
}

// converts standard stack contents into a printable string for debugging/tracing
std::string getStackString(std::stack<char> s){
    std::string str = "";
    // grab items top-first
    while (!s.empty()){
        str += s.top();
        s.pop();
    }
    // flip it back so bottom of the stack is on the left
    std::reverse(str.begin(), str .end());
    return str;
}

// formats our custom array stack so we can print it out in the table
std::string stackState(const std::string operatorStack[], int top){
    if (top < 0) return "Empty";
    std::string result = " ";
    for (int i = 0; i <= top; i++){
        result += operatorStack[i];
        if (i < top) result += ", ";
    }
    result += " ";
    return result;
}

// postfix -> infix using a basic array as a stack
std::string convertPostfixToInfixArray (const std::string &expression){
    std::string postfix = "";
    int top = -1; // -1 means stack is empty
    int stepCount = 0;
    std::string actDesc;
    std::string op1, op2;
    std::string operatorStack[100]; // manual stack array
    
    // header for the output table
    std::cout << std::left << std::setw(10) << "Step" << std::setw(12) << "Token" << std::setw(30) << "Action" << std::setw(30) << "Stack Content" << "\n";
    std::cout << std::string (70, '-') << "\n";
    
    // read through the expression character by character
    for (char token : expression){
        if (token == ' ') continue; // ignore spaces
        
        // if it's a variable or number, just throw it on the stack
        if (isOperand(token)){
            top++;
            operatorStack[top] = std::string(1, token);
            stepCount++;
            actDesc = "Push Operand";
        }
        // if it's an operator, grab the last two items, put operator between them, and push back
        else if (isOperator(token)){
            if (top < 1){return "Error: Invalid postfix expression (not enough operands).";}
            op2 = operatorStack[top]; // right side
            top--;
            op1 = operatorStack[top]; // left side
            top--;
            top++;
            operatorStack[top] = '(' + op1 + token + op2 + ')'; // wrap in parenthesis to preserve order
            stepCount++;
            actDesc = "Pop and Combine ";
        }
        // print progress line
        std::cout << std::left << std::setw(10) << stepCount << std::setw(12) << token << std::setw(30) << actDesc<< std::setw(30) << stackState(operatorStack, top) << "\n";
    }
    // make sure we didn't end up with broken syntax
    if (top < 0) return "Error: Empty expression.";
    if (top > 0) return "The postfix expression is invalid because it has too many operands and not enough operators.";
    
    postfix = operatorStack[top];
    return postfix;
}

// prefix -> infix using an array stack
std::string convertPrefixToInfixArray (const std::string &expression){
    std::string prefix = "";
    int top = -1;
    int stepCount = 0;
    std::string actDesc;
    std::string op1, op2;
    std::string operatorStack[100];
    std::string revExpre = expression;
    
    // for prefix, we scan backwards (right to left)
    std::reverse(revExpre.begin(), revExpre.end());
    
    std::cout << std::left << std::setw(10) << "Step" << std::setw(12) << "Token" << std::setw(30) << "Action" << std::setw(30) << "Stack Content" << "\n";
    std::cout << std::string (70, '-') << "\n";
    
    for (char token : revExpre){
        if (token == ' ') continue;
        
        if (isOperand(token)){
            top++;
            operatorStack[top] = std::string(1, token);
            stepCount++;
            actDesc = "Push Operand";
        }
        // reading backwards swaps order when combining: op2 comes before op1
        else if (isOperator(token)){
            if (top < 1){return "Error: Invalid postfix expression (not enough operands).";}
            op2 = operatorStack[top];
            top--;
            op1 = operatorStack[top];
            top--;
            top++;
            operatorStack[top] = '(' + op2 + token + op1 + ')';
            stepCount++;
            actDesc = "Pop and Combine";
        }
        std::cout << std::left << std::setw(10) << stepCount << std::setw(12) << token << std::setw(30) << actDesc<< std::setw(30) << stackState(operatorStack, top) << "\n";
    }
    if (top < 0) return "Error: Empty expression.";
    if (top > 0) return "The postfix expression is invalid because it has too many operands and not enough operators.";
    prefix = operatorStack[top];
    return prefix;
}

// standard infix -> postfix conversion (shunting-yard algorithm)
std::string convertToPostfixStack(const std::string& infix) {
    std::stack<char> opStack; // stores operators temporarily
    std::string result = "";   // holds output

    std::cout << "\n--- Infix to Postfix Steps ---\n";
    std::cout << std::left << std::setw(12) << "ICP" 
              << std::setw(20) << "ISP" 
              << "Postfix Output\n";
    std::cout << std::string(50, '-') << "\n";

    for (char token : infix) {
        if (token == ' ') continue;

        // operands go straight to output string
        if (isOperand(token)) {
            result.push_back(token);
        } 
        // open parenthesis goes right to stack
        else if (token == '(') {
            opStack.push(token);
        } 
        // closing parenthesis: pop everything back to output until we hit '('
        else if (token == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                result.push_back(opStack.top());
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop(); // toss out the '('
        } 
        // handle operator precedence and associativity
        else if (isOperator(token)) {
            while (!opStack.empty() && opStack.top() != '(' &&
                  ((!isRightAssociative(token) && getPrecedence(opStack.top()) >= getPrecedence(token)) ||
                   (isRightAssociative(token) && getPrecedence(opStack.top()) > getPrecedence(token)))) {
                result.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }

        // output current row to table
        std::cout << std::left << std::setw(12) << token 
                  << std::setw(20) << ("-#" + getStackString(opStack)) 
                  << result << "\n";
    }

    // flush any leftover operators from the stack
    while (!opStack.empty()) {
        result.push_back(opStack.top());
        opStack.pop();
        
        std::cout << std::left << std::setw(12) << "-#" 
                  << std::setw(20) << ("-#" + getStackString(opStack)) 
                  << result << "\n";
    }

    return result;
}

// infix -> prefix conversion (reverse string trick + shunting-yard variant)
std::string convertToPrefixStack(const std::string & infix) {
    std::stack<char> opStack;
    std::string reversedResult = "";
    std::string tempInfix = infix;
    
    // step 1: reverse the expression first
    std::reverse(tempInfix.begin(), tempInfix.end());

    std::cout << "\n--- Infix to Prefix Steps (Reversed Processing) ---\n";
    std::cout << std::left << std::setw(12) << "ICP" 
              << std::setw(20) << "ISP" 
              << "Reversed Output\n";
    std::cout << std::string(50, '-') << "\n";

    for (char token : tempInfix) {
        if (token == ' ') continue;

        if (isOperand(token)) {
            reversedResult.push_back(token);
        } 
        // because string was reversed, parens flip roles ('(' acts as ')')
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
                  << std::setw(20) << ("-#" + getStackString(opStack)) 
                  << reversedResult << "\n";
    }

    // flush remaining stack
    while (!opStack.empty()) {
        reversedResult.push_back(opStack.top());
        opStack.pop();

        std::cout << std::left << std::setw(12) << "-#" 
                  << std::setw(20) << ("-#" + getStackString(opStack)) 
                  << reversedResult << "\n";
    }

    // step 2: reverse final output back to get correct prefix format
    std::string prefixResult = reversedResult;
    std::reverse(prefixResult.begin(), prefixResult.end());
    return prefixResult;
}