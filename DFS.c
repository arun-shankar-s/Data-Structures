#include<stdio.h>

#define MAX 10
void dfs(int v);

int n,a[MAX][MAX],v,visited[MAX],stack[MAX],top=-1;

void create(){
printf("Enter the no.of vertices");
scanf("%d",&n);
printf("Enter the adjacency form");
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
scanf("%d",&a[i][j]);
}
}
}
void dfs(int v){
printf("%d\t",v);
visited[v]=1;
top=top+1;
for(int i=0;i<n;i++){
if(a[v][i]==1 && visited[i]==0){
stack[top]=i;
dfs(stack[top]);
}
}
}


void main(){
create();
for(int i=0;i<n;i++){
visited[i]=0;
}
printf("Enter the Source Vertex");
scanf("%d",&v);
dfs(v);
}
