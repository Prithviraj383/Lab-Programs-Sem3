#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node *createHeader()
{
    Node *header = (Node *)malloc(sizeof(Node));
    if (!header)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    header->data = 0; // Not used; just a header
    header->next = header;
    header->prev = header;
    return header;
}

int isEmpty(Node *header)
{
    return header->next == header;
}

void display(Node *header)
{
    if (isEmpty(header))
    {
        printf("List is empty.\n");
        return;
    }
    Node *temp = header->next;
    printf("List: ");
    while (temp != header)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int length(Node *header)
{
    int len = 0;
    Node *temp = header->next;
    while (temp != header)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

/* ----------- Basic insert helpers ---------- */

void insertFront(Node *header, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;

    newNode->next = header->next;
    newNode->prev = header;
    header->next->prev = newNode;
    header->next = newNode;
}

void insertRear(Node *header, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;

    newNode->next = header;
    newNode->prev = header->prev;
    header->prev->next = newNode;
    header->prev = newNode;
}

/* Insert at position (1-based index) */
void insertAtPos(Node *header, int data, int pos)
{
    int len = length(header);
    if (pos < 1 || pos > len + 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        insertFront(header, data);
        return;
    }

    // Find node currently at position pos (or header if pos==len+1)
    Node *temp = header->next;
    int i;
    for (i = 1; i < pos && temp != header; i++)
    {
        temp = temp->next;
    }
    // temp is node at pos (or header if inserting at end)
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;

    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

/* Insert after first occurrence of key */
void insertAfterKey(Node *header, int key, int data)
{
    if (isEmpty(header))
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = header->next;
    while (temp != header && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == header)
    {
        printf("Key %d not found.\n", key);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

/* Insert before first occurrence of key */
void insertBeforeKey(Node *header, int key, int data)
{
    if (isEmpty(header))
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = header->next;
    while (temp != header && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == header)
    {
        printf("Key %d not found.\n", key);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;

    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

/* ----------- Deletion helpers ---------- */

void deleteFront(Node *header)
{
    if (isEmpty(header))
    {
        printf("List is empty.\n");
        return;
    }
    Node *temp = header->next;
    header->next = temp->next;
    temp->next->prev = header;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void deleteRear(Node *header)
{
    if (isEmpty(header))
    {
        printf("List is empty.\n");
        return;
    }
    Node *temp = header->prev;
    header->prev = temp->prev;
    temp->prev->next = header;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void deleteAtPos(Node *header, int pos)
{
    int len = length(header);
    if (pos < 1 || pos > len)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        deleteFront(header);
        return;
    }

    Node *temp = header->next;
    int i;
    for (i = 1; i < pos; i++)
    {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("Deleted element at position %d: %d\n", pos, temp->data);
    free(temp);
}

/* Delete by key (first occurrence) */
void deleteByKey(Node *header, int key)
{
    if (isEmpty(header))
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = header->next;
    while (temp != header && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == header)
    {
        printf("Key %d not found.\n", key);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("Deleted node with key %d\n", key);
    free(temp);
}

/* ----------- Search ---------- */

void searchByKey(Node *header, int key)
{
    if (isEmpty(header))
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = header->next;
    int pos = 1;
    while (temp != header)
    {
        if (temp->data == key)
        {
            printf("Key %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Key %d not found in the list.\n", key);
}

/* ----------- Ordered list (ascending) ---------- */

void sortedInsert(Node *header, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;

    // If list is empty or first element is >= data, insert at front
    if (isEmpty(header) || header->next->data >= data)
    {
        newNode->next = header->next;
        newNode->prev = header;
        header->next->prev = newNode;
        header->next = newNode;
        return;
    }

    Node *temp = header->next;
    while (temp->next != header && temp->next->data < data)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

/* Create ordered list from scratch */
void createOrderedList(Node *header)
{
    int n, i, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Clear existing list
    while (!isEmpty(header))
    {
        deleteFront(header);
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        sortedInsert(header, val);
    }
    printf("Ordered list created.\n");
}

/* ----------- Reverse list ---------- */

void reverseList(Node *header)
{
    if (isEmpty(header))
    {
        printf("List is empty.\n");
        return;
    }

    Node *current = header;
    Node *temp;

    // For circular doubly list with header, swap next/prev for all nodes including header
    do
    {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    } while (current != header);

    printf("List reversed.\n");
}

/* ----------- Copy list ---------- */

Node *copyList(Node *header)
{
    Node *newHeader = createHeader();
    Node *temp = header->next;

    while (temp != header)
    {
        insertRear(newHeader, temp->data);
        temp = temp->next;
    }

    printf("Copy of the list created.\n");
    return newHeader;
}

/* ----------- Free entire list ---------- */

void freeList(Node *header)
{
    Node *temp = header->next;
    while (temp != header)
    {
        Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(header);
}

/* ----------- Menus ---------- */

void insertionMenu(Node *header)
{
    int ch, data, pos, key;
    printf("\n--- Insertion Menu ---\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at specified position (index)\n");
    printf("4. Insert after a node (by key)\n");
    printf("5. Insert before a node (by key)\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("Enter data: ");
        scanf("%d", &data);
        insertFront(header, data);
        break;
    case 2:
        printf("Enter data: ");
        scanf("%d", &data);
        insertRear(header, data);
        break;
    case 3:
        printf("Enter data: ");
        scanf("%d", &data);
        printf("Enter position (1-based): ");
        scanf("%d", &pos);
        insertAtPos(header, data, pos);
        break;
    case 4:
        printf("Enter key after which to insert: ");
        scanf("%d", &key);
        printf("Enter data: ");
        scanf("%d", &data);
        insertAfterKey(header, key, data);
        break;
    case 5:
        printf("Enter key before which to insert: ");
        scanf("%d", &key);
        printf("Enter data: ");
        scanf("%d", &data);
        insertBeforeKey(header, key, data);
        break;
    default:
        printf("Invalid choice.\n");
    }
}

void deletionMenu(Node *header)
{
    int ch, pos, key;
    printf("\n--- Deletion Menu ---\n");
    printf("1. Delete at beginning\n");
    printf("2. Delete at end\n");
    printf("3. Delete at specified position (index)\n");
    printf("4. Delete by key\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        deleteFront(header);
        break;
    case 2:
        deleteRear(header);
        break;
    case 3:
        printf("Enter position (1-based): ");
        scanf("%d", &pos);
        deleteAtPos(header, pos);
        break;
    case 4:
        printf("Enter key to delete: ");
        scanf("%d", &key);
        deleteByKey(header, key);
        break;
    default:
        printf("Invalid choice.\n");
    }
}

/* ----------- main ---------- */

int main()
{
    Node *header = createHeader();
    Node *copyHeader = NULL; // For storing copy if created
    int choice, key;

    while (1)
    {
        printf("\n==== Circular Doubly Linked List (Header) ====\n");
        printf("1. Insertion operations\n");
        printf("2. Deletion operations\n");
        printf("3. Search by key\n");
        printf("4. Create ordered list\n");
        printf("5. Reverse list\n");
        printf("6. Create copy of list\n");
        printf("7. Display original list\n");
        printf("8. Display copied list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertionMenu(header);
            break;
        case 2:
            deletionMenu(header);
            break;
        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            searchByKey(header, key);
            break;
        case 4:
            createOrderedList(header);
            break;
        case 5:
            reverseList(header);
            break;
        case 6:
            if (copyHeader != NULL)
            {
                freeList(copyHeader);
            }
            copyHeader = copyList(header);
            break;
        case 7:
            printf("Original ");
            display(header);
            break;
        case 8:
            if (copyHeader == NULL)
            {
                printf("Copy list not created yet.\n");
            }
            else
            {
                printf("Copy ");
                display(copyHeader);
            }
            break;
        case 9:
            freeList(header);
            if (copyHeader != NULL)
            {
                freeList(copyHeader);
            }
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}