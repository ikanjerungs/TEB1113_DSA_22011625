/*
**********************
id: 22011625
name: Brooklyn Neo Allexius
contact: +60 19-7077 715
email: brooklyn_22011625@utp.edu.my
Lab: 6
*/

#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    static const int SIZE = 5;
    string arr[SIZE];
    int front;
    int rear;
    int count;

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull() {
        return count == SIZE;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        rear = (rear + 1) % SIZE;
        arr[rear] = name;
        count++;

        cout << "Enqueued: " << name << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % SIZE;
        count--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
        } else {
            cout << "Front of queue: " << arr[front] << endl;
        }
    }

    void display_queue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % SIZE;
            cout << arr[index];
            if (i < count - 1)
                cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue("Zara");
    queue.enqueue("Imran");
    queue.enqueue("Lina");
    queue.enqueue("Lez");
    queue.enqueue("Waffy");

    queue.display_queue();

    queue.dequeue();
    queue.dequeue();

    queue.enqueue("Wilfred");
    queue.enqueue("Faris");

    cout << "After dequeue and wrap-around enqueue: " << endl;
    queue.display_queue();

    queue.peek();

    return 0;
}
