#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top =-1;

typedef struct stack{
    char *arr;
    int size;
    int data;
}Stack;

int isFull(Stack *s){
    if(top == s->size -1){
        return 1;
    }
    else
    return 0;
}

int stackTop(Stack *s){
    return s->arr[top];
}

void push(Stack *s , int val){
    if(isFull(s)){
        printf("Stack Overflow");
    }
    else{
        s->arr[++top] = val;
    }

}
int isEmpty(Stack *s){
    if(top == -1)
    return 1;
    else 
    return 0;
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
    }
    else{
        int x = s->arr[top];
        top --;
        return x;
        }
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


char *infixToPostfix(char *infix){
    Stack *sp = (Stack *) malloc(sizeof(Stack));
    sp->size = 100;
    sp->arr = (char *)malloc(sizeof(char));
    char *postfix = (char*) malloc ((strlen(infix)+1) *sizeof(char));
    int i=0; 
    int j=0;
    while (infix[i] != '\0')
    {
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
                postfix [j] = pop(sp);
                j++;  
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    char *infix = "a-b+t/6";
    printf("postfix is %s" , infixToPostfix(infix));

}