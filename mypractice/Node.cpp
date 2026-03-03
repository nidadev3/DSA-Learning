#include<iostream>
using namespace std;

//Node in Stack
// struct Node{
//     int data;
//     Node *next;
// };
// int main (){
// Node Node1;
// Node1.data=10;
// Node1.next=nullptr;
// cout<<"Node Data: "<<Node1.data<<endl;
// cout<<"Address of Node: "<<&Node1<<endl;
// cout<<"Node Next: "<<Node1.next<<endl;
// return 0;
// }

//Node in Heap
struct Node{
    int data;
    Node *next;
};
int main(){
    Node *Node1=new Node();
    Node1->data=10;
    Node1->next=nullptr;
    cout<<"Node Data: "<<Node1->data<<endl;
    cout<<"Address of Node: "<<Node1<<endl;
    cout<<"Node Next: "<<Node1->next<<endl;
    delete Node1;
    return 0;
}