#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class List
{
    Node *head, *temp;

public:
    List();
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

List::List(){
    head = NULL;
    temp = NULL;
}

void List::create(){
    int num;
    cout << "Enter the number of nodes you want to create: ";
    cin >> num;

    for (int i = 0; i < num; i++){
        int value;
        cout << "Enter value for node:" << i + 1 << ": ";
        cin >> value;

        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL){
            head = newNode;
            temp = newNode;
            newNode->next = head;
        }
        else{
            temp->next = newNode;
            newNode->next = head;
            temp = temp->next;
        }
    }
}

void List::display(){
    if (head == NULL){
        cout << "List is empty." << endl;
        return;
    }
    temp = head;
    while (temp->next != head){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout <<temp->data<< " -> ";
    cout <<"END"<< endl;
}

void List::insertAtStart(int value){
    Node *newNode = new Node;
    newNode->data = value;

    newNode->next=head;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    head=newNode;
}

void List::insertAtEnd(int value){
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;

    if (head == NULL){
        head = newNode;
    }
    else{
        temp = head;
        while (temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void List::insertAtIntermediate(int position, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    if (position <= 0)
    {
        insertAtStart(value);
        return;
    }
    temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    // If temp outside the len of list.
    if (temp == NULL)
    {
        cout << "Position out of bounds." << endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void List::deleteatstart()
{
    Node*q;
    q = temp = head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    head = q->next;
    temp->next=head;
    delete (q);
}

void List::deleteatend()
{
    Node *q;
    temp = head;
    while ((temp->next)->next != head)
    {
        temp = temp->next;
    }
    q = temp->next;
    temp->next = head;
    delete (q);
}

void List::deleteatposition(int position)
{
    if (position == 0)
    {
        deleteatstart();
    }
    else
    {
        Node *q;
        temp = head;
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        q = temp->next;
        temp->next = q->next;
        delete (q);
    }
}
void List::deleteanelement(int value)
{
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

void List::reverse()
{
    Node *forward, *curr, *back;
    forward = head;
    curr = NULL;

    while (forward->next != head)
    {
        back = curr;
        curr = forward;
        forward = forward->next;
        curr->next = back;
    }
    back = curr;
    curr = forward;
    forward = forward->next;
    curr->next = back;
    head = curr;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
}

void List::concatenate(List& list2)
{
    if (head == NULL)
    {
        head = list2.head;
    }
    else if (list2.head != NULL)
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = list2.head;
        temp = list2.temp;
        while (temp->next != list2.head)
        {
            temp = temp->next;
        }
        temp->next = head;
    }

    // Set list2 to an empty list
    list2.head = NULL;
    list2.temp = NULL;
}


int main()
{
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
        cout << "9. Delete any particular node\n";
        cout << "10. Reverse\n";
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
            list.display();
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
            cout << "Concatenated List: ";
            list.display();
            break;
        }
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 13);

    return 0;
}
