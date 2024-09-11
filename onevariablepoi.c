#include <stdio.h>
int main(){
    int a;
    int *p , *q;
    a= 10;
    p=&a;
    printf("%d \n" , *p);
    q=&a;
    printf("%d\n" , *q);
    printf("%d" , *p);

}