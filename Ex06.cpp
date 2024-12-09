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

void printList(Node* head) {
    Node* temp = head;
    printf("NULL");
    while (temp != NULL) {
        printf(" <-> %d", temp->data);
        temp = temp->next;
    }
    printf(" <-> NULL\n");
}

int replaceValue(Node* head, int oldValue, int newValue) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            return 1;  // Thay th? thành công
        }
        temp = temp->next;
    }
    return 0;  
}

int main() {
    Node* head = NULL;
    int data;

    insertHead(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);

    printf("Danh sach ban dau: ");
    printList(head);

    int oldValue, newValue;
    printf("Gia tri can thay the: ");
    scanf("%d", &oldValue);
    printf("Gia tri moi: ");
    scanf("%d", &newValue);

    if (replaceValue(head, oldValue, newValue)) {
        // Hi?n th? danh sách sau khi thay th?
        printf("Danh sach sau khi thay the: ");
        printList(head);
    } else {
        printf("Khong tim thay phan tu can thay the\n");
    }

    return 0;
}

