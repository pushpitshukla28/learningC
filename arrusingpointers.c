#include <stdio.h>
int main(){
int a[100];
int n;
printf("Enter number of elements in array\n");
scanf("%d", &n);
int *ptr = a;
printf("Enter elements\n");
for (int i = 0; i < n; i++)
{
   scanf("%d", ptr+i);
}
printf("The address of entered array is: \n");
for (int i = 0; i < n; i++)
{
    printf("%d\t", (void*)ptr+i);
}
printf("\nThe entered array is: \n");
for (int i = 0; i < n; i++)
{
    printf("%d\t", *(ptr+i));
}
}
