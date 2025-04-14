#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct graph{
    int src,dest,weight;
}graph;
void bellmanFord(graph graph[8],int V, int E, int src){
    int dist[5];

    for(int i=0;i<5;i++){
        dist[i]=INT_MAX;
    }

    dist[src]=0;

    for(int i=0;i<V-1;i++){
        for(int j=0;j<E;j++){
            int u=graph[j].src;
            int v=graph[j].dest;
            int wt=graph[j].weight;
            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
    for(int i=0;i<E;i++){
        int u=graph[i].src;
        int v=graph[i].dest;
        int wt=graph[i].weight;
        if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
            printf("\nGraph contains negative cycles.");
            return;
        }
    }
    for (int i = 0; i < V; i++) {
        printf("%d\t\t", i);
        if (dist[i] == INT_MAX)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
}
int main()
{
    graph graph[]={
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}};
    bellmanFord(graph,5,3,1);
    return 0;
}
