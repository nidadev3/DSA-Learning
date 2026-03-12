// #include<iostream>
// using namespace std;

// int main() {
//     int arr[5] = {10, 20, 30, 40, 50};
//     int size = 5;

//     // Deleting a static array is not possible
//     // Instead, just make size = 0
//     size = 0;

//     cout << "Array deleted logically, size = " << size << endl;

//     return 0;
// }

//dynamic array 
#include<iostream>
using namespace std;

int main() {
    int size = 5;
    int* arr = new int[size]{10,20,30,40,50};

    // Print array before deletion
    cout << "Array before deletion: ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;

    // Delete the whole array
    delete[] arr;
    arr = nullptr;  // avoid dangling pointer

    cout << "Array deleted completely!" << endl;

    return 0;
}