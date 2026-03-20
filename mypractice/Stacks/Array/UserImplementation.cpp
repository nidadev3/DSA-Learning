#include<iostream>
using namespace std;

class stack{
    private:
    int* arr;
    int capacity;
    int top;
    public:
    stack(int capacity){
        this.capcacity=capacity;
        arr=new int[capacity];
        top=-1
    }
    //isFull function
    bool isFull(){
if(top==capcity-1){
    cout<<"Stack is overflow"<<endl;
    return 1;
}
else{
    return 0;
}

    }
    //isEmpty Function
    bool isEmpty(){
        if (top==-1){
            cout<<"Stack is empty"<<endl;
            return 1;
        }
        else{
            return 0;
        }
    }
    
}
int main (){
    int choice, int data;
    while(1){
        cout<<"1-Perform push operation";
        cout<<"2-Perform pop operation";
        cout<<"3-Print the element at the top";
        cout<<"4-Print all elements in the stack";
        cout<<"5-Exit";
        cout<<"Enter you choice:";
        cin>>choice;
    }
}