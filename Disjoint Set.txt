#include<stdio.h>
#include<conio.h>
void union(int a,int b);
void check(int a,int b);
void set(int n);
int find(int a);
void display();

typedef struct{
int parent[10];
int rank[10];
int n;
}dis;

void set(int n){
for(int i=0;i<=n;i++){
parent[i]=i;
rank[i]=0;
}
}

int find(int a){
if(a!=dis.parent[a]){
dis.parent[a]=find(dis.parent[a]);
}
else{
return a;
}
}


void union1(int a,int b){
int pa=find(a);
int pb=find(b);

if(pa==pb){
printf("Connected Nodes");
}
else{
if(dis.rank[pa]==dis.rank[pb]){
dis.rank[pa]++;
dis.parent[pb]=pa;
}
else if(dis.rank[pa]>dis.rank[pb]){
dis.parent[pb]=pa;
}
else{
dis.parent[pa]=pb;
}
}


void check1(int a,int b){
int pa=find(a);
int pb=find(b);

if(pa==pb){
printf("Yeah it's a connected Node")
}
else{
printf("Nope it's Not")
}
}

void display(){
printf("The Parent array will be:")
for(int i=0;i<=n;i++){
printf(dis.parent[i]," ")'
}
printf("The Rank array will be:")
for(int i=0;i<=n;i++){
printf(dis.rank[i]," ")'
}
}



int main(){
int ch,a,b;
printf("Enter the Size of Disjoint Set");
scanf("%d",&dis.n);

set(dis.n);

printf("\n***DISJOINT SET***\n");
printf("What yo want to perform:\n")
printf("1.Union\n.2.Check\n3.Display\n")
scanf("%d",&ch);
switch(ch){

case 1:
printf("Enter two Numbers");
scanf("%d%d",&a,&b);
union1(a,b);
break;

case 2:
printf("Enter two Numbers");
scanf("%d%d",&a,&b);
check1(a,b);
break;

case 3:
display();
break;

default :
printf("Wrong Choice MAHN!!")
}
return 0;
}










