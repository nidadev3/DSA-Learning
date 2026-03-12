#include<iostream>
using namespace std;

void deleteAtEnd(int &size)
{
    size--;
}

int main()
{
    int arr[10] = {10,20,30,40,50};
    int size = 5;

    deleteAtEnd(size);

    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
}