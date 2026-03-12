// #include<iostream>
// using namespace std;
// void addatanyposition(int arr[], int &size, int capacity, int pos, int value)
// {
//     if(size < capacity)
//     {
//         for(int i = size - 1; i >= pos; i--)
//         {
//             arr[i + 1] = arr[i];
//         }

//         arr[pos] = value;
//         size++;
//     }
// }
// int main (){
//     int capacity=10;
//     int arr[capacity]={1,2,3,4,5,6};
//     int size=6;
//     int pos=4;
//     int value=79;
//     addatanyposition(arr,size,capacity,pos,value);
//     cout<<"Array after insertion";
//     for(int i=0;i<size;i++){
//         cout<<arr[i]<<" ";
//     }
// }


//when array is full


#include<iostream>
using namespace std;

void insertAtPos(int* &arr, int &size, int &capacity, int value, int pos)
{
    if(size == capacity)
    {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];

        for(int i=0;i<pos;i++)
            newArr[i] = arr[i];

        newArr[pos] = value;

        for(int i=pos;i<size;i++)
            newArr[i+1] = arr[i];

        delete[] arr;

        arr = newArr;
        capacity = newCapacity;
        size++;
    }
}

int main()
{
    int capacity = 5;
    int size = 5;

    int* arr = new int[capacity]{10,20,30,40,50};

    insertAtPos(arr,size,capacity,25,2);

    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";

    delete[] arr;
}