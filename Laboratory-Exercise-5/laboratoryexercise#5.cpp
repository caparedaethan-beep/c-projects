#include <iostream>
#include <cctype>

//This is where we will use to add node
struct Node {
    char data;
    Node* left;
    Node* right;

    //Constructor (In order to add a new node which is safer)
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

void inOrder (Node* node){
    if (node == nullptr) return; //This will return back to the main if there is no node in the tree.
    //In-order Traversal → Left → Root → Right
    inOrder (node -> left);
    std:: cout << node -> data;
    inOrder (node -> right);
}


void preOrder (Node* node){
    if (node == nullptr) return;
    //Pre-order Traversal → Root → Left → Right
    std:: cout << node -> data; //This will print all of the nodes of the tree
    preOrder (node -> left);
    preOrder (node -> right);
}

void postOrder (Node* node){
    if (node == nullptr) return;
    //Post-order Traversal → Left → Right → Root
    inOrder (node -> left);
    inOrder (node -> right);
    std::cout << node -> data;
}

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