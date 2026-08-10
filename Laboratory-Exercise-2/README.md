# Expression Parser & Converter (Infix to Prefix/Postfix)

A lightweight C++ implementation for parsing and converting arithmetic expressions from **Infix notation** to **Prefix (Polish)** and **Postfix (Reverse Polish)** notations. The program provides both standard array-based conversions and detailed step-by-step trace tables using `std::stack`.

---

##  Features

- **Dual Implementation**:
  - **Fixed-size Array Stack**: Lightweight pointer-based stack implementation for standard conversion.
  - **STL (`std::stack`)**: Dynamic stack conversion with step-by-step state logging.
- **Full Operator Support**:
  - Multi-level operator precedence (`+`, `-`, `*`, `/`, `^`).
  - Correct associativity rules (Left-to-Right for standard arithmetic, Right-to-Left for exponentiation `^`).
  - Nested parenthetical expressions `()` overrides.
- **Trace Output**: Visualizes Incoming Characters (**ICP**), Stack State (**ISP**), and intermediate output during STL-based execution.

---

##  Operator Rules & Precedence

| Operator | Description | Precedence Level | Associativity |
| :---: | :---: | :---: | :---: |
| `^` | Exponentiation | `3` | **Right-to-Left** |
| `*`, `/` | Multiplication, Division | `2` | Left-to-Right |
| `+`, `-` | Addition, Subtraction | `1` | Left-to-Right |
| `(`, `)` | Grouping Parentheses | Priority Override | N/A |

---

## Algorithm Overview

### Infix to Postfix (Shunting-Yard)
1. Read expression left-to-right.
2. Append operands directly to output.
3. Push `(` onto the stack.
4. On `)`, pop operators to output until `(` is reached.
5. On operators, pop higher (or equal, for left-associative) precedence operators to output before pushing the new operator.

### Infix to Prefix (Reversed Processing)
1. Reverse the input string.
2. Swap parentheses (`(` becomes `)`, and vice-versa).
3. Process tokens left-to-right with inverted precedence checks:
   - Left-associative operators pop strictly higher precedence (`>`).
   - Right-associative operators pop higher or equal precedence (`>=`).
4. Reverse the final result string to produce Prefix notation.

---

## Getting Started

### Prerequisites
- A C++ compiler with C++11 support or higher (e.g., `g++`, `clang++`, or MSVC).

### Compilation
Compile the program using standard GCC/Clang options:

```bash
g++ -std=c++11 -O2 main.cpp -o expression_converter
```

### Running the Executable

```bash
./expression_converter
```

---

## 💻 Usage Example

Given default test expression:
$$	ext{Infix: } (a+b)*D+E/(F+(G+A*D))+c$$

### Terminal Output Preview

```text
Infix Expression = (a+b)*D+E/(F+(G+A*D))+c
Options:
[1] Prefix Notation
[2] Postfix Notation
[3] Using Stack 
Enter your choice: 3

==================================================
FINAL RESULTS USING STACK
Infix:   (a+b)*D+E/(F+(G+A*D))+c

--- Infix to Postfix Steps ---
ICP         ISP                 Postfix Output
--------------------------------------------------
(           -#(                 
a           -#(                 a
+           -#(+                a
b           -#(+                ab
)           -#                  ab+
*           -#*                 ab+
D           -#*                 ab+D
+           -#+                 ab+D*
...

Postfix:  ab+D*EFGAD*++/+c+

Prefix:   ++*+abD/E+F+G*ADc
```

---

##  Code Structure

- **`isOperand() / isOperator()`**: Validates input tokens.
- **`getPrecedence() / isRightAssociative()`**: Defines mathematical priorities and operator directional behavior.
- **`postfix() / prefix()`**: Array-based lightweight converters.
- **`convertToPostfix() / convertToPrefix()`**: STL stack implementations with trace logs.
- **`main()`**: Interactive terminal menu loop.

---

##  Limitations

- Handles single-character alphanumeric operands (`a-z`, `A-Z`, `0-9`).
- Array-based stack functions carry a maximum stack size limit of 100 elements.
