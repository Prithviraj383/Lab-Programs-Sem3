#include <stdio.h>
#include <stdlib.h>

#define MAX 5

/* ================= STATIC QUEUE (ARRAY) ================= */

typedef struct {
    int arr[MAX];
    int front, rear;
} StaticQueue;

void initStatic(StaticQueue *q) {
    q->front = q->rear = -1;
}

int staticEmpty(StaticQueue *q) {
    return q->front == -1 || q->front > q->rear;
}

int staticFull(StaticQueue *q) {
    return q->rear == MAX - 1;
}

void staticEnqueue(StaticQueue *q, int x) {
    if (staticFull(q)) {
        printf("Static Queue Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = x;
}

void staticDequeue(StaticQueue *q) {
    if (staticEmpty(q)) {
        printf("Static Queue Underflow\n");
        return;
    }
    printf("Deleted %d\n", q->arr[q->front++]);
}

void staticDisplay(StaticQueue *q) {
    if (staticEmpty(q)) {
        printf("Static Queue Empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

void staticMenu(StaticQueue *q) {
    int ch, x;
    do {
        printf("\n--- Static Queue Menu ---\n");
        printf("1.Enqueue  2.Dequeue  3.Display  0.Back\n");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            staticEnqueue(q, x);
            break;
        case 2:
            staticDequeue(q);
            break;
        case 3:
            staticDisplay(q);
            break;
        }
    } while (ch != 0);
}

/* ================= DYNAMIC QUEUE (LINKED LIST) ================= */

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front, *rear;
} DynamicQueue;

void initDynamic(DynamicQueue *q) {
    q->front = q->rear = NULL;
}

void dynamicEnqueue(DynamicQueue *q, int x) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void dynamicDequeue(DynamicQueue *q) {
    if (q->front == NULL) {
        printf("Dynamic Queue Underflow\n");
        return;
    }
    Node *temp = q->front;
    printf("Deleted %d\n", temp->data);
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

void dynamicDisplay(DynamicQueue *q) {
    if (q->front == NULL) {
        printf("Dynamic Queue Empty\n");
        return;
    }
    Node *temp = q->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void dynamicMenu(DynamicQueue *q) {
    int ch, x;
    do {
        printf("\n--- Dynamic Queue Menu ---\n");
        printf("1.Enqueue  2.Dequeue  3.Display  0.Back\n");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            dynamicEnqueue(q, x);
            break;
        case 2:
            dynamicDequeue(q);
            break;
        case 3:
            dynamicDisplay(q);
            break;
        }
    } while (ch != 0);
}

/* ================= MAIN MENU ================= */

int main() {
    int ch;
    StaticQueue sQ;
    DynamicQueue dQ;

    initStatic(&sQ);
    initDynamic(&dQ);

    do {
        printf("\n==== Queue Implementation ====\n");
        printf("1. Static Queue (Array)\n");
        printf("2. Dynamic Queue (Linked List)\n");
        printf("3. Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            staticMenu(&sQ);
            break;
        case 2:
            dynamicMenu(&dQ);
            break;
        }
    } while (ch != 3);

    return 0;
}