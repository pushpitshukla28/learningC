//LAB 6 question 2

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top =-1;

typedef struct stack{
    char *arr;
    int size;
    int data;
}Stack;

int isEmpty(Stack *s){
    if(top == -1)
    return 1;
    else 
    return 0;
}

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
// char stackTop(Stack *s){
//     if(!isEmpty(s)){
//     return s->arr[top];
// }
// return '\0';
// }
void push(Stack *s , int val){
    if(isFull(s)){
        printf("Stack Overflow");
    }
    else{
        s->arr[++top] = val;
    }

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

void reversal(char *infix){
    int len = strlen(infix);
    int temp;
    for(int i =0; i< len/2 ; i++){
        temp = infix[i];
        infix [i] = infix[len-i-1];
        infix[len-i-1] = temp;
    }
}

char *infixToPrefix(char *infix){
    reversal(infix);
    int len = strlen(infix);

    for (int i = 0; i < len; i++)
    {
        if(infix[i] == '('){
            infix[i] =')';
        }
        else if(infix[i] == ')'){
            infix[i] = '(';
        }

    }
    char *postfix = infixToPostfix(infix);
    reversal(postfix);
    return postfix;
}
int main(){
    char *infix = "4-8+7/6";
    printf("postfix is %s" , infixToPostfix(infix));
    printf("Infix to Postfix is %s" , infixToPrefix(infix));
    return 0;
}