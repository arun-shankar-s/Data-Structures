#include <stdio.h>

int que[10], front = -1, rear = -1, n;

void enque(int data);
void deque();
void display();

void enque(int data) {
    if ((front==0 && rear==n-1)||(front==rear+1)) {
        printf("Queue is Full\n");
    } else {
        if (front == -1) {
            rear = 0;
            front = 0;
            que[rear] = data;
        } else if (rear == n - 1) {
            rear = 0;
            que[rear] = data;
        } else {
            rear = rear + 1;
            que[rear] = data;
        }
        printf("%d Inserted\n", data);
    }
}

void deque() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("%d is Deleted\n", que[front]);

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % n;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements: ");
        if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                printf("%d\t", que[i]);
            }
        } else {
            for (int i = front; i < n; i++) {
                printf("%d\t", que[i]);
            }
            for (int i = 0; i <= rear; i++) {
                printf("%d\t", que[i]);
            }
        }
    }
    printf("\n");
}

int main() {
    int ch, data, wish;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    do {
        printf("OPERATIONS\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data to be Inserted: ");
                scanf("%d", &data);
                enque(data);
                break;

            case 2:
                deque();
                break;

            case 3:
                display();
                break;
        }

        printf("Do you wish to continue (1/0): ");
        scanf("%d", &wish);
    } while (wish == 1);

    return 0;
}
