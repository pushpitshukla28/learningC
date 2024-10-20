#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data){
    struct node *n; //creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); //Allocating memory in the heap
    n->data = data; //Setting data
    n->right = NULL; 
    n->left = NULL;
    return n; // returning the created node
}


int main(){
    struct node*p = createNode(2);
    struct node*p1 = createNode(4);
    struct node*p2 = createNode(5);

    p->left = p1;
    p->right = p2;



    // struct node *p;
    // p = (struct node *) malloc(sizeof (struct node));
    // p->left = NULL;
    // p->right = NULL;
    // p->data = 2;

    // struct node *p1;

    // p1 = (struct node *) malloc(sizeof (struct node));
    // p1->left = NULL;
    // p1->right = NULL;
    // p1->data = 6;

    // struct node *p2;

    // p2 = (struct node *) malloc(sizeof (struct node));
    // p2->left = NULL;
    // p2->right = NULL;
    // p2->data = 5;


}