#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(){
    
}

void enqueue(struct queue *q , int val){
    if(isFull()){
        printf("Overflow\n");
    }
    else{
        q->r = q->r+1;
        q->arr[q->r] = val;
    }

 }
 int dequeue(struct queue *q){
    int a =-1
    if(q->f == q->r){
        printf("No element to dequeue");
    }
    else{
        q->f++;
        a= q->arr[q->f];
    }
    return a;
 }


