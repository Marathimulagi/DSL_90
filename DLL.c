#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Create new node
struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertBeginning() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    struct node *newNode = createNode(data);

    if (head != NULL) {
        head->prev = newNode;
    }
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
    newNode->prev = temp;
}

// Insert at position
void insertPosition() {
    int data, pos, i = 1;
    printf("Enter data and position: ");
    scanf("%d %d", &data, &pos);

    struct node *newNode = createNode(data);

    if (pos == 1) {
        if (head != NULL)
            head->prev = newNode;
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
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

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

    if (head != NULL) {
        head->prev = NULL;
    }

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

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    printf("Deleted from end\n");
}

// Delete from position
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
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        printf("Deleted\n");
        return;
    }

    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
    printf("Deleted\n");
}

// Display
void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main with switch case
int main() {
    int choice;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
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
