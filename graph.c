#include<stdio.h>
#include<stdlib.h>
# define MAX_CITIES 50
struct Graph{
int vertices;
int adjacencymatrix[MAX_CITIES][MAX_CITIES];
};
struct Graph creategraph(int n){
struct Graph graph;
graph.vertices=n;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        graph.adjacencymatrix[i][j]=0;
    }
}
return graph;
}
void addedge(struct Graph *graph,int city1,int city2){
    if(city1>=0&&city1<=graph->vertices&&city2>=0&&city2<=graph->vertices){
        graph->adjacencymatrix[city1][city2]=1;
    }
    else{
        printf("Invalid indeces");
    }
}
void DFS(struct Graph *graph,int startcity,int visited[]){
printf("%d",startcity);
visited[startcity]=1;
for(int i=0;i<graph->vertices;i++){
    if(graph->adjacencymatrix[startcity][i]&&!visited[i]){
        DFS(graph,i,visited);
    }
}
}
int main()
{int startcity,n;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    struct Graph graph=creategraph(n);
    printf("Enter the adjacency matrix");
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
    scanf("%d",&graph.adjacencymatrix[i][j]);
            }
    }
    printf("Enter the startcity(0 to %d)",n-1);
    scanf("%d",&startcity);
    int visited[MAX_CITIES]={0};
    printf("DFS traversal\n");
    DFS(&graph,startcity,visited);
    printf("\n");
    return 0;
}
