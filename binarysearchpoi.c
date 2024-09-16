#include<stdio.h>
#define MAX 7
int bin(int a[] , int *pfind , int *pfirst , int *pLast){
    int *pWalk;
    int mid = (*pfirst + *pLast)/2;

    if(*pfirst > *pLast){
        return -1;
    }
    else if(*pfind == a[mid]) {
        return mid;
        }
    else if(*pfind < a[mid]){
        *pLast = mid -1;
        return bin(a,pfind , pfirst , pLast);
    }
    else{
        *pfirst = mid +1;
        return bin(a , pfind , pfirst , pLast);
    }    
    
}

int main(){
    int arr[MAX] = {1,2,5,8,10,12,14};
    //Number to be searched
    int n = 5;
    int first =0;
    int last = MAX-1;
    int y = bin(arr , &n , &first , &last);
    if (y==-1)
    {
        printf("Error");
    }
    else{
        printf("The number is at index %d" , y);
    }
    

}