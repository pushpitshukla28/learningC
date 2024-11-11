#include<stdio.h>
#include<stdlib.h>
#include<string.h>

node *top = NULL;


typedef struct Node{
    int data;
    struct Node *next;
}node;
 
void traversal(node *ptr){
    while(ptr != NULL){
        printf("Element is %d\n" , ptr->data);
        ptr= ptr->next;
    }
}

int isEmpty(node *top){
    if(top == NULL){
        return 1;
    }
    else
    return 0;
}

int isFull(node *top){
    node *p = (node *)malloc(sizeof(node));
    if(p== NULL){
        return 1;
    }
    else
    return 0;
}



//Push is insterting node @ index 0
node *push(node *top ,int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        node *n = (node *)malloc(sizeof(node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }

}
//Pop is printing value at index 0 and removing it using free()
int pop(node *top){
    if(isEmpty(top)){
        printf("Stack Underflow\n");
    }
    else{
        node *n = top;
        top = top->next;
        int x = n->data;
        free(n);
        return x;
    }
}
int main(){
    
    top = push(top , 7);
    top = push(top , 8);
    top = push(top , 12);
    top = push(top , 69);

    traversal(top);
    int element = pop(top);
    printf("The popped element is %d\n" , element);

    printf("\nStack after pop\n");
    traversal(top);
}

