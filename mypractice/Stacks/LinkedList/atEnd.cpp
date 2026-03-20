#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
    Node* head;

public:
    Stack() {
        head = NULL;
    }

    // PUSH at end
    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << x << " pushed\n";
    }

    // POP from end
    void pop() {
        if (head == NULL) {
            cout << "Stack Underflow\n";
            return;
        }

        // Only one node
        if (head->next == NULL) {
            cout << head->data << " popped\n";
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        cout << temp->data << " popped\n";
        prev->next = NULL;
        delete temp;
    }

    // DISPLAY
    void display() {
        if (head == NULL) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // PEEK (last element)
    void peek() {
        if (head == NULL) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        cout << "Top element: " << temp->data << endl;
    }
};

int main() {
    Stack s;

    s.push(5);
    s.push(10);
    s.push(15);

    s.display();

    s.pop();
    s.display();

    s.peek();

    return 0;
}