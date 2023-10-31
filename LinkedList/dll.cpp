#include <iostream>
using namespace std;

class Node { 
public:
    int data;
    Node *next;
    Node *previous;
};

class List {
    Node *head, *temp;

public:
    List(){
        head = NULL;
        temp = NULL;
    };
    void create();
    void display();
    void insertAtStart(int value);
    void insertAtEnd(int value);
    void insertAtIntermediate(int position, int value);
    void deleteatstart();
    void deleteatend();
    void deleteatposition(int position);
    void deleteanelement(int value);
    void reverse();
    void concatenate(List &list2);
};


void List::create() {
    int num;
    cout << "Enter the number of nodes you want to create: ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int value;
        cout << "Enter value for node:" << i + 1 << ": ";
        cin >> value;

        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        newNode->previous = NULL;
        if (head == NULL){
            head = temp =  newNode;
        }
        else{
            temp->next = newNode;
            newNode->previous = temp;
            temp = newNode;
        }
    }
}

void List::display() {
    if (head == NULL){
        cout << "List is empty." << endl;
        return;
    }
    cout << "NULL" << " <-> ";
    temp = head;
    while (temp != NULL){
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void List::insertAtStart(int value) {
    Node* newNode = new Node;
    newNode->data = value;

    newNode->next = head;
    head->previous = newNode;
    head = newNode;
}

void List::insertAtEnd(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL){
        head = newNode;
    }
    else{
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void List::insertAtIntermediate(int position, int value) {
    Node *newNode = new Node;
    newNode->data = value;
    if (position <= 0)
    {
        insertAtStart(value);
        return;
    }
    
    temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)    {
        temp = temp->next;
    }
    
    if (temp == NULL)    {
        cout << "Position out of bounds." << endl;
        return;
    }
    newNode -> previous = temp;
    newNode -> next = temp -> next;
    temp ->next -> previous = newNode;
    temp -> next = newNode;
}

void List::deleteatstart() {
    temp = head;
    
    head = temp->next;
    temp->next->previous=NULL;
    delete (temp);
}

void List::deleteatend() {
    Node *q;
    temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    q = temp->next;
    temp->next = NULL;
    delete (q);
}

void List::deleteatposition(int position) {
    if (position == 0)
    {
        deleteatstart();
    }
    else
    {
        temp = head;
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
        temp->previous->next = temp->next;
        temp->next->previous=temp->previous;
        delete (temp);
    }
}

void List::deleteanelement(int value) {
    Node *q;
    temp = head;
    if (temp->data == value) // value found in first node
    {
        head = temp->next;
        delete temp;
    }
    else
    {
        while (temp != NULL) // search for the node
        {
            if (temp->next->data == value)
            {
                // Delete node next to temp
                q = temp->next;
                temp->next = q->next;
                delete q;
                return;
            }
            temp = temp->next;
        }
        cout << "Number not found in the list";
    }
}

void List::reverse() {
    Node *current = head;
    Node *temp = nullptr;

    while (current != nullptr) {
        temp = current->previous;
        current->previous = current->next;
        current->next = temp;

        current = current->previous;
    }

    if (temp != nullptr) {
        head = temp->previous;
    }
}

void List::concatenate(List &list2) {
    if (head == nullptr) {
        head = list2.head;
    } else {
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = list2.head;
        list2.head = nullptr;
    }
}


int main() {
    List list, list2;
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Create List\n";
        cout << "2. Display List\n";
        cout << "3. Insert at Start\n";
        cout << "4. Insert at End\n";
        cout << "5. Insert at Intermediate\n";
        cout << "6. Delete at Intermediate\n";
        cout << "7. Delete at start\n";
        cout << "8. Delete at end\n";
        cout << "9. Delete at Intermediate\n";
        cout << "10. Reverse List\n";
        cout << "11. Create second list\n";
        cout << "12. Concatenate lists\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.create();
            break;
        case 2:
            cout << "List elements: ";
            list.display();
            break;
        case 3:
        {
            int startValue;
            cout << "Enter value to insert at the start: ";
            cin >> startValue;
            list.insertAtStart(startValue);
            break;
        }
        case 4:
        {
            int endValue;
            cout << "Enter value to insert at the end: ";
            cin >> endValue;
            list.insertAtEnd(endValue);
            break;
        }
        case 5:
        {
            int position, intermediateValue;
            cout << "Enter position to insert at: ";
            cin >> position;
            cout << "Enter value to insert at position " << position << ": ";
            cin >> intermediateValue;
            list.insertAtIntermediate(position, intermediateValue);
            break;
        }
        case 6:
        {
            int position;
            cout << "Enter position to delete at: ";
            cin >> position;
            list.deleteatposition(position);
            break;
        }
        case 7:
        {
            list.deleteatstart();
            break;
        }
        case 8:
        {
            list.deleteatend();
            break;
        }
        case 9:
        {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteanelement(value);
            break;
        }
        case 10:
        {
            list.reverse();
            cout << "List reversed." << endl;
            break;
        }
        case 11:
        {
            list2.create();
            break;
        }
        case 12:
        {
            list.concatenate(list2);
            cout << "Concatenated list: ";
            list.display();
            break;
        }
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 13);

    return 0;
}
