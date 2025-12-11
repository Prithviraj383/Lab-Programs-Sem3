#include <stdio.h>
#define ROW 100
#define COL 100
void read(int (*p)[COL], int r, int c)
{
        printf("Enter elements of (%d X %d) matrix \n", r, c);
        int m = r, n = c;
        for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                        scanf("%d", (*(p + i) + j));
}
void display(int (*p)[COL], int r, int c)
{
        int m = r, n = c;
        for (int i = 0; i < m; i++)
        {
                for (int j = 0; j < n; j++)
                        printf("%d", *(*(p + i) + j));
                printf("\n");
        }
}
int main()
{
        int arr1[ROW][COL], r, c;
        int (*p)[COL] = arr1;
        printf("Enter the number of rows and column: ");
        scanf("%d%d", &r, &c);
        read(p, r, c);
        printf("Matrix contents: \n");
        display(p, r, c);
        return 0;
}