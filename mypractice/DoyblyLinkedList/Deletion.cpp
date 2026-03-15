#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

//method 1
void deletefromhead(Node* &head)
{
    if(head == NULL)
        return;

    Node* temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    delete temp;
}

//method 2
void deleteFromHead(Node* &head)
{
    if(head == NULL)
        return;

    head = head->next;

    if(head != NULL)
    {
        delete head->prev;
        head->prev = NULL;
    }
}

//display function
void display(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    //creating list: 10 <-> 20 <-> 30
    Node* head = new Node{10,NULL,NULL};
    Node* second = new Node{20,NULL,NULL};
    Node* third = new Node{30,NULL,NULL};

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    cout<<"Original List: ";
    display(head);

    cout<<"After deletefromhead(): ";
    deletefromhead(head);
    display(head);

    cout<<"After deleteFromHead(): ";
    deleteFromHead(head);
    display(head);

    return 0;
}