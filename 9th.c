// Write a program to implement tree traversals using linked list.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Representation of a node in the binary tree
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Global pointer to represent the root of the binary tree
struct node *root = NULL;

// Function to create a new node
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) { // Error checking for malloc
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Representation of a simple queue structure for level order traversal
struct queue
{
    int front, rear, size;
    struct node **arr;
};

// Function to create a queue
struct queue *createQueue()
{
    struct queue *newQueue = (struct queue *)malloc(sizeof(struct queue));
    if (newQueue == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newQueue->front = -1;
    newQueue->rear = 0;
    newQueue->size = 0;
    newQueue->arr = (struct node **)malloc(100 * sizeof(struct node *));
    if (newQueue->arr == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    return newQueue;
}

// Function to add an element to the queue
void enqueue(struct queue *queue, struct node *temp)
{
    queue->arr[queue->rear++] = temp;
    queue->size++;
}

// Function to remove an element from the queue
struct node *dequeue(struct queue *queue)
{
    queue->size--;
    return queue->arr[++queue->front];
}

// Function to insert nodes into a binary tree in a level-order manner
void insertNode(int data)
{
    struct node *newNode = createNode(data);

    if (root == NULL) // If tree is empty, set the first node as root
    {
        root = newNode;
        return;
    }
    struct queue *queue = createQueue();
    enqueue(queue, root);

    while (true)
    {
        struct node *node = dequeue(queue);

        // Check if the left child is empty
        if (node->left == NULL)
        {
            node->left = newNode;
            enqueue(queue, node->left);
            break;
        }
        else
        {
            enqueue(queue, node->left);
        }

        // Check if the right child is empty
        if (node->right == NULL)
        {
            node->right = newNode;
            enqueue(queue, node->right);
            break;
        }
        else
        {
            enqueue(queue, node->right);
        }
    }
}

// Function for an in-order traversal of the binary tree
void inorderTraversal(struct node *node)
{
    if (node == NULL)
        return;

    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

int main()
{
    insertNode(1);
    printf("Binary tree after inserting 1: ");
    inorderTraversal(root);
    printf("\n");

    insertNode(2);
    insertNode(3);
    printf("Binary tree after inserting 2 and 3: ");
    inorderTraversal(root);
    printf("\n");

    insertNode(4);
    insertNode(5);
    printf("Binary tree after inserting 4 and 5: ");
    inorderTraversal(root);
    printf("\n");

    insertNode(6);
    insertNode(7);
    printf("Binary tree after inserting 6 and 7: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
