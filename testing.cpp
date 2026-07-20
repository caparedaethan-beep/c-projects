#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <cctype>

int prec(char c) {
    switch (c) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return -1;
    }
}

std::string toPostfix(const std::string& s) {
    std::string res;
    std::stack<char> st;

    for (char c : s) {
        if (std::isalnum(c)) {
            res += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') { res += st.top(); st.pop(); }
            if (!st.empty()) st.pop(); // Pop '('
        } else if (prec(c) > 0) {
            // Check operator precedence (^ is right-associative)
            while (!st.empty() && (prec(st.top()) > prec(c) || (prec(st.top()) == prec(c) && c != '^'))) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) { res += st.top(); st.pop(); }
    return res;
}

std::string toPrefix(std::string s) {
    // Reverse, swap parentheses, calculate postfix, and reverse back
    std::reverse(s.begin(), s.end());
    for (char& c : s) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    std::string res = toPostfix(s);
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    std::string exp;
    std::cout << "Input Infix Expression: ";
    std::getline(std::cin, exp);

    // Clean spaces inline
    exp.erase(std::remove_if(exp.begin(), exp.end(), ::isspace), exp.end());

    std::cout << "Postfix Notation: " << toPostfix(exp) << "\n";
    std::cout << "Prefix Notation:  " << toPrefix(exp) << "\n";

    return 0;
}