#include <iostream>
// #include <algorithm>
using namespace std;

class Node {
public:
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        height = 1;
        left = right = nullptr;
    }
};

class AVLTree {
private:
    Node* root;

    // Function to get the height of a node
    int height(Node* node) {
        if (node == nullptr)
            return 0; // Height of empty node is 0
        return node->height; // Otherwise, return stored height
    }


// Function to get the balance factor of a node
    int getBalance(Node* node) {
        if (node == nullptr) return 0; // Empty node has balance factor 0
        int leftHeight = height(node->left);  // Height of left subtree
        int rightHeight = height(node->right); // Height of right subtree
        return leftHeight - rightHeight; // Positive if left-heavy, negative if right-heavy
}


    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;  // Duplicate keys not allowed

        // Update height
        node->height = 1 + max(height(node->left), height(node->right));

        // Get balance factor
        int balance = getBalance(node);

        // Balance the tree
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* node, int key) {
        if (!node) return node;

        if (key < node->key)
            node->left = deleteNode(node->left, key);
        else if (key > node->key)
            node->right = deleteNode(node->right, key);
        else {
            // Node with one or no child
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Node* temp = minValueNode(node->right);
                node->key = temp->key;
                node->right = deleteNode(node->right, temp->key);
            }
        }

        if (!node) return node;

        // Update height
        node->height = 1 + max(height(node->left), height(node->right));

        // Balance
        int balance = getBalance(node);

        // Balance the tree
        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
    }

public:
    AVLTree() {
        root = nullptr;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    void displayInorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }
};

// ---------------------- Menu Driver ------------------------

int main() {
    AVLTree tree;
    int choice, value;

    do {
        cout << "\n===== AVL Tree Menu =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display Inorder\n";
        cout << "4. Display Preorder\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.deleteKey(value);
                break;
            case 3:
                tree.displayInorder();
                break;
            case 4:
                tree.displayPreorder();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
