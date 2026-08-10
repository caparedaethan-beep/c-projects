# Problem Statement: Expression Conversion Visualizer (Infix to Postfix & Prefix)

## Objective
Write a program that takes an arithmetic expression in **Infix notation** (e.g., `A + B * C`) as input, converts it into both **Postfix (Reverse Polish Notation)** and **Prefix (Polish Notation)** expressions using a stack-based algorithm, and displays a step-by-step trace table showing the state of the operator stack and output buffer at each token processing step.

---

## Background & Specifications

### 1. Supported Characters & Operators
* **Operands**: Alphanumeric characters (`A-Z`, `a-z`, `0-9`).
* **Operators**:
  | Operator | Description | Precedence | Associativity |
  | :---: | :---: | :---: | :---: |
  | `^` | Exponentiation | 3 (Highest) | Right-to-Left |
  | `*`, `/` | Multiplication, Division | 2 | Left-to-Right |
  | `+`, `-` | Addition, Subtraction | 1 (Lowest) | Left-to-Right |
* **Parentheses**: `(` and `)` are used for grouping and overriding standard operator precedence.
* **Whitespace**: Spaces should be ignored during parsing.

---

## Rules & Conversion Logic

### A. Infix to Postfix Conversion Algorithm (Shunting-Yard Variant)
1. Read the infix expression token by token from **left to right**.
2. **If token is an Operand**: Append it directly to the Postfix output string.
3. **If token is `(`**: Push it onto the operator stack.
4. **If token is `)`**: Pop operators from the stack and append them to the Postfix output until a `(` is popped.
5. **If token is an Operator**:
   * While the stack is not empty, top is not `(`, and:
     * Operator is **left-associative** AND `precedence(stack.top) >= precedence(token)`, OR
     * Operator is **right-associative** AND `precedence(stack.top) > precedence(token)`
     * Pop from stack to Postfix output.
   * Push the current operator onto the stack.
6. After reading all tokens, pop any remaining operators in the stack to the output.

### B. Infix to Prefix Conversion Algorithm
1. **Reverse** the input infix expression string.
2. Read the reversed infix string token by token from **left to right**:
   * **Operand**: Append directly to reversed output string.
   * **`)` (Closing Parenthesis)**: Push onto stack.
   * **`(` (Opening Parenthesis)**: Pop from stack to reversed output until `)` is popped.
   * **Operator**:
     * While stack is not empty, top is not `)`, and:
       * Operator is **left-associative** AND `precedence(stack.top) > precedence(token)`, OR
       * Operator is **right-associative** AND `precedence(stack.top) >= precedence(token)`
       * Pop from stack to reversed output.
     * Push current operator onto stack.
3. Pop any remaining operators in the stack to the reversed output.
4. **Reverse** the resulting string to obtain the final Prefix expression.

---

## Input / Output Requirements

### Input Format
* A single line containing an infix expression (e.g., `(A+B)*C^D-E`).

### Output Format
1. **Step-by-step trace tables** for both Postfix and Prefix conversions showing:
   * **Symbol**: The current character/token being processed (or `End` when flushing remaining stack items).
   * **Operator Stack**: Current contents of the stack.
   * **Output**: Accumulated output string at each step.
2. **Final Results Summary**: Printing the original Infix, converted Postfix, and converted Prefix expressions.

---

## Sample Execution

### Example Input
```text
(A+B)*C
```

### Example Output
```text
Enter Infix Expression: (A+B)*C

--- Infix to Postfix Steps ---
Symbol      Operator Stack      Postfix Output
--------------------------------------------------
(           (                   
A           (                   A
+           (+                  A
B           (+                  AB
)                             AB+
*           *                   AB+
C           *                   AB+C
End                             AB+C*

--- Infix to Prefix Steps (Reversed Processing) ---
Symbol      Operator Stack      Reversed Output
--------------------------------------------------
C                               C
*           *                   C
)           *)                  C
B           *)                  CB
+           *)+                 CB
A           *)+                 CBA
(           *                   CBA+
End                             CBA+*

==================================================
FINAL RESULTS:
Infix:   (A+B)*C
Postfix: AB+C*
Prefix:  *(+AB)C
```

---

## Compilation & Usage

### Prerequisites
* C++ compiler supporting C++11 or higher (e.g., `g++`, `clang++`, or MSVC).

### Building and Running
```bash
# Compile the C++ source file
g++ -std=c++11 -o expression_converter main.cpp

# Execute the binary
./expression_converter
```
