#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string disease;
};

struct Node {
    Patient data;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void addPatient(Patient p) {
    Node* newNode = new Node;
    newNode->data = p;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(Patient p, int pos) {
    Node* newNode = new Node;
    newNode->data = p;
    newNode->next = nullptr;

    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    if (newNode->next == nullptr)
        tail = newNode;
}

void display() {
    if (head == nullptr) {
        cout << "No patients.\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->data.id << endl;
        cout << "Name: " << temp->data.name << endl;
        cout << "Age: " << temp->data.age << endl;
        cout << "Disease: " << temp->data.disease << endl;
        cout << "-------------------\n";
        temp = temp->next;
    }
}

void search(int id) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data.id == id) {
            cout << "Found: " << temp->data.name << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Not found\n";
}

void deletePatient(int id) {
    if (head == nullptr) {
        tail = nullptr;
        cout << "List empty\n";
        return;
    }

    if (head->data.id == id) {
        Node* temp = head;
        head = head->next;

        if (head == nullptr)
            tail = nullptr;
        delete temp;
        cout << "Deleted\n";
        return;
    }

    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr && curr->data.id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Not found\n";
        return;
    }


    if (curr == tail) {
        tail = prev;
    }

    prev->next = curr->next;
    delete curr;
    cout << "Deleted\n";
}

void sortList() {
    if (head == nullptr) return;

    bool swapped;
    Node* ptr;

    do {
        swapped = false;
        ptr = head;

        while (ptr->next != nullptr) {
            if (ptr->data.id > ptr->next->data.id) {
                Patient temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = true;
            }
            ptr = ptr->next;
        }

    } while (swapped);

    cout << "List sorted by ID\n";
}

int main() {
    int choice;

    do {
        cout << "\n1. Add\n2. Display\n3. Search\n4. Delete\n5. Insert at Position(manager)\n6. Sort\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Patient p;

            cout << "Enter ID: ";
            cin >> p.id;
            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, p.name);

            cout << "Enter Age: ";
            cin >> p.age;
            cin.ignore();

            cout << "Enter Disease: ";
            getline(cin, p.disease);

            addPatient(p);
        }

        else if (choice == 2) {
            display();
        }

        else if (choice == 3) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            search(id);
        }

        else if (choice == 4) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            deletePatient(id);
        }

        else if (choice == 5) {
            Patient p;
            cout << "please enter password ";
            int pass;
            cin >> pass;
            if (pass == 1234) {
                int pos;

                cout << "Enter ID: ";
                cin >> p.id;
                cin.ignore();

                cout << "Enter Name: ";
                getline(cin, p.name);

                cout << "Enter Age: ";
                cin >> p.age;
                cin.ignore();

                cout << "Enter Disease: ";
                getline(cin, p.disease);

                cout << "Enter Position: ";
                cin >> pos;

                insertAtPosition(p, pos);
            }
            else {
                cout << "incorrect password";
            }
        }

        else if (choice == 6) {
            sortList();
        }

    } while (choice != 7);

    return 0;
}
