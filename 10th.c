// Write a program to implement BFS.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n; // Number of vertices
int adj[MAX][MAX]; // Adjacency matrix
int state[MAX]; // State of each node during traversal
int queue[MAX], front = -1, rear = -1;

// Function prototypes
void create_graph();
void BFS_Traversal();
void BFS(int v);
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

int main()
{
    create_graph();
    BFS_Traversal();
    return 0;
}

// Create the graph by user input
void create_graph()
{
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix with zeros
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj[i][j] = 0;

    int origin, destin;
    printf("Enter edges (enter -1 -1 to stop):\n");
    while (1)
    {
        printf("Edge (origin destination): ");
        scanf("%d %d", &origin, &destin);
        if (origin == -1 && destin == -1)
            break;

        if (origin >= n || destin >= n || origin < 0 || destin < 0)
        {
            printf("Invalid edge!\n");
            continue;
        }

        // Assuming an undirected graph
        adj[origin][destin] = 1;
        adj[destin][origin] = 1;
    }
}

// Initialize BFS by asking the user for the start vertex
void BFS_Traversal()
{
    int v;
    for (v = 0; v < n; v++)
        state[v] = initial;

    printf("Enter start vertex for BFS: ");
    scanf("%d", &v);
    if (v >= 0 && v < n)
    {
        BFS(v);
    }
    else
    {
        printf("Invalid starting vertex\n");
    }
}

// Perform BFS starting from the given vertex
void BFS(int v)
{
    int i;

    // Enqueue the starting vertex
    insert_queue(v);
    state[v] = waiting;

    while (!isEmpty_queue())
    {
        v = delete_queue();
        printf("%d ", v);
        state[v] = visited;

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && state[i] == initial)
            {
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }
    printf("\n");
}

// Enqueue a vertex
void insert_queue(int vertex)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1) // First insertion
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

// Dequeue a vertex
int delete_queue()
{
    int delete_item;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    delete_item = queue[front];
    front++;
    return delete_item;
}

// Check if the queue is empty
int isEmpty_queue()
{
    return (front == -1 || front > rear);
}
