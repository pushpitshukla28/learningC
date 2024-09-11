#include <stdio.h>
int main(){
    int a,b;
    int *p;
    int *q = &b;
    p = &a;
    printf("Enter two numbers\n");
    scanf("%d%d", p , q);
    int res;
    res = *p+*q;
    printf("The addition is: %d \n" , res);

}