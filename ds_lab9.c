// Write a program to create a singly linked list that maintains a
// list of names in alphabetical order. Implement the following
// operations on the list.
// a. Insert a new name
// b. Delete a specified name

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char name[50];
    struct node *next;
} Node;

Node *head = NULL; // head of the list

void insert(char *name)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name); // copy name to newNode->name
    newNode->next = NULL;
    if (head == NULL || strcmp(head->name, name) >= 0) // check if the list is empty or the new name is smaller than the first name
    {
        newNode->next = head; // insert the new node at the beginning
        head = newNode;       // update the head
    }
    else
    {
        Node *current = head;                                                  // current is the node before the insertion point
        while (current->next != NULL && strcmp(current->next->name, name) < 0) // finding the insertion point
            current = current->next;                                           // move to the next node
        newNode->next = current->next;                                         // insert the new node after current
        current->next = newNode;                                               // update the next pointer of current
    }
}

void delete(char *name)
{
    Node *temp = head, *prev;
    if (temp != NULL && strcmp(temp->name, name) == 0) // check if the first node is the one to be deleted
    {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && strcmp(temp->name, name) != 0) // find the node to be deleted
    {
        prev = temp;       // keep track of the previous node
        temp = temp->next; // move to the next node
    }
    if (temp == NULL) // check if the node is not found
        return;
    prev->next = temp->next; // update the next pointer of the previous node
    free(temp);              // free the memory
}
void display()
{
    Node *ptr = head;
    printf("\nNames in the List: ");
    while (ptr != NULL)
    {
        printf("%s ", ptr->name);
        ptr = ptr->next;
    }
}

int main()
{
    int choice;
    char name[50];
    while (1)
    {
        printf("\n1.Insert a name ");
        printf("\n2.Delete a name ");
        printf("\n3.Display the list ");
        printf("\n4.Exit ");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the name to be inserted : ");
            scanf("%s", name);
            insert(name);
            break;
        case 2:
            printf("Enter the name to be deleted : ");
            scanf("%s", name);
            delete (name);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice ");
        }
    }
}
