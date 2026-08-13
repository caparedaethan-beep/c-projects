# Euclidean Algorithm GCD Calculator (C++)

A C++ console application that computes the **Greatest Common Divisor (GCD)** of two user-provided integers using the **Euclidean Algorithm**.

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [How the Algorithm Works](#how-the-algorithm-works)
- [Prerequisites](#prerequisites)
- [Compilation & Execution](#compilation--execution)
- [Usage Instructions](#usage-instructions)
- [Test Cases & Validation](#test-cases--validation)
- [Code Structure Explanation](#code-structure-explanation)

---

## 🔍 Overview

The **Greatest Common Divisor (GCD)** of two integers is the largest positive integer that divides both numbers without leaving a remainder. 

This program prompts the user for two numbers (a divisor and a dividend), applies repeated division using C++'s modulo operator (`%`), and outputs the calculated GCD alongside the initial values.

---

## Features

- **Interactive Console Input:** Captures inputs directly from the standard input stream (`std::cin`).
- **Euclidean Algorithm Implementation:** Employs efficient remainder shifting via a `while` loop.
- **Original Input Preservation:** Preserves user inputs in separate variables (`divisor`, `dividend`) for final summary display.
- **Division-by-Zero Safety:** Built-in loop condition (`num1 != 0`) prevents crashes when `0` is passed as a divisor.

---

## How the Algorithm Works

The Euclidean Algorithm is based on the principle that the GCD of two numbers also divides their remainder.

1. Take two integers, $A$ (dividend) and $B$ (divisor).
2. Calculate the remainder $R = A \pmod B$.
3. Replace $A$ with $B$, and $B$ with $R$.
4. Repeat steps 2–3 until $B = 0$.
5. The non-zero value remaining in $A$ is the GCD.

---

## Prerequisites

To build and run this program, you need:

- A C++ compiler supporting C++11 or later (e.g., `g++`, `clang++`, or MSVC).
- A terminal or command prompt interface.

---

## Compilation & Execution

### Using GCC (`g++`)

1. Open your terminal in the folder containing `main.cpp`.
2. Compile the source code:
   ```bash
   g++ -o gcd_calculator main.cpp