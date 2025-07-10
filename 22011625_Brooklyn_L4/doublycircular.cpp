/*********************
id: 22011625  
name: Brooklyn Neo Allexius  
contact: +60 19-7077 715  
email: brooklyn_22011625@utp.edu.my  
Lab: 4  
*/
#include <iostream>
using namespace std;

// Node definition for a doubly circular linked list
class Person {
public:
    string fullName;
    Person* next;
    Person* prev;

    Person(string fullName) : fullName(fullName), next(nullptr), prev(nullptr) {}
};

// Circular doubly linked list implementation
class DoublyCircularList {
private:
    Person* front = nullptr;
    Person* rear = nullptr;

public:
    // Insert a new person into the list
    void insert(string fullName) {
        Person* newPerson = new Person(fullName);
        if (front == nullptr) {
            front = newPerson;
            rear = newPerson;
            newPerson->next = newPerson;
            newPerson->prev = newPerson;
        } else {
            newPerson->next = front;
            newPerson->prev = rear;
            front->prev = newPerson;
            rear->next = newPerson;
            rear = newPerson;
        }
    }

    // Display list in reverse (from tail to head)
    void showReverse() {
        if (rear == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Person* temp = rear;
        do {
            cout << temp->fullName << " -> ";
            temp = temp->prev;
        } while (temp != rear);
        cout << temp->fullName << endl; // print the last node again to close the loop
    }
};

int main() {
    DoublyCircularList namesList;

    namesList.insert("Zara");
    namesList.insert("Imran");
    namesList.insert("Lina");
    namesList.insert("Farid");

    namesList.showReverse();

    return 0;
}
