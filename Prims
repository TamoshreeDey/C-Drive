#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minKey(int key[5],int mstSet[5]){
    int min=INT_MAX,min_idx;
    for(int i=0;i<5;i++){
        if(mstSet[i]==0 && key[i]<min){
            min=key[i], min_idx=i;
        }
    }
    return min_idx;
}
void printMst(int parent[5], int graph[5][5]){
    for(int i=1;i<5;i++){
        printf("%d - %d\t%d\n",parent[i],i,graph[i][parent[i]]);
    }
}
void primMst(int graph[5][5]){
    int parent[5];
    int key[5];
    int mstSet[5];

    for(int i=0;i<5;i++){
        key[i]=INT_MAX;
        mstSet[i]=0;
    }

    key[0]=0;
    parent[0]=-1;

    for(int count=0;count<4;count++){

        int u=minKey(key,mstSet);
        mstSet[u]=1;

        for(int v=0;v<5;v++){
            if(graph[u][v]&&mstSet[v]==0&&graph[u][v]<key[v]){
                key[v]=graph[u][v];
                parent[v]=u;
            }
        }
    }
    printMst(parent,graph);
}
int main()
{
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    primMst(graph);
    return 0;
}
