#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct {
    int m, c, boat;
    int parent;
} State;

/* ================= GLOBAL VARIABLES ================= */

State queue[MAX];
int visited[4][4][2];

State solutionPath[50];
int pathLength = 0;

int bfsSteps, bfsNodes;
int dfsSteps, dfsNodes;
int iddfsSteps, iddfsNodes;

/* ================= VALID STATE CHECK ================= */

int isValid(int m, int c) {
    int mr = 3 - m;
    int cr = 3 - c;

    if (m < 0 || c < 0 || m > 3 || c > 3)
        return 0;

    if ((m > 0 && m < c) || (mr > 0 && mr < cr))
        return 0;

    return 1;
}

/* ================= PRINT PATH ================= */

void printSolution() {
    printf("\nStep-by-step:\n\n");

    for(int i = pathLength-1, step = 0; i >= 0; i--, step++) {

        int m = solutionPath[i].m;
        int c = solutionPath[i].c;
        int boat = solutionPath[i].boat;

        int mr = 3 - m;
        int cr = 3 - c;

        printf("%d. ", step);

        if(boat == 0)
            printf("Left[%dM %dC] <boat> ~~~~ Right[%dM %dC]\n",
                   m, c, mr, cr);
        else
            printf("Left[%dM %dC] ~~~~ <boat> Right[%dM %dC]\n",
                   m, c, mr, cr);
    }
}

/* ================= BFS ================= */

void bfs() {
    int front = 0, rear = 0;
    bfsNodes = 0;

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<2;k++)
                visited[i][j][k] = 0;

    queue[rear++] = (State){3,3,0,-1};
    visited[3][3][0] = 1;

    while(front < rear) {

        State current = queue[front];
        int currIndex = front;
        front++;
        bfsNodes++;

        if(current.m == 0 && current.c == 0 && current.boat == 1) {

            bfsSteps = 0;
            pathLength = 0;

            int temp = currIndex;
            while(temp != -1) {
                solutionPath[pathLength++] = queue[temp];
                temp = queue[temp].parent;
                if(temp != -1) bfsSteps++;
            }
            return;
        }

        int moves[5][2] = {{1,0},{2,0},{0,1},{0,2},{1,1}};

        for(int i=0;i<5;i++) {

            int nm, nc, nb;

            if(current.boat == 0) {
                nm = current.m - moves[i][0];
                nc = current.c - moves[i][1];
                nb = 1;
            } else {
                nm = current.m + moves[i][0];
                nc = current.c + moves[i][1];
                nb = 0;
            }

            if(isValid(nm,nc) && !visited[nm][nc][nb]) {
                visited[nm][nc][nb] = 1;
                queue[rear++] = (State){nm,nc,nb,currIndex};
            }
        }
    }
}

/* ================= DFS ================= */

int dfsUtil(int m, int c, int boat, int depth) {

    dfsNodes++;

    if(m == 0 && c == 0 && boat == 1) {
        solutionPath[pathLength++] = (State){m,c,boat,-1};
        dfsSteps = depth;
        return 1;
    }

    visited[m][c][boat] = 1;

    int moves[5][2] = {{1,0},{2,0},{0,1},{0,2},{1,1}};

    for(int i=0;i<5;i++) {

        int nm, nc, nb;

        if(boat == 0) {
            nm = m - moves[i][0];
            nc = c - moves[i][1];
            nb = 1;
        } else {
            nm = m + moves[i][0];
            nc = c + moves[i][1];
            nb = 0;
        }

        if(isValid(nm,nc) && !visited[nm][nc][nb]) {
            if(dfsUtil(nm,nc,nb,depth+1)) {
                solutionPath[pathLength++] = (State){m,c,boat,-1};
                return 1;
            }
        }
    }

    return 0;
}

void dfs() {
    dfsNodes = 0;
    pathLength = 0;

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<2;k++)
                visited[i][j][k] = 0;

    dfsUtil(3,3,0,0);
}

/* ================= IDDFS ================= */

int dls(int m, int c, int boat, int depth, int limit) {

    iddfsNodes++;

    if(m == 0 && c == 0 && boat == 1) {
        solutionPath[pathLength++] = (State){m,c,boat,-1};
        iddfsSteps = depth;
        return 1;
    }

    if(depth >= limit)
        return 0;

    visited[m][c][boat] = 1;

    int moves[5][2] = {{1,0},{2,0},{0,1},{0,2},{1,1}};

    for(int i=0;i<5;i++) {

        int nm, nc, nb;

        if(boat == 0) {
            nm = m - moves[i][0];
            nc = c - moves[i][1];
            nb = 1;
        } else {
            nm = m + moves[i][0];
            nc = c + moves[i][1];
            nb = 0;
        }

        if(isValid(nm,nc) && !visited[nm][nc][nb]) {
            if(dls(nm,nc,nb,depth+1,limit)) {
                solutionPath[pathLength++] = (State){m,c,boat,-1};
                visited[m][c][boat] = 0;
                return 1;
            }
        }
    }

    visited[m][c][boat] = 0;
    return 0;
}

void iddfs() {
    iddfsNodes = 0;
    pathLength = 0;

    for(int depth=0; depth<20; depth++) {

        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                for(int k=0;k<2;k++)
                    visited[i][j][k] = 0;

        if(dls(3,3,0,0,depth))
            return;
    }
}

/* ================= MAIN ================= */

int main() {

    clock_t start, end;
    double bfsTime, dfsTime, iddfsTime;

    // BFS
    start = clock();
    bfs();
    end = clock();
    bfsTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    printf("=====================================================\n");
    printf("BFS\n");
    printf("=====================================================\n");
    printf("Steps: %d | Nodes: %d | Time: %.4f ms\n",
           bfsSteps, bfsNodes, bfsTime);
    printSolution();

    // DFS
    start = clock();
    dfs();
    end = clock();
    dfsTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    printf("\n=====================================================\n");
    printf("DFS\n");
    printf("=====================================================\n");
    printf("Steps: %d | Nodes: %d | Time: %.4f ms\n",
           dfsSteps, dfsNodes, dfsTime);
    printSolution();

    // IDDFS
    start = clock();
    iddfs();
    end = clock();
    iddfsTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    printf("\n=====================================================\n");
    printf("IDDFS\n");
    printf("=====================================================\n");
    printf("Steps: %d | Nodes: %d | Time: %.4f ms\n",
           iddfsSteps, iddfsNodes, iddfsTime);
    printSolution();

    printf("\n=== Code Execution Successful ===\n");

    return 0;
}