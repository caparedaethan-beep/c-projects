#include <iostream>

int main(){
    int n[15];

    for (int i = 0; i < 15; i++){
        std::cin >> n[i];
    }

    for (int i = 0; i < 15; i++){
        std::cout << n[i];
    }
}