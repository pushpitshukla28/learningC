#include <stdio.h>
int exchange(int x, int y){
    int temp;
    temp = x;
    x=y;
    y = temp;
    return x;
    return y;
}

 int main(){
    int a, b;
    printf("Enter two numbers to be exchanged \n");
    scanf("%d %d", &a, &b);
    int y = exchange(a,b);
    printf("The exchanged numbers are:%d %d",a ,b);

 }


