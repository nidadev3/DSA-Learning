#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};


Node *addAtBeginning(struct Node* head, int value){
    Node* newNode=new Node();
    newNode->data=value;
    newNode->link=head;
    head=newNode;
    return head;
}
int main (){
    
    Node* head=nullptr;
    head=addAtBeginning(head,10);
    head=addAtBeginning(head,20);
    head=addAtBeginning(head,30);
    Node* temp=head;
    while(temp!=nullptr){
        cout<<"Node Data: "<<temp->data<<endl;
        temp=temp->link;
    }

}