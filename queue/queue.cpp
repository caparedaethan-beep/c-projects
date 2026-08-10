#include <iostream>
#include <queue>

int main(){

    char opt = 'a';
    int studentID[100];
    int i = 0;
    int len=1;
    int temp;
    std::queue<int> line;

    while (opt != 'e' && opt != 'E'){
        std::cout << "\n=== STUDENT LINE-UP ===\n" << "a) Add student to line\n" << "b) Call next student\n" << "c) View first in line\n" << "d) Show full line\n" << "e) Exit\n" << "Choose option: ";
        std::cin >> opt;
        std::cin.ignore();
        if (opt == 'a' || opt == 'A'){
            while (len != 6){
                std::cout << "\nInput Student ID: ";
                std::cin >> studentID[i];
                temp = studentID[i];
                while (temp /=10){
                    len++;
                }
                if (len != 6) {
                    std::cout << "\nInvalid Student ID, Try Again.";
                    len = 1;
                }
            }
            len = 1;
            line.push(studentID[i]);
            i++;
        }   
        
        else if (opt == 'b' || opt == 'B'){
            if (!line.empty()){
                line.pop();
                i--;
                std::cout << "\nThe Student has been called\n";
            }
            else std::cout << "\nThe line is empty, you can't call again\n";
            
        }
        else if (opt == 'c' || opt == 'C'){
            if (!line.empty()){
                std::cout << "\nThe First in Line: "<< line.front() << "\n";
            }
            else std::cout << "\nThere is no one in the Line\n";
        }
        else if (opt == 'd' || opt == 'D'){
            if (!line.empty()){
                std::cout << "\nNumber of Students in line: " << line.size() << "\nStudent ID List in Line: \n";
                for (int i = 0; i < line.size() ; i++){
                    std::cout << studentID[i] << "\n";
                }
            }
            else std::cout << "\nThe line is empty\n";
        }
    }
    
    return 0;

}