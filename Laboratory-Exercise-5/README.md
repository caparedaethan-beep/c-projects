# Binary Search Tree (BST) Character Traversal

A C++ implementation of a **Binary Search Tree (BST)** designed to store unique uppercase alphabetical characters and display them using standard tree traversal techniques (**Pre-order**, **In-order**, and **Post-order**).

---

## Features

- **Dynamic BST Insertion:** Inserts character nodes into a Binary Search Tree following binary search properties (`Left < Root < Right`).
- **Input Validation:** Restricts input strictly to alphabetical characters (`A-Z`, `a-z`). Non-alphabetical input throws an error.
- **Automatic Formatting:** Automatically converts lowercase character inputs to uppercase (`std::toupper`).
- **Duplicate Prevention:** Rejects duplicate character inputs to maintain distinct BST nodes.
- **Early Termination:** Allows early input completion using the `#` Sentinel character or when reaching the maximum limit of 15 characters.
- **Tree Traversals:** Outputs standard tree traversals:
  - **In-order Traversal** (Left → Root → Right) — *Displays characters in alphabetical order.*
  - **Pre-order Traversal** (Root → Left → Right)
  - **Post-order Traversal** (Left → Right → Root)

---

## Code Structure

| Component | Description |
| :--- | :--- |
| `struct Node` | Represents each node containing a `char data` payload and pointers to `left` and `right` child nodes. Includes a custom constructor for safe initialization. |
| `insertNode(Node*& node, char value)` | Recursively inserts a character into the BST while avoiding duplicate entries. Passes node pointers by reference (`Node*&`). |
| `inOrder(Node* node)` | Recursively performs **In-order Traversal**. |
| `preOrder(Node* node)` | Recursively performs **Pre-order Traversal**. |
| `postOrder(Node* node)` | Recursively performs **Post-order Traversal**. |
| `main()` | Handles user interaction, input sanitization, BST populating logic, and traversal output rendering. |

---

## Logic & Bug Note

In the `main()` function:
```cpp
if (!std::isalpha(node)){
    std::cout << "Your input is not a character"; 
    return 1;
}
if (node == '#') {
    break; 
}
```
> **Note:** Because `std::isalpha('#')` evaluates to `false`, entering `#` triggers the `"Your input is not a character"` validation error before reaching the `if (node == '#')` check. To allow `#` as a sentinel break character, check for `#` **before** testing `std::isalpha(node)`.

---

## How to Run

### 1. Prerequisites
Ensure you have a C++ compiler installed (such as `g++`, `clang++`, or MSVC).

### 2. Compilation
Compile the program using standard C++11 (or later):
```bash
g++ -std=c++11 main.cpp -o bst_traversal
```

### 3. Execution
Run the compiled executable:
```bash
./bst_traversal
```

---

## Example Output

### Sample Run
```text
Input 15 character or below (If you want to make it early use '#' at the last to ensure it breaks): M F T A K P Z
Pre-order Traversal: M F A K T P Z 
In-order Traversal: A F K M P T Z 
Post-order Traversal: A K F P Z T M 
```

### Handling Duplicates
```text
Input 15 character or below (If you want to make it early use '#' at the last to ensure it breaks): A B A C
You have inputted a duplicated character: A
Pre-order Traversal: A B C 
In-order Traversal: A B C 
Post-order Traversal: C B A 
```

---

## License
This project is open-source and intended for educational purposes.
