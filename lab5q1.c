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
    if(s->top = -1){
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
    s->top = s->top-1;
    return s->top;
    
}

int main(){
    int n;
    int choice;
    int val;
    stack *s = (stack *) malloc(sizeof(stack));
    printf("Enter the size of the stack\n");
    scanf("%d" , &n);


    s->size = n;
    s->top = -1;
    s->arr = (int *)malloc (s->size * sizeof(int));

    while(1){
    printf("1.Push an element\n");
    printf("2.Pop an element\n");
    printf("3.Display all the elements\n");
    printf("4.Quit\n");
    printf("Enter a choice\n");
    scanf("%d", &choice);

    switch(choice){
    case 1: 
    printf("Enter the element to push:\n");
    scanf("%d" , &val);
    push(s , val);
    break;

    case 2:
    val = pop(s);
    printf("The popped element is %d\n" , val);
    break;

    case 3:
    printf("Underprocess \n");
    break;

    case 4:
    exit(1);
}}
}