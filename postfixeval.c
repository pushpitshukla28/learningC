#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

int Stack[MAX];
int top = -1;

int isFull(){
    if(top == MAX-1){
        return 1;
    }
    else 
    return 0;
}

void push(int item) {
    if (isFull()) {
        printf("Stack Overflow\n");
    } else {
        Stack[++top] = item;
    }
}

int isEmpty() {
    if(top ==-1){
        return 1;
    }
    else 
    return 0;
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
    }
    else{
        return Stack[top--];
    }
    
    
}

int postfixeval(char *exp){
    int len = strlen(exp);
    for (int i= 0; i<len ; i++){
        if(isdigit(exp[i])){
            push(exp[i] - '0');
        }
        else{
            int oper2 = pop();
            int oper1 = pop();

            switch(exp[i]){
                case '+' :
                push(oper1 + oper2);
                break;
                case '-':
                    push(oper2 - oper1);
                    break;
                case '/':
                    push(oper2 / oper1);
                    break;
                case '*':
                    push(oper1 * oper2);
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", exp[i]);
                    return -1;


            }
        }
    }
    return pop();
}

int main(){
    char exp[] = "785/65-*-";
    printf("Postfix expression: %s\n" , exp);
    printf("Result : %d" , postfixeval(exp));
    return 0;
}
