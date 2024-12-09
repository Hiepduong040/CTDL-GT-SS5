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

// Thêm ph?n t? vào ð?u danh sách
void insertHead(Node** head, int data){
    Node* newNode = createNode(data); 
    newNode->next = *head; 
    if(*head != NULL){
        (*head)->prev = newNode;  
    }
    *head = newNode; 
} 

// Duy?t danh sách và in ra
void printList(Node* head){
    Node* temp = head;
    printf("NULL");
    while(temp != NULL){
        printf(" <-> %d", temp->data);
        temp = temp->next;
    }
    printf(" <-> NULL\n"); 
} 

// Thêm ph?n t? vào cu?i danh sách
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

// Ð?o ngý?c danh sách liên k?t ðôi
void reverseList(Node** head){
    Node* temp = NULL;
    Node* current = *head;
    
    // Ð?o ngý?c các con tr? next và prev
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    // N?u danh sách không r?ng, thay ð?i head
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
        printf("4. Ðao nguoc danh sach\n");
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

