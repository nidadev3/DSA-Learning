#include<iostream>
using namespace std;
void addatanyposition(int arr[], int &size, int capacity, int pos, int value)
{
    if(size < capacity)
    {
        for(int i = size - 1; i >= pos; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[pos] = value;
        size++;
    }
}
int main (){
    int capacity=10;
    int arr[capacity]={1,2,3,4,5,6};
    int size=6;
    int pos=4;
    int value=79;
    addatanyposition(arr,size,capacity,pos,value);
    cout<<"Array after insertion";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}