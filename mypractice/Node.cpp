#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
int main (){
Node Node1;
Node1.data=10;
Node1.next=nullptr;
cout<<"Node Data: "<<Node1.data<<endl;
cout<<"Address of Node: "<<&Node1<<endl;
cout<<"Node Next: "<<Node1.next<<endl;
return 0;
}