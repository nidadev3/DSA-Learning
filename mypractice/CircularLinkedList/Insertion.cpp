#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void insertatstart(Node *&head,int value){
    Node* newnode=new Node();
    newnode->data=value;
    newnode->next=nullptr;
      if(head == nullptr) 
    {
        newNode->next = newNode;
        return newNode;
    }

    Node* tail = head;
    while(tail->next != head)
        tail = tail->next;

    newNode->next = head;
    tail->next = newNode;
    head = newNode; 
}
