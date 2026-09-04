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

bool insertNode (Node*& node, char value){
    //It indicates that when node will become NULL it means that there is no value in it and now it can put a new node.
    if (node == nullptr) {
        node = new Node(value); //This add a new node
        return true; //Since it added a new node it return true to ensure the insertion of the node is true
    }
    //This will indicate whether the value is less than the root node which will go to left of the root
    if (value < node -> data){
        return insertNode(node -> left, value); //This will indicate whether the value is less than the child node and it will recurse
    }
    //This will indicate whether the value is greater than the root node which will go to right of the root
    if (value > node -> data){ 
        return insertNode(node -> right, value);
     }
     return false; //If there is a duplication it returns false as you dont input same nodes.
}

void inOrder (Node* node){
    if (node == nullptr) return; //This will return back to the main if there is no node in the tree.
    //In-order Traversal → Left → Root → Right
    inOrder (node -> left);
    std:: cout << node -> data << " ";
    inOrder (node -> right);
}


void preOrder (Node* node){
    if (node == nullptr) return;
    //Pre-order Traversal → Root → Left → Right
    std:: cout << node -> data << " "; //This will print all of the nodes of the tree
    preOrder (node -> left);
    preOrder (node -> right);
}

void postOrder (Node* node){
    if (node == nullptr) return;
    //Post-order Traversal → Left → Right → Root
    postOrder (node -> left);
    postOrder (node -> right);
    std::cout << node -> data << " ";
}

int main(){
    //This will make the root to be null as there weren't any node to have at the moment
    Node* root = nullptr;
    char node;
    int count = 0;
    //This will input data to use for our node
    std::cout << "Input 15 character or below (If you want to make it early use '#' at the last to ensure it breaks): ";

    while (count < 15 && (std::cin >> node)) {
        //This ensures that there will be no other inputs except characters
        if (!std::isalpha(node)){
            std::cout << "Your input is not a character"; 
            return 1;
        }
        //This ensures that when a user input that symbol it automatically breaks in order to input below 15 characters
        if (node == '#') {
            break; 
        }
        node = std::toupper(node); //This will make it uppercase

         //Since we are adding an input, this will may or may not make a new node with this functions
        if (insertNode (root, node)) {
            count++;
        } else std::cout << "You have inputted a duplicated character: " << node << "\n"; //It eliminates duplication/s.
        
    }

    //Output
    std::cout << "Pre-order Traversal: ";
    preOrder(root); //Output of the pre-order transverse function
    std::cout << std::endl;
    std::cout << "In-order Traversal: ";
    inOrder(root); //Output of the in-order transverse function
    std::cout << std::endl;
    std::cout << "Post-order Traversal: ";
    postOrder(root); //Output of the post-order transverse function
    std::cout << std::endl;
    
}