#include <stdio.h>

#define MAX 8

int graph[MAX][MAX] = {
    {0,1,1,0,0,0,0,0},  // A
    {1,0,0,1,1,0,0,0},  // B
    {1,0,0,0,0,1,0,0},  // C
    {0,1,0,0,0,0,0,0},  // D
    {0,1,0,0,0,0,1,1},  // E
    {0,0,1,0,0,0,0,0},  // F
    {0,0,0,0,1,0,0,0},  // G
    {0,0,0,0,1,0,0,0}   // H
};

int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v){
    if(front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue(){
    return queue[front++];
}

void bfs(int start){
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while(front <= rear){
        int node = dequeue();
        printf("%c ", node + 'A');

        for(int i=0;i<MAX;i++){
            if(graph[node][i] == 1 && visited[i] == 0){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void dfs(int v){
    visited[v] = 1;
    printf("%c ", v + 'A');

    for(int i=0;i<MAX;i++){
        if(graph[v][i] == 1 && visited[i] == 0){
            dfs(i);
        }
    }
}

int main(){

    bfs(0);   // Start from A

    for(int i=0;i<MAX;i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    dfs(0);

    return 0;
}