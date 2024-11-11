#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top = -1;

struct stack {
    char *arr;
    int data;
    int size;
}
int isEmpty(Stack *s){
    if(top == -1)
    return 1;
    else 
    return 0;
}

void push(struct stack *s , int p){
    //Check isFull
    s->arr[++top] = p;
}

int pop(struct stack *s){
    //Check isEmpty
    int x = s->arr[top];
    top--;
    return x;
}
int precedence(char ch){
     if(ch== '*' || ch == '/')
     return 3;
     else if(ch == '+' || ch == '-')
     return 2;
     else
     return 0;
}

int isOperator(char ch){
    if(ch == '+' || ch== '-' || ch == '*' || ch== '/'){
        return 1;
    }
    else 
    return 0;
}
int stackTop(Stack *s){
    return s->arr[top];
}

char *infixToPost(char *infix){
    struct stack *sp = (struct stack *) malloc (sizeof(struct stack));
    sp->size = 100;
    sp->arr = (char *) malloc (sizeof(char));
    char *postfix = (char *) malloc ((strlen(infix)+1) * sizeof(char));
    int j=0;
    int i =0;

    while(infix[i] != '\0'){

    if(!isOperator(infix[i])){
        postfix[j] = infix[i];
        j++;
        i++;
    }
    else{
        if(precedence(infix[i]) > precedence(stackTop(sp))){
            push(sp, infix[i]);
            i++;
        }
        else{
            postfix[j] = pop(sp);
        }

    }
}

while(isEmpty(sp)){
    postfix[j] = pop(sp);
    j++;
}
postfix[j] = '\0';

return postfix;
}