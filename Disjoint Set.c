#include<stdio.h>

typedef struct {
    int parent[10];
    int rank[10];
    int n;
} DisjointSet;

DisjointSet dis; 

void set(int n) {
    for(int i = 0; i <= n; i++) {
        dis.parent[i] = i;
        dis.rank[i] = 0;
    }
}

int find(int a) {
    if(a != dis.parent[a]) {
        dis.parent[a] = find(dis.parent[a]);
    }
    return dis.parent[a];
}

void union1(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if(pa == pb) {
        printf("Connected Nodes\n");
    } else {
        if(dis.rank[pa] == dis.rank[pb]) {
            dis.rank[pa]++;
            dis.parent[pb] = pa;
        } else if(dis.rank[pa] > dis.rank[pb]) {
            dis.parent[pb] = pa;
        } else {
            dis.parent[pa] = pb;
        }
    }
}

void check(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if(pa == pb) {
        printf("Yeah, it's a connected Node\n");
    } else {
        printf("Nope, it's Not\n");
    }
}

void display() {
    printf("The Parent array will be: ");
    for(int i = 0; i <= dis.n; i++) {
        printf("%d ", dis.parent[i]);
    }
    printf("\nThe Rank array will be: ");
    for(int i = 0; i <= dis.n; i++) {
        printf("%d ", dis.rank[i]);
    }
    printf("\n");
}

int main() {
    int ch, a, b,wish;
    printf("Enter the Size of Disjoint Set: ");
    scanf("%d", &dis.n);

    set(dis.n);
do{
    printf("\n***DISJOINT SET***\n");
    printf("What do you want to perform:\n");
    printf("1. Union\n2. Check\n3. Display\n");
    scanf("%d", &ch);

    switch(ch) {
        case 1:
            printf("Enter two Numbers: ");
            scanf("%d%d", &a, &b);
            union1(a, b);
            break;
        case 2:
            printf("Enter two Numbers: ");
            scanf("%d%d", &a, &b);
            check(a, b);
            break;
        case 3:
            display();
            break;
        default:
            printf("Wrong Choice MAHN!!\n");
    }
printf("\nDo you Wish to Continue(1/0):");
scanf("%d",&wish);
}while(wish==1);

    return 0;
}
