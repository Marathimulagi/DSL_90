#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

// Push Operation
void push() {
    int value;
    if (top == SIZE - 1) {
        printf("Stack is Full (Overflow)\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

// Pop Operation
void pop() {
    if (top == -1) {
        printf("Stack is Empty (Underflow)\n");
    } else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

// Top Operation
void peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

// isEmpty Operation
void isEmpty() {
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Stack is Not Empty\n");
}

// isFull Operation
void isFull() {
    if (top == SIZE - 1)
        printf("Stack is Full\n");
    else
        printf("Stack is Not Full\n");
}

int main() {
    int choice;

    do {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. isEmpty\n");
        printf("5. isFull\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                isFull();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while(choice != 6);

    return 0;
}
