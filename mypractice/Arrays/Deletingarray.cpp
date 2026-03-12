#include<iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int size = 5;

    // Deleting a static array is not possible
    // Instead, just make size = 0
    size = 0;

    cout << "Array deleted logically, size = " << size << endl;

    return 0;
}