// Write a C program to simulate the working of a circular Queue of
// integers. Represent circular queue element as a structure and use
// array of structures as your implementation method. Start and end of
// the circular queue must be identified by an empty array element.

#include <stdio.h>
#define MAX_SIZE 10

struct CircularQueue
{
    int data; // data to be stored in the queue
    int next; // index of the next element in the queue
};

struct CircularQueue queue[MAX_SIZE];
int start = -1, end = -1;

// Function to insert an element into the queue
void enqueue(int value)
{
    if ((start == 0 && end == MAX_SIZE - 1) || (start == end + 1))
    {
        printf("Circular Queue is full\n");
        return;
    }
    if (start == -1)
    {
        start = end = 0;
        queue[end].data = value;
        queue[end].next = end + 1;
    }
    else if (end == MAX_SIZE - 1 && start != 0)
    {
        end = 0;
        queue[end].data = value;
        queue[end].next = end + 1;
    }
    else
    {
        end++;
        queue[end].data = value;
        queue[end].next = end + 1;
    }
}

// Function to remove an element from the queue
int dequeue()
{
    int value;
    if (start == -1) // queue is empty 
    {
        printf("Circular Queue is empty\n");
        return -1;
    }
    value = queue[start].data; 
    if (start == end) // only one element in the queue
    {
        start = end = -1; 
    }
    else if (start == MAX_SIZE - 1) // last element in the queue
    {
        start = 0; 
    }
    else // more than one element in the queue
    {
        start++; 
    }
    return value; 
}

// Function to display the elements in the queue
void display()
{
    int i;
    if (start == -1)
    {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Elements in the Circular Queue are: ");
    i = start;
    while (i != end)
    {
        printf("%d ", queue[i].data);
        i = queue[i].next;
    }
    printf("%d\n", queue[i].data);
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("1. Insert element in the queue\n");
        printf("2. Delete element from the queue\n");
        printf("3. Display elements in the queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            value = dequeue();
            if (value != -1)
            {
                printf("The deleted element is: %d\n", value);
            }
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
    return 0;
}
