#include <iostream>
using namespace std;


string postfix(char arr[], int total){
    string postfix="";
    for (int i = 0; i < total; i++){
        if (arr[i] == 'A' || arr[i]== 'a'){
        postfix += arr[i];
        }
    }
    
   return postfix;
}
 
int main(){

    string exp =" ";
    int n;
    int total = 0;
    
    cout << "Input Infix Expression: ";
    getline(cin, exp);

    char arr[total+1];

    for(int i = 0; i < exp.length(); i++){
        if (exp[i] != ' '){
        arr[total] = exp[i];  
        total++;  
        }
    }
  
    cout << "RESULTS" << "\n";
    cout << "POSTFIX NOTATION: "<< postfix(arr, total);
    
    return 0;


}