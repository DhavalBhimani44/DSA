#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class List {
    Node* head;

    public:
        List() {
            head = NULL;
        }

        void create();
        void display();
        void insertAtHead(int x);
        void insertAtEnd(int x);
        void insertAtIntermediate(int x, int position);
        void deleteAtHead();
        void deleteAtEnd();
        void deleteAtPosition(int position);
        void reverse();
        int length();
};

void List::create() {
    int n, x;
    cout << "Enter the total number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter the data: ";
        cin >> x;

        Node* newnode = new Node;
        newnode->data = x;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void List::display() {
    Node* temp = head;
    cout << "\nLinked List elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displayRecursive(Node* current) {
    if (current == nullptr) {
        cout << endl;
        return;
    }
    
    cout << current->data << " ";
    displayRecursive(current->next);
}

void List::insertAtHead(int x) {
    Node* newnode = new Node;
    newnode->data = x;
    newnode->next = head;
    head = newnode;
}

void List::insertAtEnd(int x) {
    Node* newnode = new Node;
    newnode->data = x;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void List::insertAtIntermediate(int x, int position) {
    if (position < 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* newnode = new Node;
    newnode->data = x;

    if (position == 0) {
        newnode->next = head;
        head = newnode;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void List::deleteAtHead(){
    if(head==nullptr){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void List::deleteAtPosition(int position) {
    if (position < 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    for (int i = 0; i < position; i++) {
        if (temp == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}

void List::deleteAtEnd(){
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    if(head->next==nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while(temp->next!=nullptr){
        prev = temp;
        temp = temp->next;
    }

    delete temp;
    prev->next = nullptr;
}

void List::reverse() {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

int List::length() {
    int count = 0;
    Node* temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}


int main() {
    int p = 1, ch;
    List l;

    while (p == 1) { 
        cout << "\nChoose an option: \n1) Create \n2) Display \n3) Insert at Head \n4) Insert at End \n5) Insert at Intermediate \n6) Delete at position \n7) Reversing a linked list \n8) Delete at Head \n9) Delete at End \n10) Length of a list \n" << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            l.create();
            break;
        case 2:
            l.display();
            break;
        case 3: {
            int data;
            cout << "Enter the data to insert at the head: ";
            cin >> data;
            l.insertAtHead(data);
            break;
        }
        case 4: {
            int data;
            cout << "Enter the data to insert at the end: ";
            cin >> data;
            l.insertAtEnd(data);
            break;
        }
        case 5: {
            int data, position;
            cout << "Enter the data to insert: ";
            cin >> data;
            cout << "Enter the position to insert at: ";
            cin >> position;
            l.insertAtIntermediate(data, position);
            break;
        }
        case 6: {
            int position;
            cout << "Enter the position to delete at: ";
            cin >> position;
            l.deleteAtPosition(position);
            break;
        }
        case 7: {
            l.reverse();
            cout << "Linked list reversed!" << endl;
            break;
        }
        case 8: {
            l.deleteAtHead();
            cout << "Deleted at the head!" << endl;
            break;
        }
        case 9: {
            l.deleteAtEnd();
            cout << "Deleted at the end!" << endl;
            break;
        }

        case 10: {
            cout << "Length of the linked list: " << l.length() << endl;
            break;
        }

        default:
            cout << "Invalid choice!" << endl;
            break;
        }

        cout << "\nPress 1 to continue or any other number to exit: ";
        cin >> p;
    }

    return 0;
}