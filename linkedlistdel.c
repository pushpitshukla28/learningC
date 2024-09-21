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

//For deleteing the first element in the linked list
node *deletionOfFirst(node *head){
    node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

//For deleting the element in between in the linked list
node *deletionInBetween(node *head , int n){
    node *p = head;
    node *q = head->next;
    for (int i = 0; i < n-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

//Deletion of last element in the linked list
node *deletionOfLast(node *head){
    node *p = head;
    node *q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
return head;
}

//Deletion of value in linked list
node *deletionOfValue(node *head , int value){
    node *p = head;
    node *q = head->next;
    while(q->data!=value && q->next != NULL){
        p = p->next;
        q = q->next;
    }

    if(q->data == value){
        p->next = q->next;
        free(q);
    }
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

    printf("Before any operation\n");

    traversal(head);

    printf("\nAfter operation\n");
    // head = deletionOfFirst(head);
    // traversal(head);

    // head = deletionInBetween(head , 2);
    // traversal(head);

    // head = deletionOfLast(head);
    // traversal(head);

    head = deletionOfValue(head , 48);
    traversal(head);
    }