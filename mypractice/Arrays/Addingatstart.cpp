#include <iostream>
using namespace std;

void addAtStart(int arr[], int &n, int x){
   
    for(int i = n-1; i >= 0; i--){
        arr[i+1] = arr[i];
    }
    
    arr[0] = x;

  
    n++;
}

int main(){
    int arr[100] = {1,2,3,4,5};
    int n = 5;
    int x = 0;

    addAtStart(arr, n, x);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
