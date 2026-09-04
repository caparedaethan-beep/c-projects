/*
Instruction
Enter up to 15 unique values (letters or numbers) to build a binary tree. After you provide the tree structure / input sequence, the program will compute and display the three traversal orders:

    Pre-order Traversal → Root → Left → Right
    In-order Traversal → Left → Root → Right
    Post-order Traversal → Left → Right → Root
*/

#include <iostream>
#include <cctype>

//This is where we will use to add node
struct Node {
    char data;
    Node* left;
    Node* right;

    //Constructor
    Node (char value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void insertNode (Node*& node, char value){
    //It indicates that when node will become NULL it means that there is no value in it and now it can put a new node.
    if (node == nullptr) {
        node = new Node(value);
    }
    //This will indicate whether the value is less than the root node which will go to left of the root
    else if (value < node -> data){
        insertNode(node -> left, value); //This will indicate whether the value is less than the child node and it will recurse
    }
    //This will indicate whether the value is greater than the root node which will go to right of the root
    else if (value > node -> data){ 
        insertNode(node -> right, value);
     }
}




//void inOrder

// void preOrder (Node*& node){

// }

//void postOrder

int main(){
    //This will make the root to be null as there weren't any node to have at the moment
    Node* root = nullptr;
    char node[15];
    //This will input data to use for our node
    for (int i = 0; i < 15; i++){
        std::cin >> node[i];
        node[i] = std::toupper(node[i]); //This will make it uppercase
        insertNode (root, node[i]); //Since we are adding an input, it will make a new node with this functions
    }


    // std::cout << "Pre-order Traversal: ";
    // // preOrder(root);
    // std::cout << std::endl;
    // std::cout << "In-order Traversal: ";
    // //inOrder(root);
    // std::cout << std::endl;
    // std::cout << "Post-order Traversal: ";
    // //postOrder(root);
    // std::cout << std::endl;
    
}