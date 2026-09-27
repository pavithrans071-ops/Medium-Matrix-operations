#include <stdio.h>

void readMatrix(int matrix[10][10], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int A[10][10], int B[10][10], int C[10][10], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrix(int A[10][10], int B[10][10], int C[10][10],
                    int r1, int c1, int c2)
{
    int i, j, k;

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            C[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int A[10][10], int T[10][10], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            T[j][i] = A[i][j];
        }
    }
}

int main()
{
    int A[10][10], B[10][10], C[10][10], T[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    readMatrix(A, r1, c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Matrix B:\n");
    readMatrix(B, r2, c2);

    printf("\nMatrix A:\n");
    displayMatrix(A, r1, c1);

    printf("\nMatrix B:\n");
    displayMatrix(B, r2, c2);

    if(r1 == r2 && c1 == c2)
    {
        addMatrix(A, B, C, r1, c1);

        printf("\nMatrix Addition:\n");
        displayMatrix(C, r1, c1);
    }
    else
    {
        printf("\nMatrix addition is not possible.\n");
    }

    if(c1 == r2)
    {
        multiplyMatrix(A, B, C, r1, c1, c2);

        printf("\nMatrix Multiplication:\n");
        displayMatrix(C, r1, c2);
    }
    else
    {
        printf("\nMatrix multiplication is not possible.\n");
    }

    transposeMatrix(A, T, r1, c1);

    printf("\nTranspose of Matrix A:\n");
    displayMatrix(T, c1, r1);

    return 0;
}
