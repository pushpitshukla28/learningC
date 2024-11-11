#include <stdio.h>

#define MAX 100

// Structure to represent a sparse matrix
struct SparseMatrix {
    int row;
    int col;
    int value;
};

// Function to convert a regular matrix to sparse matrix
int createSparseMatrix(int matrix[MAX][MAX], int rows, int cols, struct SparseMatrix sparse[MAX]) {
    int k = 1; // Start from 1, because sparse[0] will store metadata
    sparse[0].row = rows;
    sparse[0].col = cols;
    sparse[0].value = 0; // Initially 0, will update later
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++;
            }
        }
    }
    
    sparse[0].value = k - 1; // Total number of non-zero elements
    return k;
}

// Function to print the sparse matrix
void printSparseMatrix(struct SparseMatrix sparse[MAX], int size) {
    printf("\nSparse Matrix Representation (Row, Col, Value):\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int main() {
    int matrix[MAX][MAX], rows, cols;
    struct SparseMatrix sparse[MAX];
    
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &rows, &cols);
    
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int size = createSparseMatrix(matrix, rows, cols, sparse);
    
    printSparseMatrix(sparse, size);
    
    return 0;
}
