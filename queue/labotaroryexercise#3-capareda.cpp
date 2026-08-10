#include <iostream>
 
#define MAX 5
 int queue[MAX];
 int rear = -1;
 int front = -1;

void enqueue(int n){
    if (rear == -1 && front == -1){
        front = 0, rear = 0;
        queue[rear] = n;
    }
    else if (((rear + 1) % MAX) == front){
        std::cout << "\nQueue is Full\n";
    }
    else {
        rear = (rear + 1) % MAX;
        queue[rear] = n;
    }
}

void dequeue (){
    if (front == -1 && rear == -1) return;
    else if (front == rear){
        front = -1;
        rear = -1;
    }

    else front = (front + 1) % MAX;
    
}

void display() {
    if (front == -1 && rear == -1) return;
    int i = front;
    while (true){
        std::cout << queue[i] << "\n";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }

}

bool isempty() {
    if (front == -1 && rear == -1) return true;
    
    return false;
}

void peek(){
    if (front == -1 && rear == -1) return;
    else std::cout << queue[front];
}

void back(){
    if (front == -1 && rear == -1) return;
    else std::cout << queue[rear];
}


int main(){
    char opt = 'a';
    int studentID;
    int len=1;
    int temp;

    while (opt != 'e' && opt != 'E'){
        std::cout << "\n=== STUDENT LINE-UP ===\n" << "a) Add student to line\n" << "b) Call next student\n" << "c) View first in line\n" << "d) Show full line\n" << "e) Exit\n" << "Choose option: ";
        std::cin >> opt;
        std::cin.ignore();
        if (opt == 'a' || opt == 'A'){
            std::cout << "\nInput Student ID: ";
            std::cin >> studentID;
            std::cin.ignore();
            enqueue(studentID);
        }   
        
        else if (opt == 'b' || opt == 'B'){
            if (isempty() == true){
            std::cout << "\nThe line is empty, you can't call again\n";
            }
            else {
            dequeue();
            std::cout << "\nThe Student has been called\n";
            }
        }
        else if (opt == 'c' || opt == 'C'){
            if (isempty() == true){
                std::cout << "\nThere is no one in the Line\n";
            }
            else{
            std::cout << "\nThe First in Line: ";
            peek();
            std::cout << "\n";
            }
        }
        else if (opt == 'd' || opt == 'D'){
            if (isempty() == true){
               std::cout << "\nThe line is empty\n"; 
            }
            else{
            std::cout << "\nStudent ID List in Line: \n";
            display();
            }
        }
    }
    
    return 0;
}


