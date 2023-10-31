#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* insertwithoutrecursion(Node* root, int data) {
    Node* newNode = new Node(data);

    if (root == NULL) {
        return newNode;
    }

    Node* current = root;
    Node* parent = NULL;

    while (current != NULL) {
        parent = current;

        if (data <= current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    if (data <= parent->data) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void deletion(Node*& root, int key) {
    if (root == NULL) {
        cout << "Number not found";
        return;
    }

    if (key < root->data) {
        deletion(root->left, key);
    }
    else if (key > root->data) {
        deletion(root->right, key); 
    }
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp; 
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            // Node with two children: Find the inorder successor (smallest in the right subtree)
            Node* temp = findMin(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            deletion(root->right, temp->data);
        }
    }
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    
    if (key < root->data) {
        return search(root->left, key);
    }
    
    return search(root->right, key);
}

int main() {
    int x, choice, data;
    Node* root = NULL;
    Node* result = NULL;

    cout << "Binary Search Tree Menu:" << endl;
    cout << "1. Insert an element" << endl;
    cout << "2. Inorder Traversal" << endl;
    cout << "3. Preorder Traversal" << endl;
    cout << "4. Postorder Traversal" << endl;
    cout << "5. Delete a node" << endl;
    cout << "6. Search for a node" << endl;
    cout << "7. Quit" << endl;

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "How many nodes do you want in BST: ";
            cin >> x;
            cout << "Enter the data: ";
            for (int i = 0; i < x; i++) {
                cin >> data;
                root = insertwithoutrecursion(root, data);
            }
            break;
        case 2:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;
        case 5:
            int x;
            cout << "Enter the node value you want to delete: ";
            cin >> x;
            deletion(root, x);
            cout << "Deleted the node!" << endl;
            break;
        case 6:
            int searchValue;
            cout << "Enter the value to search: ";
            cin >> searchValue;
            result = search(root, searchValue);
            if (result) {
                cout << "Found " << searchValue << " in the tree." << endl;
            }
            else {
                cout << searchValue << " not found in the tree." << endl;
            }
            break;
        case 7:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 7);

    return 0;
}
