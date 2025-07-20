/*
**********************
id: 22011625
name: Brooklyn Neo Allexius
contact: +60 19-7077 715
email: brooklyn_22011625@utp.edu.my
Lab: 8
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

    // BST Insertion
    void insert(string name) {
        root = insert_recursive(root, name);
    }

    // BST Search
    bool search(string name) {
        return search_recursive(root, name);
    }

private:
    Node* insert_recursive(Node* node, string name) {
        if (node == nullptr)
            return new Node(name);

        if (name < node->name)
            node->left = insert_recursive(node->left, name);
        else if (name > node->name)
            node->right = insert_recursive(node->right, name);

        return node;
    }

    bool search_recursive(Node* node, string name) {
        if (node == nullptr)
            return false;
        if (node->name == name)
            return true;
        else if (name < node->name)
            return search_recursive(node->left, name);
        else
            return search_recursive(node->right, name);
    }
};

// Traversals
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

    // Insert nodes into BST
    tree.insert("D");
    tree.insert("B");
    tree.insert("A");
    tree.insert("C");
    tree.insert("F");
    tree.insert("E");
    tree.insert("G");

    cout << "Root: " << tree.root->name << endl;

    cout << endl << "Preorder Traversal: ";
    preorder(tree.root);
    cout << endl << "Inorder Traversal: ";
    inorder(tree.root);
    cout << endl << "Postorder Traversal: ";
    postorder(tree.root);
    cout << endl;

    // Search
    string target;
    cout << "\nEnter a character to search: ";
    cin >> target;

    if (tree.search(target)) {
        cout << target << " is found in the tree." << endl;
    } else {
        cout << target << " is NOT found in the tree." << endl;
    }

    return 0;
}
