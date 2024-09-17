#include <stdio.h>

// Function to convert matrix to sparse matrix
void convertToSparseMatrix(int matrix[][10], int row, int col, int sparseMatrix[][3], int *numNonZero)
{
    int k = 0; // Counter for non-zero elements

    // Traverse the matrix and store non-zero elements
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparseMatrix[k][0] = i;            // Row index
                sparseMatrix[k][1] = j;            // Column index
                sparseMatrix[k][2] = matrix[i][j]; // Non-zero value
                k++;
            }
        }
    }

    // Set the number of non-zero elements
    *numNonZero = k;
}

// Function to print the sparse matrix
void printSparseMatrix(int sparseMatrix[][3], int numNonZero)
{
    printf("Sparse Matrix Representation:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < numNonZero; i++)
    {
        printf("%d\t%d\t%d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }
}

// Function to convert sparse matrix back to dense matrix
void convertToDenseMatrix(int sparseMatrix[][3], int numNonZero, int denseMatrix[][10], int row, int col)
{
    // Initialize dense matrix with zeros
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            denseMatrix[i][j] = 0;
        }
    }

    // Populate dense matrix with values from sparse matrix
    for (int i = 0; i < numNonZero; i++)
    {
        int r = sparseMatrix[i][0];
        int c = sparseMatrix[i][1];
        int value = sparseMatrix[i][2];
        denseMatrix[r][c] = value;
    }
}

// Function to print the dense matrix
void printDenseMatrix(int denseMatrix[][10], int row, int col)
{
    printf("Dense Matrix Representation:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", denseMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int matrix[10][10], sparseMatrix[100][3], denseMatrix[10][10];
    int row, col, numNonZero;

    // Input matrix dimensions
    printf("Enter number of rows and columns of matrix:\n");
    scanf("%d %d", &row, &col);

    // Input matrix elements
    printf("Enter elements of matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Convert matrix to sparse matrix
    convertToSparseMatrix(matrix, row, col, sparseMatrix, &numNonZero);

    // Print the sparse matrix
    printSparseMatrix(sparseMatrix, numNonZero);

    // Convert sparse matrix back to dense matrix
    convertToDenseMatrix(sparseMatrix, numNonZero, denseMatrix, row, col);

    // Print the dense matrix
    printDenseMatrix(denseMatrix, row, col);

    return 0;
}
