#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int top = -1;
int stack_arr[MAX];

int push(int data){
    stack_arr[++top] = data;
}
char pop(){
    return stack_arr[top--];
}

int palindrome(char *str){
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        push(str[i]);
    }
    for (int i = 0; i < len; i++)
    {
        if (str[i]!=pop())
        {
            return 0;
        }
        return 1;
        
    }
}

int main(){
    char str[MAX];
    printf("Enter a string\n");
    scanf("%s", &str);
    if (palindrome(str))        
    {
        printf("Is a palindrome");
    }
    else{
        printf("Not a palindrome");
    }
    
}