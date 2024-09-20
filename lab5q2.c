#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int top;
    int size;
    int *arr;
}stack;

int isFull(stack *s){
    if(s->top == s->size-1){
        return 1;
    }
    else
    return 0;
}

int isEmpty(stack *s){
    if(s->top == -1){
        return 1;
    }
    else
    return 0;
}

void push(stack *s , int val){
    if (isFull(s)){
        printf("Stack Overflow\n");
    }
    else{
        s->top = s->top+1;
        s->arr[s->top] = val;
    }
    
}

int pop(stack *s){
    if(isEmpty(s)){
        printf("Stack underflow\n");
    }
    int val = s->arr[s->top];
    s->top = s->top-1;
    return val;
    
}

int main(){
    int n;
    int choice;
    int val;
    int dec;
    stack *s = (stack *) malloc(sizeof(stack));
    // printf("Enter the size of the stack\n");
    // scanf("%d" , &n);
    //s->size = n;
    s->size = 10;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    printf("Enter the decimal number\n");
    scanf("%d" , &dec);

    while(dec > 0){
        int rem = dec%2;
        push (s , rem);
        dec = dec/2;
    }
    while (s->top >=0)
    {
        printf("%d" , pop(s));
    }
    

}