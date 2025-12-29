#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct pqueue
{
    int *data;
    int *priority;
    int size;
    int count;
};

void insert(struct pqueue *q, int x, int p)
{
    if (q->count == q->size)
    {
        printf("Queue overflow\n");
        return;
    }
    q->data[q->count] = x;
    q->priority[q->count] = p;
    q->count++;
}

void delete(struct pqueue *q)
{
    if (q->count == 0)
    {
        printf("Queue underflow\n");
        return;
    }

    int pos = 0;
    for (int i = 1; i < q->count; i++)
    {
        if (q->priority[i] < q->priority[pos])
        {
            pos = i;
        }
    }

    printf("Deleted element: %d\n", q->data[pos]);

    for (int i = pos; i < q->count - 1; i++)
    {
        q->data[i] = q->data[i + 1];
        q->priority[i] = q->priority[i + 1];
    }

    q->count--;
}

void display(struct pqueue *q)
{
    if (q->count == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Element\tPriority\n");
    for (int i = 0; i < q->count; i++)
    {
        printf("%d\t%d\n", q->data[i], q->priority[i]);
    }
}

int main()
{
    struct pqueue q;
    int ch, x, p, type;

    q.count = 0;

    printf("1. Static priority queue\n2. Dynamic priority queue\n");
    scanf("%d", &type);

    if (type == 1)
    {
        q.size = MAX;
    }
    else
    {
        printf("Enter queue size: ");
        scanf("%d", &q.size);
    }

    q.data = (int *)malloc(q.size * sizeof(int));
    q.priority = (int *)malloc(q.size * sizeof(int));

    if (q.data == NULL || q.priority == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (1)
    {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element and priority: ");
            scanf("%d%d", &x, &p);
            insert(&q, x, p);
            break;

        case 2:
            delete(&q);
            break;

        case 3:
            display(&q);
            break;

        case 4:
            free(q.data);
            free(q.priority);
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}