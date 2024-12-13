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
   ```bash
   g++ -o InMemoryDB InMemoryDB.cpp

## To make an Official Assignment
To make this assignment an official coursework assignment:

Clarify that the get function works outside of a transaction and explain its behavior when keys are missing.
Add test cases that validate edge conditions.
Provide a sample grading rubric that emphasizes clean exception handling and proper transaction isolation.
Require integration tests to simulate a real-world application of the in-memory database.
