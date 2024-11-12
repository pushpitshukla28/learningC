//Reverse a singly linked list of words

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char data[100];
    struct Node *next;
}node;

node *createNode(char val[]){
    node *newN = (node *)malloc(sizeof(node));
    strcpy(newN->data , val);
    newN->next = NULL;
    return newN;
}

node *reverseList(node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node *newHead = reverseList(head->next);

    
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

void traversal(node *ptr){
    //node *ptr = (node *) malloc(sizeof(node));
    while(ptr!= NULL){
        printf("Elemet is %s\n" ,ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    node *head = createNode("Hello");
    head->next = createNode("World");
    head->next->next = createNode("how");
    head->next->next->next = createNode("are");
    head->next->next->next->next = createNode("you?");

    traversal(head);

    node *newHH = reverseList(head);
    traversal(newHH);

}

