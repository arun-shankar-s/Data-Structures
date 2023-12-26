#include<stdio.h>


void main(){
int a[10],b[10],c[20],n,m,temp;

printf("Enter the Size of the First Array");
scanf("%d",&n);
printf("Enter the Elements");
for(int i=0;i<n;i++){
scanf("%d",&a[i]);
}


for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
if(a[i]>a[j]){
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
} 
}

for(int i=0;i<n;i++){
printf(" %d",a[i]);
}


printf("\nEnter the Size of the Second Array");
scanf("%d",&m);
printf("Enter the Elements");
for(int i=0;i<m;i++){
scanf("%d",&b[i]);
}


for(int i=0;i<m;i++){
for(int j=i+1;j<m;j++){
if(b[i]>b[j]){
temp=b[i];
b[i]=b[j];
b[j]=temp;
}
} 
}

for(int i=0;i<m;i++){
printf(" %d",b[i]);
}

int acount=0;
int bcount=0;
int count=0;

while(acount<n && bcount<m){

if(a[acount]<b[bcount]){
c[count]=a[acount];
count++;
acount++;
}
else{
c[count]=b[bcount];
count++;
bcount++;
}
}

 while (acount < n) {
        c[count] = a[acount];
        count++;
        acount++;
    }

    while (bcount < m) {
        c[count] = b[bcount];
        count++;
        bcount++;
    }



printf("\n");
for(int i=0;i<m+n;i++){
printf( " %d",c[i]);
}
}