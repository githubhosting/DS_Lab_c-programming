// Write a C program to support the following operations on a doubly
// linked list.
// a) Insert a new node to the left of the node whose key value is read
// as an input.
// b) Delete a node with given data, if it is found otherwise display
// appropriate error message.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *head = NULL;

void insert(int data, int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *current = head;

    while (current->next != NULL && current->data != key)
        current = current->next;

    if (current->data == NULL)
    {
        printf("Key not found\n");
        return;
    }

    newNode->prev = current->prev;
    current->prev = newNode;

    newNode->next = current;

    if (newNode->prev != NULL)
        newNode->prev->next = newNode;
    else
        head = newNode;
}

void delete(int data)
{
    Node *temp = head, *prev = NULL, *next = NULL;

    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Data not found\n");
        return;
    }

    next = temp->next;

    if (prev == NULL)
        head = next;
    else
        prev->next = next;

    if (next != NULL)
        next->prev = prev;

    free(temp);
}

void display()
{
    Node *ptr = head;
    printf("\nList: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    int choice, value, key;
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            printf("Enter the key: ");
            scanf("%d", &key);
            insert(value, key);
            break;
        case 2:
            printf("Enter the value to be deleted: ");
            scanf("%d", &value);
            delete(value);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
