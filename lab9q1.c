//Implement a queue using singly linked list without the header node 

#include <stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *f = NULL;
node *r = NULL;

void traversal(node *ptr){
    //node *ptr = (node *)malloc (sizeof(node)); (THIS IS NOT THERE)
    while(ptr != NULL){
        printf("Element is %d \n" , ptr->data);
        ptr = ptr->next;
    }
    
}

void enqeue(int val){
    node *ptr = (node *) malloc(sizeof(node));
    if(ptr == NULL){
        printf("Queue is full\n");
    }
    else{
        ptr->data = val;
        ptr->next = NULL;
        if(f== NULL){
            f=r=ptr;
        }
        else{
            r->next = ptr;
            r = ptr;
        }
    }    
}

void dequeue(){
    int val = -1;
    node *n = (node *) malloc(sizeof(node));
    if(f== NULL){
    printf("Queue is empty\n");
    }
    else{
        f= f->next;
        val = n->data;
        free(n);
    }
}

int main(){
    enqeue(10);
    enqeue(5);
    enqeue(7);
    enqeue(1);
    enqeue(18);
    enqeue(19);
    enqeue(47);

    traversal(f);

    dequeue();
    dequeue();

    printf("After dequeue \n");

    traversal(f);

}
