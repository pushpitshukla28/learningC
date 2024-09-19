#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct circularqueue
{
    int size;
    int f;
    int r;
    int *arr;
};


void enqueue(struct circularqueue *q , int val)
{
    if((q->r+1)%q->size == q->f){
    printf("Queue Overflow\n");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct circularqueue *q){
    int val = -1;
    if(q->r == q->f){
        printf("Empty queue");
    }
    else{
        q->f = (q->f+1)%q->size;
        val = q->arr[q->f];
    }
    return val;
}

int display(struct circularqueue *q){
    if(q->r == q->f)
        printf("Empty queue");
    else{
        int temp;
        temp = q->f;

        while(temp != q->r){
            temp = (temp+1)%q->size;
            printf("%d ", q->arr[temp]);
            }
            printf("\n");
            }
        }

int main(){
    int s;
    printf("Enter number of elements in the queue\n");
    struct circularqueue *q = (struct circularqueue *)malloc(sizeof(struct circularqueue));
    scanf("%d" , &s);
    int choice;
    int val;
    q->size = s;
    q->size++; // To differentiate full and empty states
    q->f = 0;
    q->r = 0;
    
    // q->f = -1;
    // q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    while(1){
    printf("Enter a choice:\n");
    printf("1.Enqueue an element\n");
    printf("2.Dequeue an element\n");
    printf("3.Display all the elements\n");
    printf("4.Quit\n");
    printf("Enter a choice\n");
    scanf("%d", &choice);

    switch(choice){
    case 1: 
    printf("Enter the element to enqueue:\n");
    scanf("%d" , &val);
    enqueue(q, val);
    break;

    case 2:
    val = dequeue(q);
    printf("The dequed element is %d\n" , val);
    break;

    case 3:
    display(q);
    break;

    case 4:
    exit(1);
}}



    // enqueue(q, 6);
    // enqueue(q, 7);
    // enqueue(q, 8);
    // enqueue(q, 14);
    // enqueue(q, 9);
    // display(q);
    // enqueue(q, 77);
    // enqueue(q,8);
    // display(q);
    // enqueue(q,88);
    // display(q);

}        


