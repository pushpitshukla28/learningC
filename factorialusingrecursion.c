#include <stdio.h>
int fact(int n){
    int x,y,res;
    if (n==0){
        return 1;
    }
    else{
        x=n-1;
        y= fact(x);
        res = n*y;
        return res;

    }
}

int main(){
    int a;
    printf("Enter the number for which factorial is to be calculated \n");
    scanf("%d",&a);
    int b = fact(a);
    printf("The factorial is %d", b);
}