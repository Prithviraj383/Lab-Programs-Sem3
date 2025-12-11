#include <stdio.h>
#include <stdlib.h>

#define MAX 5

/* -------- Static Stack (Array) -------- */

typedef struct
{
    int a[MAX];
    int top;
} StaticStack;

void initStatic(StaticStack *s) { s->top = -1; }
int isStaticEmpty(StaticStack *s) { return s->top == -1; }
int isStaticFull(StaticStack *s) { return s->top == MAX - 1; }

void pushStatic(StaticStack *s, int x)
{
    if (isStaticFull(s))
    {
        printf("Overflow (static)\n");
        return;
    }
    s->a[++s->top] = x;
}

int popStatic(StaticStack *s)
{
    if (isStaticEmpty(s))
    {
        printf("Underflow (static)\n");
        return -1;
    }
    return s->a[s->top--];
}

int peekStatic(StaticStack *s)
{
    if (isStaticEmpty(s))
    {
        printf("Empty (static)\n");
        return -1;
    }
    return s->a[s->top];
}

void displayStatic(StaticStack *s)
{
    if (isStaticEmpty(s))
    {
        printf("Empty (static)\n");
        return;
    }
    printf("Static stack (top -> bottom): ");
    for (int i = s->top; i >= 0; --i)
        printf("%d ", s->a[i]);
    printf("\n");
}

/* -------- Dynamic Stack (Linked List) -------- */

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} DynamicStack;

void initDynamic(DynamicStack *s) { s->top = NULL; }
int isDynamicEmpty(DynamicStack *s) { return s->top == NULL; }

void pushDynamic(DynamicStack *s, int x)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n)
    {
        printf("Malloc failed\n");
        return;
    }
    n->data = x;
    n->next = s->top;
    s->top = n;
}

int popDynamic(DynamicStack *s)
{
    if (isDynamicEmpty(s))
    {
        printf("Underflow (dynamic)\n");
        return -1;
    }
    Node *temp = s->top;
    int x = temp->data;
    s->top = temp->next;
    free(temp);
    return x;
}

int peekDynamic(DynamicStack *s)
{
    if (isDynamicEmpty(s))
    {
        printf("Empty (dynamic)\n");
        return -1;
    }
    return s->top->data;
}

void displayDynamic(DynamicStack *s)
{
    if (isDynamicEmpty(s))
    {
        printf("Empty (dynamic)\n");
        return;
    }
    printf("Dynamic stack (top -> bottom): ");
    for (Node *p = s->top; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}

void freeDynamic(DynamicStack *s)
{
    while (!isDynamicEmpty(s))
        popDynamic(s);
}

/* -------- Menus -------- */

void staticMenu(StaticStack *s)
{
    int ch, x;
    do
    {
        printf("\n-- Static Stack --\n1.Push 2.Pop 3.Peek 4.Display 5.Back\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Value: ");
            scanf("%d", &x);
            pushStatic(s, x);
            break;
        case 2:
            x = popStatic(s);
            if (x != -1)
                printf("Popped: %d\n", x);
            break;
        case 3:
            x = peekStatic(s);
            if (x != -1)
                printf("Top: %d\n", x);
            break;
        case 4:
            displayStatic(s);
            break;
        }
    } while (ch != 5);
}

void dynamicMenu(DynamicStack *s)
{
    int ch, x;
    do
    {
        printf("\n-- Dynamic Stack --\n1.Push 2.Pop 3.Peek 4.Display 5.Back\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Value: ");
            scanf("%d", &x);
            pushDynamic(s, x);
            break;
        case 2:
            x = popDynamic(s);
            if (x != -1)
                printf("Popped: %d\n", x);
            break;
        case 3:
            x = peekDynamic(s);
            if (x != -1)
                printf("Top: %d\n", x);
            break;
        case 4:
            displayDynamic(s);
            break;
        }
    } while (ch != 5);
}

/* -------- main -------- */

int main(void)
{
    StaticStack sArr;
    initStatic(&sArr);
    DynamicStack sList;
    initDynamic(&sList);

    int ch;
    do
    {
        printf("\n==== Stack Implementation ====\n");
        printf("1. Static stack (array)\n2. Dynamic stack (linked list)\n3. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            staticMenu(&sArr);
            break;
        case 2:
            dynamicMenu(&sList);
            break;
        }
    } while (ch != 3);

    freeDynamic(&sList);
    return 0;
}
