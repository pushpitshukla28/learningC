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

node * insertAtfirst(node *head , int data){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

node *insertAtIndex(node *head , int data , int index){
    node *ptr = (node *) malloc(sizeof(node));
    node *p = head;
    int i =0;

    while(i != index-1){
        p= p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

node* insertAtEnd(node *head , int data){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    node *p = head;

    while(p->next != NULL){
        p= p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

node* insertAfterNode(node *head , node *prevNode , int data){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
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

    printf("Linked list before insertion\n");

    traversal(head);

    printf("\nLinked list after insertion\n");
    //head = insertAtfirst(head , 69);
    //traversal(head);
    // head = insertAtIndex(head , 99 , 2);
    // traversal(head);
    // head = insertAtEnd(head , 105);
    // traversal(head);
    head = insertAfterNode(head , second , 696);
    traversal(head);
}