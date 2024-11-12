#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void deleteKElements(int arr[] , int n , int k){
    int stack_arr[100];
    int top =-1;

    for (int i =0; i<n ; i++){
        // While the stack is not empty, the top element is less than the current element, and we still need to delete elements
        while(k>0 && stack_arr[top]<arr[i] && top>=0){
            top--;
            k--;
        }
        stack_arr[++top] = arr[i];
    }

    // If there are still deletions left, remove elements from the end
    while (k > 0 && top >= 0) {
        top--;
        k--;
    }

    // Print the final array after deleting k elements
    printf("Array after deleting elements: ", k);
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}

int main(){
    int a , b;
    printf("Enter the number of elements in the array\n");
    scanf("%d" , &a);
    int arr[a];

    printf("Enter the number of elements to be deleted\n");
    scanf("%d" , &b);

    printf("Enter the array\n");
    for(int i=0; i<a ; i++){
        scanf("%d" , &arr[i]);
    }

    int size = sizeof(arr) / sizeof(arr[0]);

    deleteKElements(arr , a , b);

    
}