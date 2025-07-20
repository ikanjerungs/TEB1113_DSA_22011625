/*
**********************
id: 22011625
name: Brooklyn Neo Allexius
contact: +60 19-7077 715
email: brooklyn_22011625@utp.edu.my
Lab: 8
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Base Heap class (abstract)
class Heap {
public:
    Node* root;

    Heap() {
        root = nullptr;
    }

    void buildHeap(vector<int> values) {
        for (int val : values) {
            insert(val);
        }
    }

    void levelOrder() {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            cout << curr->value << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

protected:
    virtual bool compare(int childVal, int parentVal) = 0; // pure virtual

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front(); q.pop();

            if (!curr->left) {
                curr->left = newNode;
                heapifyUp(curr, curr->left);
                break;
            } else q.push(curr->left);

            if (!curr->right) {
                curr->right = newNode;
                heapifyUp(curr, curr->right);
                break;
            } else q.push(curr->right);
        }
    }

    void heapifyUp(Node* parent, Node* child) {
        if (compare(child->value, parent->value)) {
            swap(child->value, parent->value);

            if (parent == root) return;

            queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                Node* curr = q.front(); q.pop();
                if (curr->left == parent || curr->right == parent) {
                    heapifyUp(curr, parent);
                    break;
                }
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
    }
};

// MaxHeap class
class MaxHeap : public Heap {
protected:
    bool compare(int childVal, int parentVal) override {
        return childVal > parentVal;  // bubble up if child is greater
    }
};

// MinHeap class
class MinHeap : public Heap {
protected:
    bool compare(int childVal, int parentVal) override {
        return childVal < parentVal;  // bubble up if child is smaller
    }
};

// Main program
int main() {
    vector<int> values = {1, 2, 3, 4, 5, 6, 7};

    MaxHeap maxHeap;
    MinHeap minHeap;

    maxHeap.buildHeap(values);
    minHeap.buildHeap(values);

    cout << "Max Heap (Level Order): ";
    maxHeap.levelOrder();
    cout << endl;

    cout << "Min Heap (Level Order): ";
    minHeap.levelOrder();
    cout << endl;

    return 0;
}
