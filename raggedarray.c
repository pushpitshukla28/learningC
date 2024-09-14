#include<stdio.h>
#include<stdlib.h>
int main(){
    int rowN , colN;
    int **table;
    printf("Enter the number of rows\n");
    scanf("%d" , &rowN);
    table = (int**)calloc(rowN+1 , sizeof(int*));
    for(int i =0 ; i<rowN;i++){
        printf("Enter the size of %d row \n" , i+1);
        scanf("%d" , &colN);
        table[i] = (int*) calloc(colN+1 , sizeof(int));
        printf("Enter %d row elements\n" ,i+1);
        for (int j = 0; j < colN; j++)
        {
            scanf("%d" , &table[i][j]);
        }
        table[i][0]= colN;
        printf("Size of row number[%d]= %d\n" , i+1 , table[i][0]);
    }
        table[rowN]=NULL;
        for (int i = 0; i < rowN; i++)
        {
            printf("Displaying %d row elements\n" , i+1);
            for (int j = 0; j < *table[i]; j++)
            {
                printf("%d\t" , table[i][j]);
            }
            printf("\n");
            
        }
        return 0;
    }