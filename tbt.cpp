#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool lThread;
    bool rThread;

    Node(int val) {
        data = val;
        left = right = NULL;
        lThread = rThread = false;
    }
};

class TBT {
private:
    Node* root;

public:
    TBT() {
        root = NULL;
    }

    // Insert a node
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = NULL;

        while (current != NULL) {
            parent = current;
            if (val < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (val < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    // Create preorder threads
    void createPreorderThread(Node* node, Node*& prev) {
        if (node == NULL) return;

        if (node->left == NULL) {
            node->left = prev;
            node->lThread = true;
        }

        if (prev != NULL && prev->right == NULL) {
            prev->right = node;
            prev->rThread = true;
        }

        prev = node;

        if (!node->lThread) createPreorderThread(node->left, prev);
        if (!node->rThread) createPreorderThread(node->right, prev);
    }

    void createThreads() {
        Node* prev = NULL;
        createPreorderThread(root, prev);
    }

    // Preorder traversal using threads
    void preorderTraversal() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }

        Node* curr = root;
        cout << "Preorder Traversal: ";
        while (curr != NULL) {
            cout << curr->data << " ";

            if (!curr->lThread) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        cout << endl;
    }
};

int main() {
    TBT tree;
    int choice, val;

    while (true) {
        cout << "\n1. Insert Node\n2. Create Threads\n3. Preorder Traversal\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                tree.insert(val);
                cout << "Node inserted.\n";
                break;
            case 2:
                tree.createThreads();
                cout << "Threads created.\n";
                break;
            case 3:
                tree.preorderTraversal();
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
