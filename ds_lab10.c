// Write a C program to maintain a stack of integers using linked implementation method.

#include <stdio.h>
#include <stdlib.h>

struct StackNode
{
    int data;
    struct StackNode *next;
};

struct StackNode *top = NULL;

// Function to add an item to stack. It increases top by 1
void push(int item)
{
    struct StackNode *temp = (struct StackNode *)malloc(sizeof(struct StackNode));
    temp->data = item;
    temp->next = top;
    top = temp;
}

// Function to remove an item from stack. It decreases top by 1
int pop()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    int item = top->data;
    struct StackNode *temp = top;
    top = top->next;
    free(temp);
    return item;
}

// Function to return the top from stack without removing it
int peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Function to display the stack
void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct StackNode *temp = top;
    printf("Stack: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be pushed: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            item = pop();
            if (item != -1)
            {
                printf("Popped item is: %d\n", item);
            }
            break;
        case 3:
            item = peek();
            if (item != -1)
            {
                printf("Top item is: %d\n", item);
            }
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
