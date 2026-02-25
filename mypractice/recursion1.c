#include<stdio.h>
#include<stdlib.h>
int main (){
    int a=3;
    a=inc(inc(a));
    printf("%d",a);
}
int inc(int x){
    return x+1;
}
