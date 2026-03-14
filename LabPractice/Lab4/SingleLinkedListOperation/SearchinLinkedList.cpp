#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};

int main() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number should be 1 or greater.";
        return 0;
    }

    Node* head = nullptr;
    Node* temp = nullptr;

    for (int i = 0; i < n; i++) {
        Node* newnode = new Node();

        cout << "Enter the data for node " << i + 1 << ": ";
        cin >> newnode->data;

        newnode->link = nullptr;

        if (head == nullptr) {
            head = newnode;
            temp = newnode;
        } else {
            temp->link = newnode;
            temp = newnode;
        }
    }

    int value;
    cout << "Enter the value to search: ";
    cin >> value;

    Node* ptr = head;
    bool found = false;

    while (ptr != nullptr) {
        if (value == ptr->data) {
            found = true;
            break;
        }
        ptr = ptr->link;
    }

    if (found) {
        cout << "Value found";
    } else {
        cout << "Value not found";
    }

    return 0;
}