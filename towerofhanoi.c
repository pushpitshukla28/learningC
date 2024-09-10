#include <stdio.h>
void tower(int n , char beg , char aux , char end){
    if(n<=0){
        printf("Not Possible\n");
    }
    else if(n==1){
        printf("Move disc from %c to %c\n" , beg , end);
    }
    else{
        tower(n-1,beg , end , aux);
        tower(1, beg , aux , end);
        tower(n-1 , aux , beg , end);
    }
}

int main(){
    int n;
    char a,b,c;
    printf("The start pole is a, the auxillary is b and end is c\n");
    printf("Enter number of disks\n");
    scanf("%d", &n);
    tower(n,'a','b','c');
}