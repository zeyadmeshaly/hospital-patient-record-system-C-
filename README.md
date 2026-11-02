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
