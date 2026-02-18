#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define TRUE 1
#define FALSE 0

/* ---------- Graph Node ---------- */
typedef struct node {
    int vertex;
    struct node *link;
} node;

typedef node* nodePointer;

/* ---------- Queue Node ---------- */
typedef struct queue {
    int vertex;
    struct queue *link;
} queue;

typedef queue* queuePointer;

/* ---------- Global Variables ---------- */
nodePointer graph[MAX];
short int visited[MAX];
queuePointer front = NULL, rear = NULL;

/* ---------- Queue Functions ---------- */
void addq(int v) {
    queuePointer temp = (queuePointer)malloc(sizeof(queue));
    temp->vertex = v;
    temp->link = NULL;

    if (rear == NULL)
        front = rear = temp;
    else {
        rear->link = temp;
        rear = temp;
    }
}

int deleteq() {
    queuePointer temp = front;
    int v = temp->vertex;
    front = front->link;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return v;
}

/* ---------- Add Edge ---------- */
void addEdge(int u, int v) {
    nodePointer temp = (nodePointer)malloc(sizeof(node));
    temp->vertex = v;
    temp->link = NULL;

    if (graph[u] == NULL) {
        graph[u] = temp;
    } else {
        nodePointer p = graph[u];
        while (p->link != NULL)
            p = p->link;
        p->link = temp;
    }
}


/* ---------- DFS ---------- */
void dfs(int v) {
    nodePointer w;
    visited[v] = TRUE;
    printf("%d ", v);

    for (w = graph[v]; w; w = w->link) {
        if (!visited[w->vertex])
            dfs(w->vertex);
    }
}

/* ---------- BFS ---------- */
void bfs(int v) {
    nodePointer w;
    front = rear = NULL;

    printf("%d ", v);
    visited[v] = TRUE;
    addq(v);

    while (front) {
        v = deleteq();

        for (w = graph[v]; w; w = w->link) {
            if (!visited[w->vertex]) {
                printf("%d ", w->vertex);
                visited[w->vertex] = TRUE;
                addq(w->vertex);
            }
        }
    }
}

/* ---------- Main ---------- */
int main() {
    int n, e, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        graph[i] = NULL;
        visited[i] = FALSE;
    }+

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);   // ✅ undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nDFS Traversal: ");
    dfs(start);

    for (int i = 0; i <= n; i++)
        visited[i] = FALSE;

    printf("\nBFS Traversal: ");
    bfs(start);

    return 0;
}