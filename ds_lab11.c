// Write a C program to support the following operations on a doubly
// linked list.
// a) Insert a new node to the left of the node whose key value is read
// as an input.
// b) Delete a node with given data, if it is found otherwise display
// appropriate error message.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void insert(int data);
void display();
void delete(int data);

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n1.Insert an element ");
        printf("\n2.Display the list ");
        printf("\n3.Delete an element ");
        printf("\n4.Exit ");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data : ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter the data : ");
            scanf("%d", &data);
            delete (data);
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice ");
        }
    }
}

void insert(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    printf("List is : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void delete(int data)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            if (temp == head)
            {
                head = temp->next;
                head->prev = NULL;
            }
            else if (temp == tail)
            {
                tail = temp->prev;
                tail->next = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("Element deleted");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found");
}
