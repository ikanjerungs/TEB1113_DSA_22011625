/*
**********************
id: 22011625
name: Brooklyn Neo Allexius
contact: +60 19-7077 715
email: brooklyn_22011625@utp.edu.my
Lab: 7
*/

#include <iostream>
using namespace std;

class Node;

void preorder(Node* node);
void inorder(Node* node);
void postorder(Node* node);

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void add_root(string name) {
        root = new Node(name);
    }

    void add_left(Node* parent, string name) {
        parent->left = new Node(name);
    }

    void add_right(Node* parent, string name) {
        parent->right = new Node(name);
    }
};

void preorder(Node* node) {
    if (node != nullptr) {
        cout << node->name << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Node* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->name << " ";
        inorder(node->right);
    }
}

void postorder(Node* node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        cout << node->name << " ";
    }
}

int main() {
    Tree tree;

    tree.add_root("A");
    tree.add_left(tree.root, "B");
    tree.add_right(tree.root, "C");
    tree.add_left(tree.root->left, "D");
    tree.add_right(tree.root->left, "E");
    tree.add_left(tree.root->right, "F");
    tree.add_right(tree.root->right, "G");

    cout << "Root: " << tree.root->name << endl;
    cout << "Left child of root: " << tree.root->left->name << endl;
    cout << "Right child of root: " << tree.root->right->name << endl;
    cout << "Left child of B: " << tree.root->left->left->name << endl;
    cout << "Right child of B: " << tree.root->left->right->name << endl;
    cout << "Left child of C: " << tree.root->right->left->name << endl;
    cout << "Right child of C: " << tree.root->right->right->name << endl;

    cout << endl << "Preorder Traversal: ";
    preorder(tree.root);
    cout << endl << "Inorder Traversal: ";
    inorder(tree.root);
    cout << endl << "Postorder Traversal: ";
    postorder(tree.root);
    cout << endl;

    return 0;
}