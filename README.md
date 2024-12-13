# InMemoryDB

## Overview
This project implements an in-memory key-value database in C++, supporting transactional operations.

## Features
- `get(key)`: Retrieves the value of a key.
- `put(key, value)`: Sets or updates a key-value pair within an active transaction.
- `begin_transaction()`: Starts a new transaction.
- `commit()`: Commits all changes made in the active transaction to the database.
- `rollback()`: Discards all changes made during the active transaction.

## How to Run
1. Ensure you have a C++ compiler installed.
2. Compile the code:
   ```g++ -o InMemoryDB InMemoryDB.cpp```

### Linux/macOS: Ensure GCC is installed. Use the command:
``g++ --version``
If GCC is not installed, use:

``sudo apt-get install g++``        
### For Ubuntu/Debian
``brew install gcc``

### For macOS with Homebrew
Windows: Install MinGW or use the Windows Subsystem for Linux (WSL).
Clone the repository:

``git clone https://github.com/YourUsername/InMemoryDB.git
cd InMemoryDB``
Steps to Run
Compile the program:
``g++ -o InMemoryDB InMemoryDB.cpp``

Execute the program:

``./InMemoryDB``

Expected Output:
The program includes test cases in the main() function that demonstrate:
Correct handling of transactions.
Commit and rollback operations.
Error handling for invalid operations (e.g., put() outside a transaction).
The output should match the sample scenarios provided in the project description.

## To Make an Official Assignment

Clarify that the get function works outside of a transaction and explain its behavior when keys are missing.
Add test cases that validate edge conditions.
Provide a sample grading rubric that emphasizes clean exception handling and proper transaction isolation.
Require integration tests to simulate a real-world application of the in-memory database.
