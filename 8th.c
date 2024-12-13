//Write a program to implement Binary Search Tree using linked list .

#include <stdio.h>
#include <stdlib.h>

/* A linked list node */
struct LNode {
    int data;
    struct LNode* next;
};

/* A Binary tree node */
struct TNode {
    int data;
    struct TNode* left;
    struct TNode* right;
};

/* Function to create a new Binary tree node */
struct TNode* newNode(int data) {
    struct TNode* node = (struct TNode*)malloc(sizeof(struct TNode));
    if (node) {
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

/* Function to count nodes in a linked list */
int countLNodes(struct LNode* head) {
    int count = 0;
    struct LNode* temp = head;
    while (temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

/* Function to recursively convert the sorted linked list to a balanced BST */
struct TNode* sortedListToBSTRecur(struct LNode** head_ref, int n) {
    if (n <= 0)
        return NULL;

    // Recurse for left subtree
    struct TNode* left = sortedListToBSTRecur(head_ref, n / 2);

    // Create a new BST node for the middle linked list element
    struct TNode* root = newNode((*head_ref)->data);

    // Move the linked list pointer
    *head_ref = (*head_ref)->next;

    // Recurse for right subtree
    root->left = left;
    root->right = sortedListToBSTRecur(head_ref, n - n / 2 - 1);

    return root;
}

/* Function to convert linked list to BST */
struct TNode* sortedListToBST(struct LNode* head) {
    int n = countLNodes(head);
    return sortedListToBSTRecur(&head, n);
}

/* Function to push nodes into the linked list */
void push(struct LNode** head_ref, int new_data) {
    struct LNode* new_node = (struct LNode*)malloc(sizeof(struct LNode));
    if (new_node) {
        new_node->data = new_data;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
}

/* Function to print the linked list */
void printList(struct LNode* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Pre-order traversal of the BST */
void preOrder(struct TNode* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

/* Driver program */
int main() {
    /* Start with the empty list */
    struct LNode* head = NULL;

    /* Create a sorted linked list */
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("\nGiven Linked List: ");
    printList(head);

    /* Convert List to BST */
    struct TNode* root = sortedListToBST(head);

    printf("\nPreOrder Traversal of constructed BST: ");
    preOrder(root);

    printf("\n");

    return 0;
}
