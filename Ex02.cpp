#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    printf("NULL");
    while (temp != NULL) {
        printf("<--->%d", temp->data);
        temp = temp->next;
    }
    printf("<--->NULL\n");
}

void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertElement(Node** head, int value, int position) {
    Node* newNode = createNode(value);
    if (position < 0) {
        printf("Loi vi tri\n");
        return;
    }

    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int count = 0;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Loi vi tri\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

int main() {
    Node* head = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 3);
    insertEnd(&head, 5);
    printf("Danh sach truoc khi chen:\n");
    printList(head);

    printf("\nChen gia tri 4 vao vi tri 2:\n");
    insertElement(&head, 4, 2);
    printList(head);

    printf("\nChen gia tri 8 vao vi tri 5:\n");
    insertElement(&head, 8, 5);

    return 0;
}

