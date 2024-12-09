#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
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

void deleteLast(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) { // N?u ch? có m?t ph?n t?
        free(temp);
        *head = NULL;
        printf("Danh sach rong\n");
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 3);
    insertEnd(&head, 5);
    insertEnd(&head, 7);

    printf("Danh sach ban dau: \n");
    printList(head);

    deleteLast(&head);

    printf("Danh sach sau khi xoa phan tu cuoi: \n");
    printList(head);

    deleteLast(&head);
    deleteLast(&head);
    deleteLast(&head);

    printf("Danh sach sau khi xoa het: \n");
    printList(head);

    return 0;
}

