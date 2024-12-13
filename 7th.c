#include <stdio.h>
#include <stdlib.h>

// Declaration of struct type node
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Function to insert the element into the queue
void enqueue(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode) // Memory allocation check
    {
        printf("\nMemory allocation failed.\n");
        return;
    }

    newnode->data = x;
    newnode->next = NULL;

    if (rear == NULL) // Empty queue case
    {
        front = rear = newnode;
        rear->next = front; // Circular link
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front; // Circular link
    }

    printf("\nInserted %d into the queue.\n", x);
}

// Function to delete an element from the queue
void dequeue()
{
    if (front == NULL)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    struct node *temp = front;

    // Single element case
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    printf("\nDeleted %d from the queue.\n", temp->data);
    free(temp);
}

// Function to get the front of the queue
void peek()
{
    if (front == NULL)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\nThe front element is %d\n", front->data);
    }
}

// Function to display all elements of the queue
void display()
{
    if (front == NULL)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    struct node *temp = front;
    printf("\nThe elements in the queue are: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

// Main function to test circular queue operations
void main()
{
    enqueue(34);
    enqueue(10);
    enqueue(23);

    display();
    dequeue();
    peek();
}
