
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char action[100];
    struct Node *link;
};

struct Node *top = NULL, *ptr, *newnode;

void push() {
    newnode = malloc(sizeof(struct Node));

    if (newnode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter action: ");
    scanf(" %99[^\n]", newnode->action);

    newnode->link = top;
    top = newnode;

    printf("Action stored successfully\n");
}

void pop() {
    if (top == NULL)
        printf("Stack Underflow: No actions to undo\n");
    else {
        ptr = top;

        printf("Undoing action: %s\n", ptr->action);

        top = top->link;
        free(ptr);
    }
}

void display() {
    if (top == NULL)
        printf("Stack is empty\n");
    else {
        ptr = top;

        printf("\nStored actions (Recent to Oldest):\n");

        while (ptr != NULL) {
            printf("%s\n", ptr->action);
            ptr = ptr->link;
        }
    }
}

int main() {
    int ch;

    do {
        printf("\n1. Store Action (Push)");
        printf("\n2. Undo Action (Pop)");
        printf("\n3. Display Actions");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }

    } while (ch != 4);

    return 0;
}
