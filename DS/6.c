#include <stdio.h>
#include <stdlib.h>

typedef struct node{
        int val;
        struct node *next;
}node;

node *header;

void init(){
        header = (node *)malloc(sizeof(node));
        header->val = -1;
        header->next = header;
}

node *createNode(int x){
        node *newNode = (node *)malloc(sizeof(node));
        newNode->val = x;
        newNode->next = NULL;
        return newNode;
}

void display(){

        if(!header->next){
        printf("LIST IS EMPTY\n");
        return;
        }

        node *temp = header->next;
        while(temp != header){
                printf("%d -> ", temp->val);
                temp = temp->next;
        }
        printf("JOINED TO DUMMY\n");
}

void insertFront(int x){
        node *t = (node *)malloc(sizeof(node));
        t->val = x;
        t->next = header->next;
        header->next = t;
}

void insertRear(int x){
        node *newNode = createNode(x);
        node *temp = header;
        while(temp->next!=header) temp = temp->next;
        temp->next = newNode;
        newNode->next = header;
}

void deleteFront(){
        if(header->next == header){
                printf("LIST IS EMPTY\n");
                return;
        }
        node *temp = header->next;
        header->next = temp->next;
        free(temp);
        printf("FRONT NODE DELETED\n");
}

void deleteRear(){
        if(header->next == header){
                printf("LIST IS EMPTY\n");
                return;
        }
        node *prev = header, *temp = header->next;
        while(temp->next != header){
                prev = temp;
                temp = temp->next;
        }
        free(temp);
        prev->next = header;
        printf("REAR NODE DELETED\n");
}

void insertPos(int x, int pos){
        node *temp = header;
        for(int i=1;i<pos && temp->next != header;++i) temp = temp->next;

        node *newNode = createNode(x);
        newNode->next = temp->next;
        temp->next = newNode;
}


void deletePos(int pos){
        if(header->next == header){
                printf("LIST IS EMPTY\n");
                return;
        }
        node *temp = header, *del;
        for(int i=1;i<pos && temp->next != header;++i) temp = temp->next;
        del = temp->next;
        if(del == header){
                printf("INVALID POSITION\n");
                return;
        }
        temp->next = del->next;
        free(del);
}

void deleteByKey(int key){
        node *temp = header, *del;
        while(temp->next != header && temp->next->val!=key) temp = temp->next;
        if(temp->next == header){
                printf("KEY NOT FOUND\n");
                return;
        }
        del = temp->next;
        temp->next = del->next;
        free(del);
        printf("Node with key %d is deleted\n", key);
}

void search(int key){
        node *temp = header->next;
        int pos = 1;
        while(temp != header){
                if(temp->val == key){
                        printf("Key found at pos %d\n", pos);
                        return;
                }
                pos++;
                temp = temp->next;
        }
        printf("Key not found\n");
}

void insertOrdered(int x){
        node *temp = header;
        while(temp->next != header && temp->next->val < x) temp = temp->next;

        node *newNode = createNode(x);
        newNode->next = temp->next;
        temp->next = newNode;
}

void reverse(){
        if(header->next == header || header->next->next == header) return;
        node *prev = NULL, *curr = header->next, *nxt = NULL;
        while(curr!=header){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
        }
        header->next->next = header;
        header->next = prev;
}

node *copyList(){
        node *newHeader = (node *)malloc(sizeof(node));
        newHeader->val = -1;
        newHeader->next = newHeader;

        node *src = header->next;
        node *dst = newHeader;
        while(src != header){
                node *newNode = createNode(src->val);
                dst->next = newNode;
                dst = newNode;
                src = src->next;
        }
        dst->next = newHeader;
        return newHeader;
}

int main(){
        init();
        int choice, data, pos;
        node *copy;
        while(1){
                printf("\n---------CIRCULAR SLL MENU--------\n");
                printf("1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Insert at position\n6.Delete at position\n7.Delete by key\n8.Search\n9.Insert Ordered\n10.Reverse\n11.Copy List\n12.Display\n13.Exit\n");
                printf("Enter choice:");
                scanf("%d",&choice);

                switch(choice){
                        case 1: printf("Enter data :");
                                                scanf("%d", &data);
                                                insertFront(data);
                                                break;

                        case 2: printf("Enter data :");
                                                scanf("%d", &data);
                                                insertRear(data);
                                                break;

                        case 3: deleteFront();
                                                break;

                        case 4:deleteRear();
                                                break;

                        case 5: printf("Enter data and Position:");
                                                scanf("%d %d", &data, &pos);
                                                insertPos(data, pos);
                                                break;

                        case 6: printf("Enter position :");
                                                scanf("%d", &pos);
                                                deletePos(pos);
                                                break;

                        case 7: printf("Enter key :");
                                                scanf("%d", &data);
                                                deleteByKey(data);
                                                break;

                        case 8: printf("Enter key :");
                                                scanf("%d", &data);
                                                search(data);
                                                break;

                        case 9: printf("Enter data :");
                                                scanf("%d", &data);
                                                insertOrdered(data);
                                                break;

                        case 10: reverse();
                                                  printf("List reversed :\n");
                                                  break;

                        case 11: copy = copyList();
                                                  printf("Copy created.(Not displayed here)\n");
                                                  break;

                        case 12: display();
                                                break;

                        case 13: exit(0);

                        default : printf("Invalid choice .\n");
                }
        }
        return 0;
}