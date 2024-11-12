// Implement two stacks in an array

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20

int stack_arr[MAX];
int top1 = -1;
int top2 = MAX;

int isFull1(){
    if(top1 >= top2){
        return 1;
    }
    return 0;
}
int isFull2(){
    if(top2 <= top1){
        return 1;
    }
    return 0;
}

void push1(int val){
    if(isFull1()){
        printf("Stack 1 is full\n");
    }
    else{
        top1++;
        stack_arr[top1] = val;
    }
}

void push2(int val){
    if(isFull2()){
        printf("Stack 2 is full\n");
    }
    else{
        top2--;
        stack_arr[top2] = val;
    }
}

int pop1(){
    int x;
    if(top1 == -1){
        printf("Stack is empty\n");
    }
    else{
        x = stack_arr[top1];
        top1--;
    }
    return x;
}

int pop2(){
    int x;
    if(top2 == MAX){
        printf("Stack is empty\n");
    }
    else{
        x = stack_arr[top2];
        top2++;
    }
    return x;
}

int main(){
    push1(10);
    push1(20);
    push1(30);

    pop1();

    push2(6);
    push2(7);

    pop2();
}



