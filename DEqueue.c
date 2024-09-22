#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct DEqueue{
    int *arr;
    int f;
    int r;
    int size;
}DE;

// int isFull(DE *q){
//     if()
// }

int isEmpty(DE *q){
    if(q->f == q->r){
        return 1;
    }
    else
    return 0;

}

void enqueueR(DE *q , int val){
    if(q->r == q->size-1){
        printf("Queue Overflow\n");
    }
    else {
        q->r = q->r +1;
        q->arr[q->r] = val;
    }
}
void enqueueF(DE *q , int val){
    if(q->f ==-1){
        printf("Queue Overflow\n");
    }
    else {
        q->f = q->f +1;
        q->arr[q->f] = val;
    }
}

int dequeueF(DE *q){
    int val =-1;
    if(isEmpty(q)){
        printf("Queue Underflow\n");
    }
    else{
        q->f = q->f+1;
        val = q->arr[q->f];
        }
        return val;
}
int dequeueR(DE *q){
    int val =-1;
    if(isEmpty(q)){
        printf("Queue Underflow\n");
    }
    else{
        q->r = q->r-1;
        val = q->arr[q->r];
        }
        return val;
}

void display(DE *q){
    if(isEmpty(q)){
        printf("Queue underflow\n");
    }
    else{
        int temp;
        temp = q->f;
        while (temp != q->r){
            printf("%d\n" , q->arr[temp]);
            temp ++;
        }
    }
}

int main(){
    DE *d = (DE *)malloc (sizeof(DE));
    d->size = 5;
    d->arr = (int *)malloc(d->size *sizeof(int));
    d->f = 0;
    d->r= -1;


    enqueueF(d , 6);
    enqueueR(d, 8);
    enqueueF(d,9);
    display(d);
    dequeueF(d);
    dequeueR(d);
    display(d);

}