//LAB 5 question 1

#include <stdio.h>
#include <stdlib.h>
int top = -1;
#define MAX 20
int stack_arr[MAX]; 

int isFull(){
    if (top==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}

int isEmpty()
{
    if(top == -1)
    return 1;
    else
    return 0;
}

void push(int data)
{
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    top = top+1;
    stack_arr[top] = data;
}

int pop(){
    int value;
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    value = stack_arr[top];
    top = top -1;
    return value;
}

int peek(){
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    return stack_arr[top];
}

void Print(){
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    for(int i = top ; i>=0 ; i--){
    printf("%d \n" , stack_arr[i]);
    }
}

int main(){
    int choice , data;
    while(1){
        printf("1. Push an element\n");
        printf("2. Pop an element\n");
        printf("3. Print the topmost element\n");
        printf("4. Print the whole stack\n");
        printf("5. Quit\n");
        printf("Enter your choice:\n");
        scanf("%d" , &choice);

        switch (choice)
        {
        case 1:
        printf("Enter number you want to push\n");
        scanf("%d", &data);
            push(data);
            break;

        case 2:
        data = pop();
        printf("The popped element is: %d \n" , data);  
        break;

        case 3:
        data = peek();  
        printf("The topmost element is:%d \n", data);
        break;

        case 4:
        Print();
        break;

        case 5:
        exit(1);
        
        default:
        printf("Wrong choice\n");
            break;
        }
        }
        return 0;
}


