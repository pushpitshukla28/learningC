#include <stdio.h>
int fib(int n){
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else{
        return (fib(n-1)+fib(n-2));
    }
}
    int main(){
        int x;
        printf("Enter the term till you need fibonacci\n");
        scanf("%d", &x);
        int result = fib(x);
        printf("The fibonacci is: %d", result);
    }
