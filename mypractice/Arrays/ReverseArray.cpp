#include <iostream>
using namespace std;

void reverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while(start < end)
    {
        // Swap elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "Original Array: ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;

    reverseArray(arr, size);

    cout << "Reversed Array: ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}