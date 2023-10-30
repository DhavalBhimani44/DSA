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
    void search(int key);
    void sort();
    void concatenate(List& otherList);
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

void List::search(int key) {
    Node* temp = head;
    int position = 0;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Element " << key << " found at position " << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Element " << key << " not found in the list" << endl;
}

void List::sort() {
    if (head == nullptr) {
        cout << "List is empty, nothing to sort." << endl;
        return;
    }

    Node* current = head;
    Node* index = nullptr;
    int temp;

    while (current != nullptr) {
        index = current->next;

        while (index != nullptr) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }

    cout << "List sorted in ascending order." << endl;
}

void List::concatenate(List& otherList) {
    if (otherList.head == nullptr) {
        cout << "The second list is empty, nothing to concatenate." << endl;
        return;
    }

    if (head == nullptr) {
        head = otherList.head;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = otherList.head;
    }
    otherList.head = nullptr;
    cout << "Lists concatenated successfully." << endl;
}

// void List::removeDuplicates() {
//     if (head == nullptr) {
//         cout << "List is empty, nothing to remove." << endl;
//         return;
//     }

//     Node* current = head;
//     while (current != nullptr) {
//         Node* runner = current;
//         while (runner->next != nullptr) {
//             if (runner->next->data == current->data) {
//                 Node* duplicate = runner->next;
//                 runner->next = runner->next->next;
//                 delete duplicate;
//             } else {
//                 runner = runner->next;
//             }
//         }
//         current = current->next;
//     }

//     cout << "Duplicates removed from the list." << endl;
// }


int main() {
    int p = 1, ch;
    List list1, list2;

    while (p == 1) { 
        cout << "\nChoose an option: \n1) Create List \n2) Display \n3) Insert at Head \n4) Insert at End \n5) Insert at Intermediate \n6) Delete at position \n7) Reversing a linked list \n8) Delete at Head \n9) Delete at End \n10) Length of a list \n11) Search \n12) Sort \n13) Concatenate Lists \n14) Create second list \n" << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            list1.create();
            break;
        case 2:
            list1.display();
            break;
        case 3: {
            int data;
            cout << "Enter the data to insert at the head: ";
            cin >> data;
            list1.insertAtHead(data);
            break;
        }
        case 4: {
            int data;
            cout << "Enter the data to insert at the end: ";
            cin >> data;
            list1.insertAtEnd(data);
            break;
        }
        case 5: {
            int data, position;
            cout << "Enter the data to insert: ";
            cin >> data;
            cout << "Enter the position to insert at: ";
            cin >> position;
            list1.insertAtIntermediate(data, position);
            break;
        }
        case 6: {
            int position;
            cout << "Enter the position to delete at: ";
            cin >> position;
            list1.deleteAtPosition(position);
            break;
        }
        case 7: {
            list1.reverse();
            cout << "Linked list reversed!" << endl;
            break;
        }
        case 8: {
            list1.deleteAtHead();
            cout << "Deleted at the head!" << endl;
            break;
        }
        case 9: {
            list1.deleteAtEnd();
            cout << "Deleted at the end!" << endl;
            break;
        }
        case 10: {
            cout << "Length of the linked list: " << list1.length() << endl;
            break;
        }
        case 11: {
            int key;
            cout << "Enter the element to search for: ";
            cin >> key;
            list1.search(key);
            break;
        }
        case 12: {
            list1.sort();
            break;
        }
        case 13: {
            cout << "Concatenating List 2 to List 1:" << endl;
            list1.concatenate(list2);
            break;
        }
        case 14:{
            list2.create();
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