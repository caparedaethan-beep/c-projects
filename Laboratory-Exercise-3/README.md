# Problem Statement: Circular Queue Student Line-Up System

## Objective
Write a C++ program that implements a fixed-size **Circular Queue** data structure using arrays to manage a student queuing line system (`STUDENT LINE-UP`). The program should present an interactive menu allowing users to add students to the line, call the next student in line, view the front student, display all queued student IDs, and gracefully handle empty and full queue conditions.

---

## Background & Specifications

### 1. Data Structure Overview
* **Structure Type**: Array-based Circular Queue using fixed size (`MAX = 5`).
* **Pointers**:
  * `front`: Tracks the index of the first element in the queue. Initialized to `-1`.
  * `rear`: Tracks the index of the last element in the queue. Initialized to `-1`.

### 2. Operations & Edge Cases
* **Enqueue (Add Student)**:
  * Inserts a student ID at `rear = (rear + 1) % MAX`.
  * **Full Condition**: Occurs when `((rear + 1) % MAX) == front`. Displays an error message and rejects insertion.
* **Dequeue (Call Student)**:
  * Removes the student ID at `front`.
  * **Reset Condition**: If `front == rear` (last element dequeued), both `front` and `rear` reset to `-1`.
  * Standard shift occurs via `front = (front + 1) % MAX`.
* **Peek / View Front**: Prints the element at `queue[front]` without modifying pointer indices.
* **Display**: Traverses from `front` to `rear` modulo `MAX` to print all active queue entries in order.
* **Empty State**: Checked via `front == -1 && rear == -1`.

---

## Rules & Algorithmic Logic

### A. Queue Initialization
* `front = -1`, `rear = -1`

### B. Enqueue Logic
1. Check if queue is empty (`front == -1 && rear == -1`). If true, set `front = 0` and `rear = 0`, then place student ID at `queue[rear]`.
2. Check if queue is full (`(rear + 1) % MAX == front`). If true, print `"Queue is Full"`.
3. Otherwise, update `rear = (rear + 1) % MAX` and store student ID at `queue[rear]`.

### C. Dequeue Logic
1. Check if queue is empty (`front == -1 && rear == -1`). If true, perform no action.
2. Check if `front == rear`. If true, set both `front = -1` and `rear = -1`.
3. Otherwise, update `front = (front + 1) % MAX`.

---

## Input / Output Requirements

### Menu Options
* `a` / `A`: Add student ID to line.
* `b` / `B`: Call next student in line (dequeue).
* `c` / `C`: View student currently first in line (peek).
* `d` / `D`: Display full list of active student IDs in line.
* `e` / `E`: Exit program.

---

## Sample Execution

### Example Output

```text
=== STUDENT LINE-UP ===
a) Add student to line
b) Call next student
c) View first in line
d) Show full line
e) Exit
Choose option: a

Input Student ID: 1001

=== STUDENT LINE-UP ===
a) Add student to line
b) Call next student
c) View first in line
d) Show full line
e) Exit
Choose option: a

Input Student ID: 1002

=== STUDENT LINE-UP ===
a) Add student to line
b) Call next student
c) View first in line
d) Show full line
e) Exit
Choose option: c

The First in Line: 1001

=== STUDENT LINE-UP ===
a) Add student to line
b) Call next student
c) View first in line
d) Show full line
e) Exit
Choose option: d

Student ID List in Line: 
1001
1002

=== STUDENT LINE-UP ===
a) Add student to line
b) Call next student
c) View first in line
d) Show full line
e) Exit
Choose option: b

The Student has been called

=== STUDENT LINE-UP ===
a) Add student to line
b) Call next student
c) View first in line
d) Show full line
e) Exit
Choose option: e
```

---

## Compilation & Usage

### Prerequisites
* Standard C++ compiler supporting standard C++ (e.g., `g++`, `clang++`, MSVC).

### Building and Running
```bash
# Compile the C++ program
g++ main.cpp -o student_queue

# Run the compiled program
./student_queue
```
