#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minDistance(int dist[5],int visited[5]){
    int min=INT_MAX, min_idx;
    for(int i=0;i<5;i++){
        if(!visited[i] && dist[i]<min){
            min=dist[i];
            min_idx=i;
        }
    }
    return min_idx;
}
void dijkstra(int graph[5][5],int src){
    int dist[5];
    int visited[5];

    for(int i=0;i<5;i++){
        dist[i]=INT_MAX;
        visited[i]=0;
    }

    dist[src]=0;

    for(int count=0;count<4;count++){
        int u=minDistance(dist,visited);
        visited[u]=1;

        for(int v=0;v<5;v++){
            if(!visited[v]&&graph[u][v]&&dist[u]!=INT_MAX&&dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < 5; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}
int main()
{
    int graph[5][5]={
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    dijkstra(graph,0);
    return 0;
}
