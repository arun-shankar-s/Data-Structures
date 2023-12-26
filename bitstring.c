#include<stdio.h>

int n,x;
int a[]={0,0,0,0,0,0,0,0,0},b[]={0,0,0,0,0,0,0,0,0};
void input();
void output(int c[]);
void inter();
void diff();
void unin();

void input(){

//First Set

printf("Enter the size of first set");
scanf("%d",&n);
printf("Enter Elements");
for(int i=0;i<n;i++){
scanf("%d",&x);
a[x-1]=1;
}

//Second Set

printf("Enter the size of Second set");
scanf("%d",&n);
printf("Enter Elements");
for(int i=0;i<n;i++){
scanf("%d",&x);
b[x-1]=1;
}

printf("First Set is");
for(int i=0;i<9;i++){
printf(" %d",a[i]);
}

printf("\nSecond Set is");
for(int i=0;i<9;i++){
printf(" %d",b[i]);
}
}


void output(int c[]){
for(int i=0;i<9;i++){
if(c[i]!=0){
printf("%d",i+1);
}
}
}


void unin(){
int c[10];

for(int i=0;i<9;i++){

if (a[i]==b[i]){
c[i]=a[i];
}
else{
c[i]=1;
}
}

for(int i=0;i<9;i++){
printf("%d",c[i]);
}
printf("\n");

output(c);
}

void inter(){
int c[10];

for(int i=0;i<9;i++){
if (a[i]==b[i]){
c[i]=a[i];
}
else{
c[i]=0;
}
}
for(int i=0;i<9;i++){
printf("%d",c[i]);
}
printf("\n");


output(c);

}

void diff(){
int c[10];

for(int i=0;i<9;i++){
if (a[i]==1 && b[i]==0){
c[i]=1;
}
else{
c[i]=0;
}
}
for(int i=0;i<9;i++){
printf("%d",c[i]);
}
printf("\n");

output(c);


}



void main(){
int ch,wish;
input();
do{
printf("\nOPERATIONS");
printf("\n1.UNION\n2.INTERSECTION\n3.DIFFERENCE");
printf("\nEnter Your Choice");
scanf("%d",&ch);

switch(ch){

case 1:
unin();
break;

case 2:
inter();
break;

case 3:
diff();
break;

}

printf("\nDo you wabt to continue?(1/0)");
scanf("%d",&wish);
}while(wish==1);
}


