#include <stdio.h>

#define MAX 20

// Adjacency matrix and visited array
int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int vertex) {
    // Mark the current node as visited and print it
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        // If there is an edge and the neighbor hasn't been visited
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i); // Recursive call
        }
    }
}

int main() {
    int startNode;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize visited array to 0
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &startNode);

    printf("DFS Traversal: ");
    dfs(startNode);
    printf("\n");

    return 0;
}

