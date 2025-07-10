/*
**********************
id: 22011625
name: Brooklyn Neo Allexius
contact: +60 19-7077 715
email: brooklyn_22011625@utp.edu.my
Lab: 5
*/
#include <iostream>

using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string val) : data(val), next(nullptr) {}
};

class Stack {

public:

    Node* top;
    Stack() : top(nullptr) {}

    
    void push(string value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << value << endl;
    }

    void display() {
        Node* current = top;
        if (current == nullptr) {
            cout << "Stack empty" << endl;
            return;
        }
        cout << "Stack contains: ";
        while (current != nullptr) {
            cout << current->data << "-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
        
    }


    
    void pop() {
        if (top == nullptr) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped: " << temp->data << endl;
        delete temp; 
    }


    string peek() {
        if (top == nullptr) {
            return "empty stack";
        }
        return top->data;
    }

    
    bool isEmpty() {
        return top == nullptr;
    }



    
};

int main() {
    Stack s;

    s.push("Ali");
    s.push("Bob");
    s.push("Cade");

    s.display();

    cout << "Top: " << s.peek() << endl;

    s.pop();
    s.display();
    s.pop();
    s.pop();
    s.display(); 
    s.pop(); 

    return 0;
}