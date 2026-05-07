#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Queue structure for BFS
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void bfs(int adj[MAX][MAX], int visited[MAX], int start, int n) {
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            // If there's an edge and the vertex isn't visited
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, startNode;
    int adj[MAX][MAX];
    int visited[MAX] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &startNode);

    bfs(adj, visited, startNode, n);

    return 0;
}

