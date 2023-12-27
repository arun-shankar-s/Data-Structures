#include<stdio.h>
int n,que[100],front=-1,rear=-1,count=0,topo[100],a[10][10],in=0,indeg[100];
void enqueue(int data);
int isempty1();
int dequeue();
void display();
void create();
int indegree(int v);

void enqueue(int data){
if(rear==n-1){
printf("Overeflow");
}
else{
if(front==-1){
front=0;
}
rear++;
}
que[rear]=data;
}

int isempty1(){
if(front==-1){
return 1;
}
else{
return 0;
}
}

int dequeue(){
if(front==-1||front>rear){
printf("Underflow");
}
else{
int del_item=que[front];
front=front+1;


return del_item;
}
}


void display(){
for(int i=0;i<count;i++){
printf("%d\t",topo[i]);
}
}

void create(){
printf("Enter the no.of vertices:");
scanf("%d",&n);
printf("Enter the elements in matrix form:");
printf("\n");
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
scanf("%d",&a[i][j]);
}
}
}


int indegree(int v){
in=0;
for(int i=0;i<n;i++){
if(a[i][v]==1){
in=in+1;
}

}
return in;
}

void main(){
create();
for(int i=0;i<n;i++){
indeg[i]=indegree(i);
if (indeg[i]==0){
enqueue(i);
}
}
while(!isempty1() && count<n){
int d=dequeue();
topo[count]=d;
count=count+1;
for(int i=0;i<n;i++){
if(a[d][i]==1){
   
a[d][i]=0;
indeg[i]=indeg[i]-1;

if(indeg[i]==0){
    
enqueue(i);

}
}
printf("\n");
}
}

if(count<n-1){
printf("topo not possible");
}
printf("\nVertices in topological order are :\n");
display();

}


















