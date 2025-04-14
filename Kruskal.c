#include <stdio.h>
#include <stdlib.h>
typedef struct graph{
    int src,dest,weight;
}graph;

int parent[5];
int rank[5];

int compare(const void* a, const void* b){
    graph* edgeA= (graph*)a;
    graph* edgeB= (graph*)b;
    return ((edgeA->weight)-(edgeB->weight));
}
int find(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=find(parent[x]);
}
void unionSet(int a, int b){
    int rootA=find(a);
    int rootB=find(b);
    if(rootA==rootB){
        return;
    }
    if(rank[rootA]<rank[rootB]){
        parent[rootA]=rootB;
    }else if(rank[rootA]<rank[rootB]){
        parent[rootB]=rootA;
    }else{
        parent[rootB]=rootA;
        rank[rootA]++;
    }
}
void kruskalMst(graph graph[5]){
    int mstWt=0;

    for(int i=0;i<5;i++){
        parent[i]=i;
        rank[i]=0;
    }

    for(int i=0;i<5;i++){
        int u=graph[i].src;
        int v=graph[i].dest;
        int weight= graph[i].weight;


        if(find(u)!=find(v)){
            unionSet(u,v);
            printf("(%d %d)- %d\n",u,v,weight);
            mstWt+=weight;
        }
    }
    printf("Total weight: %d",mstWt);
}
int main()
{
    graph graph[]={
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    qsort(graph,5,sizeof(graph[0]),compare);

    kruskalMst(graph);

    /*printf("Graph (Edge List):\n");
    for (int i = 0; i < 5; i++) {
        printf("Edge %d: ", i);
        for (int j = 0; j < 3; j++) {
            if (j == 0) printf("src = %d, ", graph[i].src);
            else if (j == 1) printf("dest = %d, ", graph[i].dest);
            else if (j == 2) printf("weight = %d", graph[i].weight);
        }
        printf("\n");
    }*/
    return 0;
}
