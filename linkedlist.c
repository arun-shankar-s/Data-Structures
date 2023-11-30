#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode = NULL, *temp = NULL;

void InsertAtBegin(int data);
void InsertAtPos(int data, int pos);
void InsertAtEnd(int data);
void display();
void DeleteAtFront();
void DeleteAtPosition(int pos);
void DeleteAtEnd();

int n;

int main() {
    int data, pos, choice, ch;

    printf("Enter the Size of the list: ");
    scanf("%d", &n);

    while (1) {
        printf("\n***OPERATIONS***");
        printf("\n1. Insertion\n2. Deletion\n3. Display");
        printf("\n\nOperation: ");
        scanf("%d", &choice);
        printf("\n\n");

        switch (choice) {
            case 1:
                printf("\n\nEnter the data to be Added: ");
                scanf("%d", &data);
                printf("\n");
                printf("\n***INSERTION***");
                printf("\na. Insert at Beginining\nb. Insert at a Position\nc. Insert at End\n");
                printf("\nEnter your Choice: ");
                scanf("%d", &ch);
                switch (ch) {
                    case 1:
                        InsertAtBegin(data);
                        break;
                    case 2:
                        printf("Enter the Position: ");
                        scanf("%d", &pos);
                        InsertAtPos(data, pos);
                        break;
                    case 3:
                        InsertAtEnd(data);
                        break;
                }
                break;
            case 2:
                printf("\na. Delete at Beginining\nb. Delete at a Position\nc. Delete at End\n");
                printf("\nEnter your Choice: ");
                scanf("%d", &ch);
                switch (ch) {
                    case 1:
                        DeleteAtFront(data);
                        break;
                    case 2:
                        printf("Enter the Position to be Deleted: ");
                        scanf("%d", &pos);
                        DeleteAtPosition(pos);
                        break;
                    case 3:
                        DeleteAtEnd();
                        break;
                }
                break;
            case 3:
                display();
                break;
        }
    }
    return 0;
}

void InsertAtBegin(int data) {
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    printf("%d inserted", data);
}

void InsertAtPos(int data, int pos) {
    int i = 1;
    if (pos > n) {
        printf("Invalid Position");
    } else {
        temp = head;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = temp->next;
        temp->next = newnode;
    }
    printf("%d inserted", data);
}

void InsertAtEnd(int data) {
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    printf("%d inserted", data);
}

void display() {
    temp = head;
    while (temp != NULL) {
        printf("[");
        printf("%d", temp->data);
        printf(" , ");
        printf("%d", temp->next);
        printf("]");
        printf("  ->  ");
        temp = temp->next;
    }
}

void DeleteAtFront() {
    head = head->next;
    display();
}

void DeleteAtEnd() {
    temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    temp->next = NULL;
    display();
}

void DeleteAtPosition(int pos) {
    temp = head;
    int i = 1;

    if (pos > n) {
        printf("Invalid Position");
    } else {
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
    }
    display();
}
