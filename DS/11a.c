#include <stdio.h>
#include <stdlib.h>
#define max_size 5
typedef struct
{
    int q[max_size];
    int f, r;
} queue;

void insert_rear(queue *qu, int x)
{
    if (qu->r == max_size - 1)
    {
        printf("Queue overflow\n");
        exit(0);
    }
    else
    {
        ++(qu->r);
        qu->q[qu->r] = x;
        if (qu->f == -1)
            qu->f = 0;
    }
    printf("\n");
}

void insert_front(queue *qu, int x)
{
    if (qu->f == 0)
    {
        printf("Cannot insert from front end\n");
        exit(0);
    }
    if (qu->f == -1)
    {
        (qu->f)++;
        qu->q[qu->f] = x;
        qu->r = 0;
    }
    else
    {
        (qu->f)--;
        qu->q[qu->f] = x;
    }
    printf("\n");
}

void delete_rear(queue *qu)
{
    int x = -1;
    if (qu->r == -1 || qu->f > qu->r)
    {
        printf("Queue is empty\n");
        exit(0);
    }
    else
    {
        x = qu->q[qu->r];
        (qu->r)--;
        printf("Deleted item is %d\n", x);
    }
}

void delete_front(queue *qu)
{
    int x = -1;
    if (qu->f == -1 || qu->f > qu->r)
    {
        printf("Queue is empty\n");
        exit(0);
    }
    else
    {
        x = qu->q[qu->f];
        (qu->f)++;
        printf("Deleted item is %d\n", x);
    }
}

void display(queue *qu)
{
    if (qu->f == -1 || qu->f > qu->r)
    {
        printf("Queue is empty\n");
        exit(0);
    }
    printf("Contents of the queue are: \n");
    for (int i = qu->f; i <= qu->r; ++i)
        printf("%d ", qu->q[i]);
    printf("\n");
}

int main()
{

    queue q;
    q.f = q.r = -1;
    int x, choice;
    for (;;)
    {
        printf("1.InsertFront 2.InsertRear 3.DeleteFront 4. DeleteRear 5.Display 6.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &x);
            insert_front(&q, x);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &x);
            insert_rear(&q, x);
            break;
        case 3:
            delete_front(&q);
            break;
        case 4:
            delete_rear(&q);
            break;
        case 5:
            display(&q);
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}