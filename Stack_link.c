#include<stdio.h>
#include <stdlib.h>



void push(int data);
void pop();
void dispaly();

struct node{
int data;
struct node*next;
};

struct node*Top=NULL,*newnode=NULL,*temp=NULL;

void push(int data){
newnode= (struct node *)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=Top;
Top=newnode;
printf("Data inserted Successfully");
}

void pop(){
temp=Top;
if(Top==NULL){
    printf("Empty Stack");
}
else{
printf("%d is Deleted",temp->data);
Top=Top->next;
free(temp);
}
}

void display(){
temp=Top;
if(Top==NULL){
    printf("Empty Stack");
}
else{
while(temp!=NULL){
printf("\n%d",temp->data);
temp=temp->next;
}
}
}

int main(){
int ch,n,wish;
do{
printf("\nOPERATIONS");
printf("\n1.PUSH\n2.POP\n3.Display");
printf("\nEnter Your Choice:");
scanf("%d",&ch);
switch(ch){
case 1:
printf("Enter data to be inserted:");
scanf("%d",&n);
push(n);
break;

case 2:
pop();
break;

case 3:
display();
break;

}
printf("\nDo you Wish to Continue(1/0):");
scanf("%d",&wish);
}while(wish==1);
}