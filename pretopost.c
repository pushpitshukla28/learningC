//LAB 6 question 4

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure to store intermediate postfix expressions
struct Stack {
    char arr[MAX][MAX];
    int top;
};

// Initialize stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Push an element to the stack
void push(struct Stack* stack, char* str) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    strcpy(stack->arr[++(stack->top)], str);
}

// Pop an element from the stack
char* pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return "";
    }
    return stack->arr[(stack->top)--];
}

// Check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert prefix expression to postfix
void prefixToPostfix(char* prefix) {
    struct Stack stack;
    initStack(&stack);

    int length = strlen(prefix);

    // Traverse the prefix expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        // If character is an operand, push it onto the stack
        if (isalnum(prefix[i])) {
            char operand[2] = {prefix[i], '\0'};
            push(&stack, operand);
        }
        // If character is an operator
        else if (isOperator(prefix[i])) {
            // Pop two operands from the stack
            char operand1[MAX], operand2[MAX];
            strcpy(operand1, pop(&stack));
            strcpy(operand2, pop(&stack));

            // Concatenate the operands and operator in postfix order
            char temp[MAX];
            snprintf(temp, sizeof(temp), "%s%s%c", operand1, operand2, prefix[i]);

            // Push the resultant postfix expression back onto the stack
            push(&stack, temp);
        }
    }

    // The final element in the stack is the postfix expression
    printf("Postfix Expression: %s\n", pop(&stack));
}

int main() {
    char prefix[MAX];

    // Input prefix expression
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    // Convert to postfix
    prefixToPostfix(prefix);

    return 0;
}
