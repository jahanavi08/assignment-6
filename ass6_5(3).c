#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void deleteNode(struct Node** head, struct Node* nodeToDelete) {
    if (*head == NULL || nodeToDelete == NULL) {
        return;
    }

    if (*head == nodeToDelete) {
        *head = nodeToDelete->next;
    }

    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }

    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = nodeToDelete->next;
    }

    // Free the memory occupied by the node
    free(nodeToDelete);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;

    printf("Original Doubly Linked List: ");
    printList(head);

    struct Node* nodeToDelete = head->next->next; 
    deleteNode(&head, nodeToDelete);

    printf("Doubly Linked List after deleting node with value 3: ");
    printList(head);

    return 0;
}
