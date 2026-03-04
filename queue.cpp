#include <iostream>
using namespace std;

#define SIZE 5

int queueArr[SIZE];
int front = -1, rear = -1;

// Enqueue Operation
void enqueue() {
    int value;

    if (rear == SIZE - 1) {
        cout << "Queue is Full (Overflow)" << endl;
    } else {
        cout << "Enter value to enqueue: ";
        cin >> value;

        if (front == -1)   // First element
            front = 0;

        rear++;
        queueArr[rear] = value;
        cout << value << " inserted into queue" << endl;
    }
}

// Dequeue Operation
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty (Underflow)" << endl;
    } else {
        cout << queueArr[front] << " removed from queue" << endl;
        front++;

        // Reset when queue becomes empty
        if (front > rear) {
            front = rear = -1;
        }
    }
}

// Front Operation
void peek() {
    if (front == -1) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "Front element is: " << queueArr[front] << endl;
    }
}

// isEmpty Operation
void isEmpty() {
    if (front == -1)
        cout << "Queue is Empty" << endl;
    else
        cout << "Queue is Not Empty" << endl;
}

// isFull Operation
void isFull() {
    if (rear == SIZE - 1)
        cout << "Queue is Full" << endl;
    else
        cout << "Queue is Not Full" << endl;
}

int main() {
    int choice;

    do {
        cout << "\n--- QUEUE MENU ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. isEmpty" << endl;
        cout << "5. isFull" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 6);

    return 0;
}
