#include<iostream>
using namespace std;
void deletefronstart(int arr[],int &size ){
    for(int i=1 ; i<size;i++){
        arr[i-1]=arr[i];

    }
    size--;
}
int main (){
    int arr[10]={1,2,3,5,4};
    int size=5;
    deletefronstart(arr, size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}