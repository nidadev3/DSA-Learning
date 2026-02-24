// #include<stdio.h>
// #include <stdlib.h>
// memory management in c
// void demo() {
//     int normal = 0;       // normal local variable
//     static int saved = 0; // static variable

//     normal++;  // increments every call, but resets
//     saved++;   // increments every call, remembers old value

//     printf("Normal: %d, Static: %d\n", normal, saved);
// }

// int main() {
//     printf("Calling demo() first time:\n");
//     demo();

//     printf("Calling demo() second time:\n");
//     demo();

//     printf("Calling demo() third time:\n");
//     demo();

//     return 0;
//}
//Function with stack variables
// void showFunctionVariables() {
//     int a = 20;   // local (stack) variable
//     int b = 30;   // local (stack) variable

//     printf("\nInside function:\n");
//     printf("Value of a = %d\n", a);
//     printf("Value of b = %d\n", b);

//     printf("Address of a = %p\n", (void*)&a);
//     printf("Address of b = %p\n", (void*)&b);
// }

// int main() {
//     // Stack variables in main
//     int x = 5;
//     int y = 10;

//     printf("Inside main:\n");
//     printf("Value of x = %d\n", x);
//     printf("Value of y = %d\n", y);

//     printf("Address of x = %p\n", (void*)&x);
//     printf("Address of y = %p\n", (void*)&y);

//     // Call function
//     showFunctionVariables();

//     return 0;
// }
//Heap 
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Heap variable
    int *ptr = (int*)malloc(sizeof(int));

    if(ptr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    *ptr = 42;
    printf("Value at ptr: %d\n", *ptr);

    // Heap array
    int *arr = (int*)malloc(5 * sizeof(int));

    if(arr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    for(int i = 0; i < 5; i++){
        arr[i] = i + 1;
    }

    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }

    free(ptr);
    free(arr);

    return 0;
}