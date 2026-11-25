
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char filename[50];
    int filesize;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL, *ptr, *newnode;

void insert() {
    newnode = malloc(sizeof(struct Node));

    printf("Enter file name: ");
    scanf("%49s", newnode->filename);

    printf("Enter file size: ");
    scanf("%d", &newnode->filesize);

    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else {
        ptr = head;

        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = newnode;
        newnode->prev = ptr;
    }
}

void delete() {
    char name[50];

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter file name to delete: ");
    scanf("%49s", name);

    ptr = head;

    while (ptr != NULL && strcmp(ptr->filename, name) != 0)
        ptr = ptr->next;

    if (ptr == NULL)
        printf("File not found\n");
    else {
        if (ptr->prev == NULL)
            head = ptr->next;
        else
            ptr->prev->next = ptr->next;

        if (ptr->next != NULL)
            ptr->next->prev = ptr->prev;

        free(ptr);
        printf("File deleted\n");
    }
}

void display() {
    if (head == NULL)
        printf("List is empty\n");
    else {
        ptr = head;

        while (ptr != NULL) {
            printf("File Name: %s\t", ptr->filename);
            printf("File Size: %d KB\n", ptr->filesize);

            ptr = ptr->next;
        }
    }
}

int main() {
    int ch;

    do {
        printf("\n1. Insert a node");
        printf("\n2. Delete a node");
        printf("\n3. Display the list");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }

    } while (ch != 4);

    return 0;
}
