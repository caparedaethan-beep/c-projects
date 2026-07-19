#include <iostream>
using namespace std;
    

int main(){

    string exp;
    int n;

    cout << "Input Infix Expression: ";
    getline(cin, exp);

    cout << "Press [1] Postfix, Press [2] Prefix: ";
    cin >> n;
    
    return 0;
}