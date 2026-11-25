
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char jobName[50];
    struct Node *link;
};

struct Node *front = NULL, *rear = NULL;
struct Node *newnode, *ptr;

// a) Add a print job
void addJob() {
    newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter print job name: ");
    scanf(" %49[^\n]", newnode->jobName);

    newnode->link = NULL;

    if (front == NULL) {
        front = rear = newnode;
    } else {
        rear->link = newnode;
        rear = newnode;
    }

    printf("Print job added successfully\n");
}

// b) Process the next print job
void processJob() {
    if (front == NULL) {
        printf("Queue is empty. No jobs to process\n");
    } else {
        ptr = front;

        printf("Processing print job: %s\n", ptr->jobName);

        front = front->link;

        if (front == NULL) {
            rear = NULL;
        }

        free(ptr);
    }
}

// c) Display pending print jobs
void display() {
    if (front == NULL) {
        printf("No pending print jobs\n");
    } else {
        ptr = front;

        printf("\nPending Print Jobs:\n");

        while (ptr != NULL) {
            printf("%s\n", ptr->jobName);
            ptr = ptr->link;
        }
    }
}

// d) Check queue status
void queueStatus() {
    if (front == NULL) {
        printf("Printer queue is empty\n");
    } else {
        printf("Printer queue is not empty\n");
        printf("Next job to be processed: %s\n", front->jobName);
        printf("Last job in queue: %s\n", rear->jobName);
    }
}

// e) Main function
int main() {
    int ch;

    do {
        printf("\n1. Add a print job");
        printf("\n2. Process the next print job");
        printf("\n3. Display pending print jobs");
        printf("\n4. Check queue status");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                addJob();
                break;

            case 2:
                processJob();
                break;

            case 3:
                display();
                break;

            case 4:
                queueStatus();
                break;

            case 5:
                printf("Exiting printer queue\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (ch != 5);

    return 0;
}
