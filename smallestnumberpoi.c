#include<stdio.h>
int main(){
    int a[5] = {5,7,10,6,1};
    int *pSm;
    int *pWalk;
    int *pLast;
    pLast = &a[5-1];
    for(pSm = a, pWalk = a+1 ; pWalk <= pLast ; pWalk++){
        if(*pSm > *pWalk)
        *pSm = *pWalk;
    }

    printf("%d", *pSm);
}