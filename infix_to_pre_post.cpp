#include <iostream>
using namespace std;
 
int main(){

    string exp =" ";
    int n;
    int total;
    char arr[total+1];

    
    cout << "Input Infix Expression: ";
    cin >> exp;
    
    arr[total] = '\0';
    total = exp.length();

    for(int i = 0; i < total; i++)
        arr[i] = exp[i];
    
    cout << "Press [1] Postfix, Press [2] Prefix: ";
    cin >> n;
    
    return 0;


}