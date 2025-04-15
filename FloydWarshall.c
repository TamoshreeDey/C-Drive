#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void display(int dist[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(dist[i][j]==INT_MAX){
                printf(" INF ");
            }else{
                printf(" %d ",dist[i][j]);
            }
        }
        printf("\n");
    }
}

void floydWarshall(int graph[4][4]){
    int dist[4][4];

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            dist[i][j]=graph[i][j];
        }
    }

    for(int k=0;k<4;k++){
        for(int i=0;i<4;i++){
                if(k==i){
                    continue;
                }
            for(int j=0;j<4;j++){
                if(k==j){
                    continue;
                }
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    display(dist);
}

int main(){
    int graph[4][4]={
        {0,2,INT_MAX,3},
        {3,0,2,INT_MAX},
        {INT_MAX,INT_MAX,0,4},
        {-2,6,INT_MAX,0}
    };
    printf("Og Graph!!!!!\n");
    display(graph);
    printf("Shortest distance time!!!!\n");
    floydWarshall(graph);
}
