#include<stdio.h>
#include<stdlib.h>
struct node*create(struct node*r,int item);
void postorder(struct node*r);
void preorder(struct node*r);
void inorder(struct node*r);



struct node{
int data;
struct node*left;
struct node*right;
};

struct node*create(struct node*r,int item){
if(r==NULL){
r=(struct node*)malloc(sizeof(struct node));
r->data=item;
r->left=NULL;
r->right=NULL;
return r;
}
else{
if(item > r->data){
r->right=create(r->right,item);
}
else if(item < r->data){
r->left=create(r->left,item);
}
else{
printf("Dupicate values not allowed");
}
return r;
}
}

void inorder(struct node*r){
if(r!=NULL){
inorder(r->left);
printf("%d\t",r->data);
inorder(r->right);
}
}

void preorder(struct node*r){
if(r!=NULL){
printf("%d\t",r->data);
preorder(r->left);
preorder(r->right);
}
}

void postorder(struct node*r){
if(r!=NULL){
postorder(r->left);
postorder(r->right);
printf("%d\t",r->data);

}
}


void main(){
int ch,wish,n,it;
struct node*root=NULL;

do{
printf("OPERATIONS");
printf("\n1.Creation\n2.Inorder\n3.Preorder\n4.Postorer");
printf("\nEnter your choice");
scanf("%d",&ch);
switch(ch){
case 1:
printf("BST for how many nodes");
scanf("%d",&n);
for(int i=1;i<=n;i++){
printf("Enter data for node %d",i);
scanf("%d",&it);
root=create(root,it);
}
break;

case 2:
inorder(root);
break;

case 3:
preorder(root);
break;

case 4:
postorder(root);
break;
}
printf("\nDo you Wish to Continue(1/0):");
scanf("%d",&wish);
}while(wish==1);
}














