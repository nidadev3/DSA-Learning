// #include <iostream>
// using namespace std;

// void addAtStart(int arr[], int &n, int x){
   
//     for(int i = n-1; i >= 0; i--){
//         arr[i+1] = arr[i];
//     }
    
//     arr[0] = x;

  
//     n++;
// }

// int main(){
//     int arr[100] = {1,2,3,4,5};
//     int n = 5;
//     int x = 0;

//     addAtStart(arr, n, x);

//     for(int i=0; i<n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }


//when array is full

#include <iostream>
using namespace std;

void addAtStart(int* &arr, int &size, int &capacity, int value) {
    // Check if array is full
    if(size == capacity) {
        int newCapacity = capacity * 2;         // double the capacity
        int* newArr = new int[newCapacity];     // allocate new array

        // Copy old elements shifted by 1 to make space at index 0
        for(int i = 0; i < size; i++) {
            newArr[i+1] = arr[i];
        }

        // Insert new element at start
        newArr[0] = value;

        // Delete old array
        delete[] arr;

        // Update pointer and capacity
        arr = newArr;
        capacity = newCapacity;
        size++;   // increase size
    }
    else {
        // If not full, just shift in original array
        for(int i = size-1; i >= 0; i--) {
            arr[i+1] = arr[i];
        }
        arr[0] = value;
        size++;
    }
}

int main() {
    int capacity = 5;
    int size = 5;

    // Initial array is full
    int* arr = new int[capacity]{10, 20, 30, 40, 50};

    int value = 5;

    addAtStart(arr, size, capacity, value);

    cout << "Array after insertion at start:\n";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Free memory
    delete[] arr;

    return 0;
}
