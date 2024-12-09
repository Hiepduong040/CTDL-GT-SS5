#include <stdio.h> 
#include <stdlib.h>

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
    if (head == NULL) {
        printf("Danh sách r?ng\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data); 
        temp = temp->next;
    }
    printf("NULL\n");
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

int countElements(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = NULL;
    int data; 
    do {
        printf("==================================Menu=============================\n");
        printf("1. Them 1 phan tu vao dau danh sach\n");
        printf("2. Hien thi danh sach\n");
        printf("3. Them phan tu vao cuoi danh sach\n"); 
        printf("4. Thoat \n");
        printf("Moi ban chon tu 1-4\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Moi ban nhap vao gia tri cho phan tu: ");
                scanf("%d", &data);
                insertHead(&head, data); 
                break;
            case 2:
                printList(head);
                break;
            case 3: 
                printf("Moi ban nhap vao gia tri cho phan tu: ");
                scanf("%d", &data);
                insertEnd(&head, data); 
                break; 
            case 4: 
                printf("Tong so phan tu trong danh sac: %d\n", countElements(head));
                exit(0);
            default: 
                printf("Vui long chon tu 1 - 4\n"); 
        }
    } while (1);
    return 0;  
} 

