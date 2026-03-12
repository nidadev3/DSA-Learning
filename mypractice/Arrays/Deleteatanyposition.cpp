#include<iostream>
using namespace std;

void deleteAtPos(int arr[], int &size, int pos)
{
    for(int i = pos+1; i < size; i++)
    {
        arr[i-1] = arr[i];
    }

    size--;
}

int main()
{
    int arr[10] = {10,20,30,40,50};
    int size = 5;

    deleteAtPos(arr,size,2);

    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
}