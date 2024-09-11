#include <stdio.h>
int main(){
    int a,b,c;
    int *p;
    a= 10;
    b=20;
    c=30;
    p=&a;
    printf("%d \n" , *p);
    p=&b;
    printf("%d \n" , *p);
    p=&c;
    printf("%d \n" , *p);
}