#include<iostream>
using namespace std; 
int main (){
    int arr[100];
    int n;
    cout<<"Enter the size of array :";
    cin>>n;
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
      sum=sum+arr[i];
      
    }
      cout<<"The sum of elements in array is:"<<sum;
}