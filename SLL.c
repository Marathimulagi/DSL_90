#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to create a new node
struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertBeginning() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    struct node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    struct node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at any position
void insertPosition() {
    int data, pos, i = 1;
    printf("Enter data and position: ");
    scanf("%d %d", &data, &pos);

    struct node *newNode = createNode(data);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Deleted from beginning\n");
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    printf("Deleted from end\n");
}

// Delete from any position
void deletePosition() {
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    if (pos == 1) {
        head = temp->next;
        free(temp);
        printf("Deleted\n");
        return;
    }

    while (i < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    printf("Deleted\n");
}

// Display list
void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with switch case
int main() {
    int choice;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertBeginning(); break;
            case 2: insertEnd(); break;
            case 3: insertPosition(); break;
            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;
            case 6: deletePosition(); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
