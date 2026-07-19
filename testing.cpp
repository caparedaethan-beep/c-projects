#include <iostream>
using namespace std;

int main(){
  char arr[100]; 
  string exp = "imong mama";
int j = 0; // Tracks the clean position in arr

for(int i = 0; i < exp.length(); i++){
    if (exp[i] != ' ') {
        arr[j] = exp[i]; // Inserts at the next empty slot, no gaps!
        j++;             // Move to the next slot
    }
}
arr[j] = '\0'; // CRUCIAL: Closes the string so no garbage prints after 'b'

for (int i = 0; i < exp.length(); i++){
    cout << arr[i];
}
}