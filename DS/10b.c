// CIRCULAR QUEUE

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct
{
    int *arr;
    int front, rear, size;
} Cqueue;

void initCqueue(Cqueue *q, int size)
{
    q->size = size;
    q->arr = (int *)malloc(sizeof(int) * size);
    q->front = q->rear = -1;
}

int isEmpty(Cqueue *q) { return q->front == -1; }

int isFull(Cqueue *q) { return (q->rear + 1) % q->size == q->front; }

void enqueue(Cqueue *q, int x)
{
    if (isFull(q))
    {
        printf("QUEUE OVERFLOW\n");
        exit(1);
    }
    if (isEmpty(q))
        q->front = 0;
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = x;
}

void dequeue(Cqueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
        exit(1);
    }
    printf("Deleted %d\n", q->arr[q->front]);
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % q->size;
}

void display(Cqueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue empty\n");
        exit(1);
    }
    int i = q->front;
    while (1)
    {
        printf("%d ", q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main()
{
    Cqueue q;
    int choice, x, type, size;
    printf("1.Static Circular Queue\n2.Dynamic Circular Queue\n3.Choice: ");
    scanf("%d", &type);

    size = (type == 1) ? MAX : (printf("Enter size: "), scanf("%d", &size), size);
    initCqueue(&q, size);

    do
    {
        printf("1.Enqueue 2.Dequeue 3.Display 0.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            enqueue(&q, x);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        }
    } while (choice != 0);
    free(q.arr);
    return 0;
}