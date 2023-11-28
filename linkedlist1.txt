#include<stdio.h>
#include<stdlib.h>

void main() {
    struct node {
        int data;
        struct node *next;
    };

    struct node *head, *newnode, *temp;
    temp = head = 0;
    int choice = 1;

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the Number: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if (head == 0) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (0 , 1)? ");
        scanf("%d", &choice);
    }

    temp = head;
    while (temp != 0) {
        printf("%d ", temp->data);  // Add a space after %d to separate the printed numbers
        temp = temp->next;
    }
}
