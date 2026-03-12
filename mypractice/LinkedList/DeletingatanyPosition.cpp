#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *link;
};
Node* deleteatposition(Node* head,int position){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return head;
    }
    if(position==1){
        Node* temp=head;
        head=head->link;
        delete temp;
        return head;
    }
    Node* temp=head;
    for(int i=1;i<position-1 && temp!=nullptr;i++){
        temp=temp->link;
    }
    if(temp==nullptr || temp->link==nullptr){
        cout<<"Position out of bounds"<<endl;
        return head;
    }
    Node* nodetodelete=temp->link;
    temp->link=nodetodelete->link;
    delete nodetodelete;
    return head;
}
int main(){
    Node* head=nullptr;
    // Creating a linked list with some nodes
    head=new Node();
    head->data=10;
    head->link=new Node();
    head->link->data=20;
    head->link->link=new Node();
    head->link->link->data=30;
    head->link->link->link=nullptr;

    cout<<"Original List: ";
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;

   head= deleteatposition(head,2);

    cout<<"List after deleting node at position 2: ";
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;
}