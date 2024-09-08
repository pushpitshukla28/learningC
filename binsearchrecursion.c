#include <stdio.h>
int bin(int high , int low , int a[], int num){
    int mid;
    
    mid = (low+high)/2;
    if(low > high){
        return -1;
    }
    else if(num == a[mid]){
        return mid;
        }
        else if(num < a[mid]){
            high = mid-1;
            return bin(high , low , a , num);
        }
        else {
            low = mid +1;
            return bin(high , low , a , num);
        }

}
int main(){
    int a[100];
    int n;
    int y;
    printf("Enter number of elements in the array");
    scanf("%d", &n);
    printf("Enter the array in ordered form");
    for (int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("Enter number to be searched\n");
    scanf("%d", &y);
    int z = bin (n-1, 0, a, n);
    if(z == -1){
        printf("Wrong element searched");
    }
    else{
    
    printf("The number is at index %d", z );
}
}