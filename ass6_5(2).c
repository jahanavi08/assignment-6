#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;    
    
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        
        *head = NULL;
    }

    free(temp);
    printf("Node deleted from the end successfully.\n");
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 1;
    head->prev = NULL;
    head->next = second;
    
    second->data = 2;
    second->prev = head;
    second->next = third;
    
    third->data = 3;
    third->prev = second;
    third->next = NULL;
    
    printf("Original Doubly Linked List: ");
    printList(head);
    

    deleteEnd(&head);
    
    printf("Doubly Linked List after deleting node from the end: ");
    printList(head);
    
    return 0;
}
