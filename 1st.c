// write a program to perform arithmetic operations

#include <stdio.h>

int main()
{
    int i, j, row, column, a[10][10], b[10][10];
    int Addition[10][10], Subtraction[10][10], Multiplication[10][10], Module[10][10];
    float Division[10][10];

    printf("\nPlease Enter Number of row and column\n");
    scanf("%d %d", &row, &column);

    printf("\nPlease Enter the first array elements\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nPlease Enter the second array elements\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            Addition[i][j] = a[i][j] + b[i][j];
            Subtraction[i][j] = a[i][j] - b[i][j];
            Multiplication[i][j] = a[i][j] * b[i][j];
            Division[i][j] = a[i][j] / b[i][j];
            Module[i][j] = a[i][j] % b[i][j];
        }
    }
    printf("\nAdd\t Sub\t Multi\t Mod\t Div");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("\n%d \t", Addition[i][j]);
            printf("%d \t", Subtraction[i][j]);
            printf("%d \t", Multiplication[i][j]);
            printf("%d \t", Module[i][j]);
            printf("%.2f \t", Division[i][j]);
        }
    }
    return 0;
}