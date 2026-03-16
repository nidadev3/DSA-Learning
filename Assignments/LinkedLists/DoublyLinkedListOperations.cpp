#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Creation of DLL
void creation(Node*& head) {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* temp = nullptr;

    for(int i = 0; i < n; i++) {
        Node* newnode = new Node();
        cout << "Enter value of node " << i+1 << ": ";
        cin >> newnode->data;
        newnode->next = nullptr;
        newnode->prev = nullptr;

        if(head == nullptr) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}

// Insert at head
void insertAtHead(Node*& head, int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->prev = nullptr;
    newnode->next = head;

    if(head != nullptr)
        head->prev = newnode;

    head = newnode;
    cout << "Node inserted at head." << endl;
}

// Insert at end
void insertAtEnd(Node*& head, int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->next = nullptr;
    newnode->prev = nullptr;

    if(head == nullptr) {
        head = newnode;
        cout << "Node inserted at end." << endl;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;

    cout << "Node inserted at end." << endl;
}

// Insert at position
void insertAtPosition(Node*& head, int value, int pos) {
    if(pos == 1) {
        insertAtHead(head, value);
        return;
    }

    Node* temp = head;
    for(int i = 1; i < pos-1; i++) {
        if(temp == nullptr) {
            cout << "Position out of range." << endl;
            return;
        }
        temp = temp->next;
    }

    Node* newnode = new Node();
    newnode->data = value;

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != nullptr)
        temp->next->prev = newnode;

    temp->next = newnode;

    cout << "Node inserted at position " << pos << "." << endl;
}

// Update first node
void updateFirstNode(Node* head, int value) {
    if(head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    head->data = value;
    cout << "First node updated." << endl;
}

// Update last node
void updateLastNode(Node* head, int value) {
    if(head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr)
        temp = temp->next;

    temp->data = value;
    cout << "Last node updated." << endl;
}

// Update at position
void updateAtPosition(Node* head, int pos, int value) {
    Node* temp = head;
    for(int i = 1; i < pos; i++) {
        if(temp == nullptr) {
            cout << "Position out of range." << endl;
            return;
        }
        temp = temp->next;
    }
    temp->data = value;
    cout << "Node updated at position " << pos << "." << endl;
}

// Delete head
void deleteHead(Node*& head) {
    if(head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    if(head != nullptr)
        head->prev = nullptr;

    delete temp;
    cout << "Head node deleted." << endl;
}

// Delete end
void deleteEnd(Node*& head) {
    if(head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if(head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Last node deleted." << endl;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr)
        temp = temp->next;

    temp->prev->next = nullptr;
    delete temp;

    cout << "Last node deleted." << endl;
}

// Delete at position
void deleteAtPosition(Node*& head, int pos) {
    if(pos == 1) {
        deleteHead(head);
        return;
    }

    Node* temp = head;
    for(int i = 1; i < pos; i++) {
        if(temp == nullptr) {
            cout << "Position out of range." << endl;
            return;
        }
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    if(temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "Node deleted at position " << pos << "." << endl;
}

// Display list
void display(Node* head) {
    if(head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main
int main() {
    Node* head = nullptr;
    int value, pos;

    creation(head);
    cout << "Doubly Linked List: ";
    display(head);

    cout << "Insert at head: ";
    cin >> value;
    insertAtHead(head,value);
    display(head);

    cout << "Insert at end: ";
    cin >> value;
    insertAtEnd(head,value);
    display(head);

    cout << "Insert at position (value pos): ";
    cin >> value >> pos;
    insertAtPosition(head,value,pos);
    display(head);

    cout << "Update first node: ";
    cin >> value;
    updateFirstNode(head,value);
    display(head);

    cout << "Update last node: ";
    cin >> value;
    updateLastNode(head,value);
    display(head);

    cout << "Update at position (pos value): ";
    cin >> pos >> value;
    updateAtPosition(head,pos,value);
    display(head);

    cout << "Delete head..." << endl;
    deleteHead(head);
    display(head);

    cout << "Delete end..." << endl;
    deleteEnd(head);
    display(head);

    cout << "Delete at position: ";
    cin >> pos;
    deleteAtPosition(head,pos);
    display(head);

    return 0;
}