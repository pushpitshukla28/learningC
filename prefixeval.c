#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    return top == -1;
}

int pop() {
    if (!isEmpty()) {
        return Stack[top--];
    }
    printf("Stack underflow\n");
    return -1; 
}

int evalPrefix(char* exp) {
    int len = strlen(exp);
    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            int operand1 = pop();
            int operand2 = pop();
            
            switch (exp[i]) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", exp[i]);
                    return -1;
            }
        }
    }
    return pop();
}

int main() {
    char exp[] = "-+7*45+20"; 
    printf("Prefix expression: %s\n", exp);
    printf("Result: %d", evalPrefix(exp));
    return 0;
}