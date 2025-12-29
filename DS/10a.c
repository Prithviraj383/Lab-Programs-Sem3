// SIMPLE QUEUE
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct
{
    int *arr;
    int front, rear, size;
} queue;

void initqueue(queue *q, int size)
{
    q->size = size;
    q->arr = (int *)malloc(sizeof(int) * size);
    q->front = -1;
    q->rear = -1;
}

int isEmpty(queue *q) { return q->front == -1 || q->front > q->rear; }

int isFull(queue *q) { return q->rear == q->size - 1; }

void enqueue(queue *q, int x)
{
    if (isFull(q))
    {
        printf("QUEUE OVERFLOW\n");
        exit(1);
    }
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = x;
}

void dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
        exit(1);
    }
    printf("Deleted %d\n", q->arr[q->front++]);
}

void display(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue empty\n");
        exit(1);
    }
    for (int i = q->front; i <= q->rear; ++i)
        printf("%d ", q->arr[i]);
    printf("\n");
}

int main()
{
    queue q;
    int choice, x, type, size;
    printf("1. Static Queue\n2.Dynamic Queue\n3.Choice: ");
    scanf("%d", &type);

    size = (type == 1) ? MAX : (printf("Enter size: "), scanf("%d", &size), size);
    initqueue(&q, size);

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