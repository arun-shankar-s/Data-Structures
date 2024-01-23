#include<stdio.h>
void bfs(int n);
int n,s,a[10][10],que[10],visited[10],rear=0,front=0;


void main(){
printf("Enter the no.of vertices:");
scanf("%d",&n);
printf("Enter the elements in matrix form:");
printf("\n");
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
scanf("%d",&a[i][j]);
}
}

for(int i=0;i<n;i++){
que[i]=0;
visited[i]=0;
}

printf("Enter the Source Vertex:");
scanf("%d",&s);

que[rear]=s;
visited[s]=1;

bfs(s);

}

void bfs(int s){

for(int i=0;i<n;i++){
if(a[s][i] && !visited[i]){
rear=rear+1;
que[rear]=i;
visited[i]=1;
}
}
while(front<=rear){

printf("%d\t",que[front]);
front=front+1;
bfs(que[front]);

}
}





