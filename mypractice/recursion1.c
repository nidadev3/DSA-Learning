#include<stdio.h>
#include<stdlib.h>
// int main (){
//     int a=3;
//     a=inc(inc(a));
//     printf("%d",a);
// }
// int inc(int x){
//     return x+1;
// }
// void B(int b){
//     printf("%d\n",b);
// }
// void A(int a ){
//     B(a*2);
//     printf("%d\n",a);
// }
// int main(){
//     A(5);
// }
// void f(int n){
//     if (n==0)
//         return;
//     printf("%d\n",n);
//     f(n-1);
// }
// int main(){
//     f(3);
// }

//  int sum(int n ){
//     if (n==0)
//         return 0;
//     return n + sum(n-1);
//  }
//  int main (){
//     printf("%d\n",sum(4));
//  }


int f(int n){
   if (n<=1)
        return 1;
   return f(n-1)+f(n-2);
}
int main (){
   printf("%d\n",f(4));
}