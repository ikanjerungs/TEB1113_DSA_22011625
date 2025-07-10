/*********************
id: 22011625
name: Brooklyn Neo Allexius
contact: +60 19-7077 715
email: brooklyn_22011625@utp.edu.my
Lab: 3
*/
#include <iostream>
using namespace std;

// Definition of a doubly linked list node
class PersonNode {
public:
    string name;
    PersonNode* next;
    PersonNode* prev;

    PersonNode(string name) {
        this->name = name;
        next = nullptr;
        prev = nullptr;
    }
};

int main() {
    // Creating three nodes
    PersonNode* first = new PersonNode("Ali");
    PersonNode* second = new PersonNode("Bob");
    PersonNode* third = new PersonNode("Cade");

    // Linking nodes together
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;

    // Display list before deleting second node
    cout << "List before deletion: ";
    PersonNode* temp = first;
    while (temp != nullptr) {
        cout << temp->name << " ";
        temp = temp->next;
    }
    cout << endl;

    // Remove second node (Bob)
    first->next = third;
    third->prev = first;
    delete second;

    // Display list after deletion
    cout << "List after deletion: ";
    temp = first;
    while (temp != nullptr) {
        cout << temp->name << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free remaining memory
    temp = first;
    while (temp != nullptr) {
        PersonNode* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    return 0;
}
