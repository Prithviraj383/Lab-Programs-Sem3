#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void display(int arr[], int n)
{
        printf("ARRAY ELEMENTS: ");
        for (int i = 0; i < n; ++i)
                printf("%d ", arr[i]);
        printf("\n");
}

void insertByPos(int arr[], int *n, int pos, int val)
{
        if (pos < 1 || pos > *n + 1)
                return;
        for (int i = *n; i >= pos; --i)
                arr[i] = arr[i - 1];
        arr[pos - 1] = val;
        (*n)++;
        printf("\n");
}

void deleteByPos(int arr[], int *n, int pos)
{
        if (pos < 1 || pos > *n)
                return;
        for (int i = pos - 1; i < *n - 1; ++i)
                arr[i] = arr[i + 1];
        (*n)--;
        printf("\n");
}

void insertByKey(int arr[], int *n, int key, int val)
{
        for (int i = 0; i < *n; ++i)
        {
                if (arr[i] == key)
                {
                        for (int j = *n; j > i + 1; --j)
                                arr[j] = arr[j - 1];
                        arr[i + 1] = val;
                        (*n)++;
                        break;
                }
        }
        printf("\n");
}

void deleteByKey(int arr[], int *n, int key)
{
        int i, found = 0;
        for (int i = 0; i < *n; ++i)
        {
                if (arr[i] == key)
                {
                        found = i;
                        break;
                }
        }
        if (!found)
        {
                printf("KEY NOT FOUND\n");
                return;
        }
        for (int j = found; j < *n - 1; j++)
                arr[j] = arr[j + 1];
        (*n)--;
        printf("\n");
}
void insertByOrder(int arr[], int *n, int val)
{
        int i;
        for (i = *n - 1; (i >= 0 && arr[i] > val); --i)
                arr[i + 1] = arr[i];
        arr[i + 1] = val;
        (*n)++;
        printf("\n");
}

int searchByKey(int arr[], int *n, int key)
{
        for (int i = 0; i < *n; ++i)
        {
                if (arr[i] == key)
                        return i;
        }
        return -1;
}

int searchByPos(int arr[], int *n, int pos)
{
        if (pos < 1 || pos > *n)
                return -1;
        return arr[pos - 1];
}

void reverse(int arr[], int n)
{
        for (int i = 0; i < n / 2; ++i)
        {
                int temp = arr[i];
                arr[i] = arr[n - i - 1];
                arr[n - i - 1] = temp;
        }
        printf("\n");
}

int main()
{

        int choice, n = 0, pos, val, key, type;
        int staticc[MAX];
        int *dynamic = NULL;
        printf("CHOOSE STORAGE TYPE: \n");
        printf("1. Static Memoery Allocation\n");
        printf("2. Dynamic Memoery Allocation\n");
        printf("Enter your choice: ");
        scanf("%d", &type);
        if (type == 2)
        {
                printf("Enter initial size of dynamic array: ");
                scanf("%d", &n);
                dynamic = (int *)malloc(n * sizeof(int));
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; ++i)
                        scanf("%d", &dynamic[i]);
        }
        else
        {
                printf("Enter no. of elements: ");
                scanf("%d", &n);
                printf("Enter %d elements", n);
                for (int i = 0; i < n; ++i)
                        scanf("%d", &staticc[i]);
        }
        do
        {
                printf("1. Insert by position\n");
                printf("2. Insert by key\n");
                printf("3. Delete by Postion\n");
                printf("4. Delete by key\n");
                printf("5. Insert by Order\n");
                printf("6. Search by key\n");
                printf("7. Search by position\n");
                printf("8. Reverse\n");
                printf("9. Display\n");
                printf("10. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                int *arr = (type == 2) ? dynamic : staticc;
                switch (choice)
                {
                case 1:
                        printf("Enter position and value: ");
                        scanf("%d %d", &pos, &val);
                        insertByPos(arr, &n, pos, val);
                        break;

                case 2:
                        printf("Enter key and value to insert after key: ");
                        scanf("%d %d", &key, &val);
                        insertByKey(arr, &n, key, val);
                        break;

                case 3:
                        printf("Enter positon to delete: ");
                        scanf("%d", &pos);
                        deleteByPos(arr, &n, pos);
                        break;

                case 4:
                        printf("Enter key to delete: ");
                        scanf("%d", &key);
                        deleteByKey(arr, &n, key);
                        break;

                case 5:
                        printf("Enter value to insert in order: ");
                        scanf("%d", &val);
                        insertByOrder(arr, &n, val);
                        break;

                case 6:
                        printf("Enter key to search: ");
                        scanf("%d", &key);
                        pos = searchByKey(arr, &n, key);
                        if (pos != -1)
                                printf("Key found at position %d", pos);
                        else
                                printf("KEY NOT FOUND\n");
                        break;

                case 7:
                        printf("Enter position to search: ");
                        scanf("%d", &pos);
                        val = searchByPos(arr, &n, pos);
                        if (val != -1)
                                printf("Value at position %d is %d", pos, val);
                        else
                                printf("INVALID POSITOIN\n");
                        break;

                case 8:
                        reverse(arr, n);
                        printf("Array reversed successfully\n");
                        break;

                case 9:
                        display(arr, n);
                        break;

                case 10:
                        printf("EXITING---\n");
                        break;

                default:
                        printf("INVALID CHOICE!! PLZ TRY AGAIN");
                }
        } while (choice != 10);

        if (type == 2)
                free(dynamic);
        return 0;

        return 0;
}