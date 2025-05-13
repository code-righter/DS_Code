#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int val) {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() {
        size = 0;
        head = tail = NULL;
    }

    void insertAtHead(Node* node) {
        if (node == NULL) return;

        if (head == NULL) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        size++;
    }

    void insertAtTail(Node* node) {
        if (node == NULL) return;

        if (tail == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
    }

    void insertAtIndex(int idx, Node* node) {
        if (node == NULL) return;
        if (idx < 0 || idx > size) {
            cout << "Invalid Index" << endl;
            return;
        }

        if (idx == 0) {
            insertAtHead(node);
            return;
        }
        if (idx == size) {
            insertAtTail(node);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < idx - 1; i++) {
            temp = temp->next;
        }

        node->next = temp->next;
        node->prev = temp;
        temp->next->prev = node;
        temp->next = node;
        size++;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid Index" << endl;
            return;
        }

        Node* temp = head;

        if (index == 0) {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            else
                tail = NULL; // List becomes empty
            delete temp;
            size--;
            return;
        }

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp == tail) tail = temp->prev;

        delete temp;
        size--;
    }

    void display() {
        if (head == NULL) {
            cout << "Empty Linked List" << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void evenNum() {
        if (head == NULL) {
            cout << "Empty Linked List" << endl;
            return;
        }

        Node* temp = head;
        bool found = false;
        while (temp != NULL) {
            if (temp->val % 2 == 0) {
                cout << temp->val << " ";
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout << "No even numbers found.";
        cout << endl;
    }
};

int main() {
    LinkedList ll;
    int choice;

    do {
        cout << "\n\nEnter the choice against the following options: " << endl;
        cout << "1. Insert Node at Head" << endl;
        cout << "2. Insert Node at Tail" << endl;
        cout << "3. Insert Node at Index" << endl;
        cout << "4. Print Nodes having Even Numbers" << endl;
        cout << "5. Delete Node" << endl;
        cout << "6. Display Linked List" << endl;
        cout << "7. Exit\n" << endl;

        cin >> choice;
        int value, index;

        switch (choice) {
            case 1:
                cout << "Enter the value: ";
                cin >> value;
                ll.insertAtHead(new Node(value));
                break;

            case 2:
                cout << "Enter the value: ";
                cin >> value;
                ll.insertAtTail(new Node(value));
                break;

            case 3:
                cout << "Enter the index: ";
                cin >> index;
                cout << "Enter the value: ";
                cin >> value;
                ll.insertAtIndex(index, new Node(value));
                break;

            case 4:
                cout << "Nodes having even numbers: ";
                ll.evenNum();
                break;

            case 5:
                cout << "Enter the index to delete: ";
                cin >> index;
                ll.deleteNode(index);
                break;

            case 6:
                cout << "Linked List: ";
                ll.display();
                break;

            case 7:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}
