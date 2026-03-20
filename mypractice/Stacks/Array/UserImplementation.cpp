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