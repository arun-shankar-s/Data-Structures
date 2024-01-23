#include<stdio.h>
#define MAX 10
#define INF 999

int n, cost[MAX][MAX], edge = 1, mincost = 0, min;

void create() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost in the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }
}

void prims() {
    int u, v;
    int visited[MAX] = {0};

    visited[1] = 1;

    while (edge < n) {
        min = 999;
        for (int i = 1; i <= n; i++) {
            if (visited[i] != 0) {
                for (int j = 1; j <= n; j++) {
                    if (visited[j] == 0 && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        visited[v] = 1;
        printf("Edge %d(%d, %d): %d\n", edge, u, v, min);
        mincost += min;
        edge = edge + 1;
    }
}

int main() {
    create();
    prims();
    printf("Min cost = %d\n", mincost);
    return 0;
}
