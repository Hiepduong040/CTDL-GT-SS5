#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next; 
    struct Node* prev;
} Node; 

// T?o node m?i
Node* createNode(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL; 
    return newNode; 
} 

// Th�m ph?n t? v�o �?u danh s�ch
void insertHead(Node** head, int data){
    Node* newNode = createNode(data); 
    newNode->next = *head; 
    if(*head != NULL){
        (*head)->prev = newNode;  
    }
    *head = newNode; 
} 

// Duy?t danh s�ch v� in ra
void printList(Node* head){
    Node* temp = head;
    printf("NULL");
    while(temp != NULL){
        printf(" <-> %d", temp->data);
        temp = temp->next;
    }
    printf(" <-> NULL\n"); 
} 

// Th�m ph?n t? v�o cu?i danh s�ch
void insertEnd(Node** head, int data){
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    } 
    temp->next = newNode;
    newNode->prev = temp; 
} 

// �?o ng�?c danh s�ch li�n k?t ��i
void reverseList(Node** head){
    Node* temp = NULL;
    Node* current = *head;
    
    // �?o ng�?c c�c con tr? next v� prev
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    // N?u danh s�ch kh�ng r?ng, thay �?i head
    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main(){
    Node* head = NULL;
    int data; 
    do {
        printf("==================================Menu=============================\n");
        printf("1. Them 1 phan tu vao dau danh sach\n");
        printf("2. Hien thi danh sach\n");
        printf("3. Them phan tu vao cuoi danh sach\n"); 
        printf("4. �ao nguoc danh sach\n");
        printf("5. Thoat \n");
        printf("Moi ban chon tu  1-5\n");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Nhap gia tri cua phan tu: ");
                scanf("%d", &data);
                insertHead(&head, data); 
                break;
            case 2:
                printList(head);
                break;
            case 3: 
                printf("Nhap gia tri cua phan tu: ");
                scanf("%d", &data);
                insertEnd(&head, data); 
                break; 
            case 4:
                reverseList(&head);
                break;
            case 5:
                exit(0);
            default: 
                printf("Vui long chon tu 1 - 5\n"); 
        }
    } while (1 == 1); 
    return 0;  
}

