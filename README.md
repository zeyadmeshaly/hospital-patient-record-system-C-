# Patient Records Manager (C++ Linked List)

A console program that stores patient records in a **singly linked list**, written in C++ as part of my data structures learning.

## Features
- **Add** a patient (ID, name, age, disease) at the end of the list
- **Display** all patients
- **Search** a patient by ID
- **Delete** a patient by ID
- **Insert at position** (manager only, password protected)
- **Sort** the list by ID (bubble sort)

## Build and run

Needs a C++ compiler (g++, clang++ or Visual Studio).

```
g++ -std=c++11 patient_list.cpp -o patient_list
./patient_list            # on Windows: patient_list.exe
```

## Example session

```
1. Add
2. Display
3. Search
4. Delete
5. Insert at Position(manager)
6. Sort
7. Exit
Enter choice: 1
Enter ID: 102
Enter Name: Sara Ali
Enter Age: 34
Enter Disease: Asthma
```

## How it works
- `Patient` is a struct holding the record's data.
- `Node` holds one `Patient` plus a pointer to the next node.
- Global `head` and `tail` pointers mark the start and end of the list, so adding at the end does not need to walk the list.
- Searching, deleting and sorting walk the list node by node.
- Sorting swaps the patient data between neighbouring nodes (bubble sort) instead of re-linking the nodes.

## What I learned
- Building and linking nodes with pointers and `new` / `delete`
- Keeping `head` and `tail` correct when inserting and deleting
- Handling the special cases: first node, last node and empty list
- Mixing `cin >>` and `getline` safely with `cin.ignore()`

## Known limitations (things I would improve next)
- No input validation: typing a letter where a number is expected breaks the input loop.
- Duplicate IDs are allowed, so search and delete only act on the first match.
- Nodes are not freed when the program exits (a small memory leak).
- Inserting at position 0 into an **empty** list does not update `tail`, so adding another patient afterwards crashes.
- A negative position in "Insert at Position" is not rejected.
- The manager password (`1234`) is a hardcoded demo value. A real system would never store a password in source code.
- Data lives in memory only and is lost on exit.

## Possible improvements
- Wrap the list in a class and add a destructor
- Validate input and reject duplicate IDs
- Save and load records from a file
