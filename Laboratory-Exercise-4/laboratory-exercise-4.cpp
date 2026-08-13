#include <iostream>

int main(){

    int num1, num2, remainder, divisor, dividend;

    std::cout << "Input the Divisor: ";
    std::cin >> num1;
    std::cout << "\nInput the dividend: ";
    std::cin >> num2;

    divisor = num1;
    dividend = num2;

    while(num1 != 0){
        remainder = num2 % num1;
        num2 = num1;
        num1 = remainder;
    }

    std::cout << "\n\n*****RESULTS***** \n" << "Divisor: " << divisor << "\n" << "Dividend: " << dividend << "\n" << "GCD: " << num2;
    
    
    return 0;
}