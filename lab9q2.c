// UNION AND INTERSECTION SET OPERATION ON SINGLY LINKED LIST

// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// struct node{
//     int data;
//     struct node *next;
// }

// void traversal(node *ptr){
//     while(ptr != NULL){
//         printf("The element is %d" , ptr->data);
//         ptr = ptr->next;
//     }
// }


#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void appendNode(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Node* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to check if a value exists in the linked list
int isPresent(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Function to find the union of two linked lists
struct Node* getUnion(struct Node* list1, struct Node* list2) {
    struct Node* unionList = NULL;
    struct Node* temp = list1;

    // Add all elements of the first list to the union list
    while (temp != NULL) {
        appendNode(&unionList, temp->data);
        temp = temp->next;
    }

    // Add elements of the second list that are not already in the union list
    temp = list2;
    while (temp != NULL) {
        if (!isPresent(unionList, temp->data)) {
            appendNode(&unionList, temp->data);
        }
        temp = temp->next;
    }

    return unionList;
}

// Function to find the intersection of two linked lists
struct Node* getIntersection(struct Node* list1, struct Node* list2) {
    struct Node* intersectionList = NULL;
    struct Node* temp = list1;

    // Check each element of the first list if it is present in the second list
    while (temp != NULL) {
        if (isPresent(list2, temp->data) && !isPresent(intersectionList, temp->data)) {
            appendNode(&intersectionList, temp->data);
        }
        temp = temp->next;
    }

    return intersectionList;
}

// Main function to test the union and intersection functions
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Creating the first linked list: 10 -> 15 -> 20 -> 25
    appendNode(&list1, 10);
    appendNode(&list1, 15);
    appendNode(&list1, 20);
    appendNode(&list1, 25);

    // Creating the second linked list: 15 -> 20 -> 30 -> 35
    appendNode(&list2, 15);
    appendNode(&list2, 20);
    appendNode(&list2, 30);
    appendNode(&list2, 35);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct Node* unionList = getUnion(list1, list2);
    printf("Union of List 1 and List 2: ");
    printList(unionList);

    struct Node* intersectionList = getIntersection(list1, list2);
    printf("Intersection of List 1 and List 2: ");
    printList(intersectionList);

    return 0;
}

