// #include<stdio.h>
//  #include <stdlib.h>
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
// #include <stdio.h>
// #include <stdlib.h>

// int main() {

//    int n;
//    printf("Enter number of elemnets:");
//    scanf("%d",&n);
//    int *arr=(int*) malloc(n*sizeof(int));
//    for(int i=0;i<n;i++){
//     arr[i]=i*i;
//    }
//    for (int i=0;i<n;i++){
//     printf("%d ",arr[i]);}
//         free(arr);
//     return 0;
// }

//Calloc Example 
// #include <stdio.h>
// #include <stdlib.h>
// int main(){
//     int n;
//     printf("Enter number of elemnets:");
//     scanf("%d",&n);
//     int *arr=(int*) calloc(n,sizeof(int));
    
//     for (int i=0;i<n;i++){
//      printf("%d ",arr[i]);}
//          free(arr);
//      return 0;  
// }

// realloc example
#include <stdio.h>
#include <stdlib.h>

/* -------- Function Prototypes -------- */
int* addNumber(int *arr, int *size, int *count, int value);
void display(int *arr, int count);
void statistics(int *arr, int count);
void searchNumber(int *arr, int count, int key);

/* -------- Main Function -------- */
int main() {

    int *arr = NULL;
    int size = 2;
    int count = 0;
    int n;

    arr = (int*) malloc(size * sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter numbers (-1 to stop):\n");

    while(1){
        if(scanf("%d", &n) != 1){
            printf("Invalid input\n");
            break;
        }

        if(n == -1)
            break;

        arr = addNumber(arr, &size, &count, n);
    }

    display(arr, count);
    statistics(arr, count);

    if(count > 0){
        int key;
        printf("\nEnter number to search: ");
        scanf("%d", &key);
        searchNumber(arr, count, key);
    }

    free(arr);
    return 0;
}

/* -------- Add Number (Dynamic Resize) -------- */
int* addNumber(int *arr, int *size, int *count, int value){

    if(*count == *size){
        *size *= 2;

        int *temp = realloc(arr, (*size) * sizeof(int));
        if(temp == NULL){
            printf("Memory reallocation failed\n");
            free(arr);
            exit(1);
        }
        arr = temp;
    }

    arr[*count] = value;
    (*count)++;

    return arr;
}

/* -------- Display Array -------- */
void display(int *arr, int count){
    printf("\nNumbers entered: ");
    for(int i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* -------- Statistics -------- */
void statistics(int *arr, int count){

    if(count == 0){
        printf("No data available.\n");
        return;
    }

    int sum = 0;
    int max = arr[0];
    int min = arr[0];

    for(int i = 0; i < count; i++){
        sum += arr[i];

        if(arr[i] > max)
            max = arr[i];

        if(arr[i] < min)
            min = arr[i];
    }

    float avg = (float)sum / count;

    printf("\n--- Statistics ---\n");
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", avg);
    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);
}

/* -------- Search Function -------- */
void searchNumber(int *arr, int count, int key){

    for(int i = 0; i < count; i++){
        if(arr[i] == key){
            printf("Number found at index %d\n", i);
            return;
        }
    }

    printf("Number not found\n");
}