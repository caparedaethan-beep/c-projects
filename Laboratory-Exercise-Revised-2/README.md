# Expression Converter

A C++ program that handles expression conversions between **Infix**, **Prefix**, and **Postfix** notations. It provides visual, step-by-step state tracing of stacks and buffers during execution.

---

## Features

- **Prefix / Postfix to Infix Conversion:** Uses an array-based stack implementation to reconstruct parenthesized infix expressions from prefix or postfix input strings.
- **Infix to Prefix / Postfix Conversion:** Implements the Shunting-Yard algorithm (using `std::stack`) with support for operator precedence and associativity rules (e.g., right-associativity for `^`).
- **Visual State Tracing:** Outputs real-time visual tables tracking Incoming Control Characters (ICP), In-Stack Elements (ISP), operator stack states, and step-by-step token actions.

---

## Operator Precedence & Associativity

| Precedence Level | Operators | Associativity |
| :--- | :--- | :--- |
| **3** (Highest) | `^` | Right-to-Left |
| **2** | `*`, `/` | Left-to-Right |
| **1** (Lowest) | `+`, `-` | Left-to-Right |

---

## Compilation & Execution

Build and run the source code using any C++11 compliant compiler:

```bash
# Compile source code
g++ -std=c++11 main.cpp -o expression_converter

# Run executable
./expression_converter
```

---

## Interactive Options

When executed, select from three processing options:

1. **Option 1 (Prefix Array):** Converts a predefined prefix expression (`++*+abD/E+F+G*ADc`) to fully parenthesized infix using a manual array stack.
2. **Option 2 (Postfix Array):** Converts a predefined postfix expression (`ab+D*EFGAD*++/+c+`) to fully parenthesized infix using a manual array stack.
3. **Option 3 (Using Stack):** Executes Shunting-Yard algorithm transformations on an infix string (`(a+b)*D+E/(F+(G+A*D))+c`), printing visual execution trace tables for both Postfix and Prefix outputs.

---

## Code Architecture & Functions

- `convertPrefixToInfixArray`: Scans reverse string and builds parenthesized infix.
- `convertPostfixToInfixArray`: Scans string left-to-right and builds parenthesized infix.
- `convertToPostfixStack`: Shunting-yard implementation converting infix to postfix.
- `convertToPrefixStack`: Reversed-string shunting-yard variant converting infix to prefix.
- `getPrecedence` / `isRightAssociative`: Evaluates mathematical operator priority rules.
