/*
**********************
id: 22011625
name: Brooklyn Neo Allexius
contact: +60 19-7077 715
email: brooklyn_22011625@utp.edu.my
Lab: 1
*/
#include <iostream>
using namespace std;


class NameQueue {
public:
    string people[50];
    int start = 0;
    int end = -1;
    int size = 0;

    
    void push(string person) {
        if (size == 50) {
            cout << "Queue is full!" << endl;
            return;
        }
        end++;
        people[end] = person;
        size++;
    }

    
    void pop() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        start++;
        size--;
    }

    
    string frontItem() {
        if (size == 0) return "No one is in the queue.";
        return people[start];
    }

    
    void showQueue() {
        if (size == 0) {
            cout << "Queue is currently empty." << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            int idx = start + i;
            cout << people[idx];
            if (i < size - 1) cout << " -> ";
        }
        cout << " -> NULL" << endl;
    }
};

int main() {
    NameQueue q;

    q.push("Zara");
    q.push("Imran");
    q.push("Lina");

    q.showQueue();

    cout << "Front of the queue: " << q.frontItem() << endl;

    q.pop();
    q.showQueue();

    q.pop();
    q.pop();
    q.showQueue();

    return 0;
}
