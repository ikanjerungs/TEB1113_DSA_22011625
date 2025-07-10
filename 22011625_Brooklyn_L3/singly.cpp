/*********************
id: 22011625  
name: Brooklyn Neo Allexius  
contact: +60 19-7077 715  
email: brooklyn_22011625@utp.edu.my  
Lab: 3  
*/
#include <iostream>
using namespace std;

// Node class for singly linked list
class ListNode {
public:
    string value;
    ListNode* next;

    ListNode(string val) {
        value = val;
        next = nullptr;
    }
};

int main() {
    // Creating the linked list nodes
    ListNode* first = new ListNode("Ali");
    ListNode* second = new ListNode("Bob");
    ListNode* third = new ListNode("Cade");

    // Linking nodes: Ali -> Bob -> Cade
    first->next = second;
    second->next = third;

    // Display contents before deletion
    cout << "List before removal: ";
    ListNode* ptr = first;
    while (ptr != nullptr) {
        cout << ptr->value << " ";
        ptr = ptr->next;
    }
    cout << endl;

    // Delete the second node (Bob)
    first->next = third;
    delete second;

    // Display contents after deletion
    cout << "List after removal: ";
    ptr = first;
    while (ptr != nullptr) {
        cout << ptr->value << " ";
        ptr = ptr->next;
    }
    cout << endl;

    // Clean up memory
    ptr = first;
    while (ptr != nullptr) {
        ListNode* toDelete = ptr;
        ptr = ptr->next;
        delete toDelete;
    }

    return 0;
}
