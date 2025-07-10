/*********************
id: 22011625  
name: Brooklyn Neo Allexius  
contact: +60 19-7077 715  
email: brooklyn_22011625@utp.edu.my  
Lab: 4  
*/
#include <iostream>
using namespace std;

// Node class for circular linked list
class PersonNode {
public:
    string label;
    PersonNode* next;

    PersonNode(string label) : label(label), next(nullptr) {}
};

// Circular linked list implementation
class RoundList {
public:
    PersonNode* start = nullptr;
    PersonNode* end = nullptr;

    // Insert a node into the list
    void insert(string label) {
        PersonNode* newNode = new PersonNode(label);
        if (start == nullptr) {
            start = newNode;
            end = newNode;
            newNode->next = start;
        } else {
            end->next = newNode;
            end = newNode;
            end->next = start;
        }
    }

    // Display the list
    void showList() {
        if (start == nullptr) return;

        PersonNode* temp = start;
        do {
            cout << temp->label << " -> ";
            temp = temp->next;
        } while (temp != start);
        cout << temp->label << endl; // show the first node again to indicate circularity
    }
};

int main() {
    RoundList circle;

    circle.insert("Ali");
    circle.insert("Bob");
    circle.insert("Cade");

    circle.showList();

    return 0;
}
