#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack structure to hold strings (prefix expressions)
struct Stack {
    int top;
    int capacity;
    char** array;
};

// Function to create a stack of given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char**)malloc(stack->capacity * sizeof(char*));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item to the stack
void push(struct Stack* stack, char* item) {
    stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
char* pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return NULL;
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert postfix to prefix expression
char* postfixToPrefix(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));

    // Traverse the postfix expression
    for (int i = 0; i < strlen(postfix); i++) {
        // If the character is an operand, push it onto the stack
        if (isalnum(postfix[i])) {
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = postfix[i];
            operand[1] = '\0';
            push(stack, operand);
        }
        // If the character is an operator
        else if (isOperator(postfix[i])) {
            // Pop two operands from the stack
            char* operand2 = pop(stack);
            char* operand1 = pop(stack);

            // Allocate space for the new prefix expression
            char* prefix = (char*)malloc(strlen(operand1) + strlen(operand2) + 2 * sizeof(char));

            // Form the new prefix expression
            prefix[0] = postfix[i];
            prefix[1] = '\0';
            strcat(prefix, operand1);
            strcat(prefix, operand2);

            // Push the resulting prefix expression back to the stack
            push(stack, prefix);
        }
    }

    // The last element of the stack will be the prefix expression
    return pop(stack);
}

int main() {
    char postfix[100];

    // Input the postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    // Convert postfix to prefix
    char* prefix = postfixToPrefix(postfix);

    // Output the result
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
