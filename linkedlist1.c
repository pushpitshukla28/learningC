#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

void traversal(node *ptr){
    while(ptr != NULL){
        printf("Element is %d\n" , ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    node *head = (node *) malloc(sizeof(node));
    node *second = (node *) malloc(sizeof(node));
    node *third = (node *) malloc(sizeof(node));

    //Link first and second nodes
    head->data = 8;
    head->next = second;

    second->data = 48;
    second->next = third;

    third->data = 75;
    third->next = NULL;

    traversal(head);


}