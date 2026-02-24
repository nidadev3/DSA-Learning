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
//Malloc and free example
#include <stdio.h>
#include <stdlib.h>

int main() {

   int n;
   printf("Enter number of elemnets:");
   scanf("%d",&n);
   int *arr=(int*) malloc(n*sizeof(int));
   for(int i=0;i<n;i++){
    arr[i]=i*i;
   }
   for (int i=0;i<n;i++){
    printf("%d ",arr[i]);}
        free(arr);
    return 0;
}