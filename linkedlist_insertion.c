#include<stdio.h>
#include<stdlib.h>
int n;
void insertatbegin(int data);
void display();
void InsertAtPos(int data,int pos);
void InsertAtEnd(int data);




struct node{
int data;
struct node *next;
};

struct node *head = NULL, *newnode = NULL, *temp = NULL;

void InsertAtBegin(int data){
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=head;
head=newnode;
}

void display(){
temp=head;
while(temp!=NULL){
printf("[");
printf("%d",temp->data);
printf(" , ");
printf("%d",temp->next);
printf("]");
printf("  ->  ");
temp=temp->next;
}
}


void InsertAtPos(int data,int pos){
int i=1;
if(pos>n){
printf("Invalid Position");
}
else{
temp = head;
while(i<pos-1){

temp=temp->next;
i++;
}
newnode=(struct node*) malloc(sizeof(struct node));
newnode->data=data;
newnode->next=temp->next;
temp->next=newnode;
}
}


void InsertAtEnd(int data){
newnode=(struct node*) malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;

   temp = head;
while(temp->next!=NULL){
temp=temp->next;
}
temp->next=newnode;
}






int main(){
int data,pos,choice,ch;

printf("Enter the Size of the list: ");
scanf("%d",&n);




while(1){
printf("\n***OPERATIONS***");
printf("\n1.Insertion\n2.Deletion\n3.Display");
printf("\n\nOperation: ");
scanf("%d",&choice);
printf("\n\n");

switch(choice){
case 1:
printf("\n\nEnter the data to be Added: ");
scanf("%d",&data);
printf("\n");
printf("\n***INSERTION***");
printf("\na.Insert at Beginining\nb.Insert at a Position\nc.Insert at End\n");
printf("\nEnter your Choice: ");
printf("\n");
scanf("%d",&ch);
switch(ch){
case 'a':
InsertAtBegin(data);
break;
case 'b':
printf("Enter the Position to be Added");
scanf("%d",&pos);
InsertAtPos(data,pos);
break;
case 'c':
InsertAtEnd(data);
}
break;





case 3:
display();
break;
}
}
return 0;

}












