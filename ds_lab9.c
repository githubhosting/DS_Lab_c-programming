// Write a program to create a singly linked list that maintains a
// list of names in alphabetical order. Implement the following
// operations on the list.
// a. Insert a new name
// b. Delete a specified name

#include <stdio.h>
#include <stdlib.h>

struct stud
{
    int id;
    char name[20];
    int sem;
    struct stud *next;
};

typedef struct stud NODE;

NODE *head;
NODE *insert_f();

void main()
{
    int ch;
    head = NULL;
    while (1)
    {
        printf("1.Insert at front \n");
        printf("2.Display \n");
        printf("3.Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = insert_f();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        }
    }
}

NODE *insert_f()
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    printf("Enter the id : ");
    scanf("%d", &temp->id);
    printf("Enter the name : ");
    scanf("%s", temp->name);
    printf("Enter the sem : ");
    scanf("%d", &temp->sem);
    temp->next = head;
    return temp;
}

void display()
{
    NODE *temp;
    if (head == NULL)
    {
        printf("List is empty \n");
        return;
    }
    temp = head;
    printf("The list is : \n");
    printf("ID \t NAME \t SEM \n");
    while (temp != NULL)
    {
        printf("%d \t %s \t %d \t \n", temp->id, temp->name, temp->sem);
        temp = temp->next;
    }
}

