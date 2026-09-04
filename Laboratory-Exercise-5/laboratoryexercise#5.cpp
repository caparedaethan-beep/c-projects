#include <iostream>
#include <cctype>

//This is where we will use to add node
struct node {
    char data;
    node* left;
    node* right;

    //Constructor
    node (char value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// void insertNode (node*& node, char value){
//     if (node == nullptr) return;
// }


//void inOrder

//void preOrder

//void postOrder

int main(){
    node* root = nullptr;
    char node[15];
    //This will input data to use for our node
    for (int i = 0; i < 15; i++){
        std::cin >> node[i];
        node[i] = std::toupper(node[i]); //This will make it uppercase
        // insertNode (root, node[i]);
    }


    std::cout << "Pre-order Traversal: ";
    // preOrder(root);
    std::cout << std::endl;
    std::cout << "In-order Traversal: ";
    //inOrder(root);
    std::cout << std::endl;
    std::cout << "Post-order Traversal: ";
    //postOrder(root);
    std::cout << std::endl;
    
}