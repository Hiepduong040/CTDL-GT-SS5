#include <stdio.h>
#include <stdlib.h>

// Khai bao cau truc node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Tao node moi
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Them phan tu vao dau danh sach
void insertHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Them phan tu vao cuoi danh sach
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

// Duyet danh sach theo thu tu binh thuong
void printList(Node* head) {
    Node* temp = head;
    printf("NULL");
    while (temp != NULL) {
        printf("<--->%d", temp->data);
        temp = temp->next;
    }
    printf("<--->NULL\n");
}

// Duyet danh sach nguoc tu cuoi ve dau
void printReverse(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node* temp = head;
    // Di chuyen den phan tu cuoi cung
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // In nguoc lai
    printf("NULL");
    while (temp != NULL) {
        printf("<--->%d", temp->data);
        temp = temp->prev;
    }
    printf("<--->NULL\n");
}

int main() {
    Node* head = NULL;

    // Them du lieu co dinh vao danh sach
    insertEnd(&head, 1);
    insertEnd(&head, 3);
    insertEnd(&head, 5);
    insertEnd(&head, 7);

    printf("Danh sach lien ket doi (binh thuong):\n");
    printList(head);
    printf("Danh sach lien ket doi (nguoc):\n");
    printReverse(head);

    return 0;
}

