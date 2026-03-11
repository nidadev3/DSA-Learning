#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* link;
};
void deletefirstNode(Node* &head){
  if(head==nullptr){
    cout<<"List is empty, nothing to delete."<<endl;
    return;
  }
  Node* temp=head;
  head=head->link;
  delete temp;

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

    deletefirstNode(head);

    cout<<"List after deleting first node: ";
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->link;
    }
    cout<<endl;
}