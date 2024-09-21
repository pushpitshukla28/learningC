#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *f = NULL;
node *r = NULL;

void traversal(node *ptr)
{
    printf("Printing the elements\n");
    while (ptr != NULL)
    {
        printf("Element is %d \n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    node *n;
    if (f == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        f = f->next;
        val = n->data;
        free(n);
    }
}

int main()
{
    traversal(f);

    enqueue(34);
    enqueue(6);
    enqueue(27);
    enqueue(7);

    printf("The elements in the list are:\n");

    traversal(f);

    dequeue();

    traversal(f);
}