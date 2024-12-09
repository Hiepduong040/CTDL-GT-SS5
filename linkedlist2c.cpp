#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
	int data;
	struct Node* next; 
	struct Node* prev;
	 
}Node; 


// tao node moi
Node* createNode(int data){
	// cap phat bo nho  
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode -> data = data;
	newNode -> next = NULL;
	newNode -> prev = NULL; 
	return newNode; 
	
} 

// them phan tu vao dau danh sach
void insertHead(Node** head, int data){
	// tao ra 1 node moi
	Node* newNode = createNode(data); 
	newNode -> next = *head; 
	if(*head != NULL){
		(*head)->prev = newNode;  
	}
	*head = newNode; 
} 
 
// duyet danh sach 
void printList(Node* head){
	Node* temp = head;
	printf("NULL"); 
	while(temp != NULL){
		printf("<--->%d",temp -> data ); 
	temp = temp -> next;
	} 
	printf("<--->NULL"); 
} 

// them phan tu vao cuoi danh sach
void insertEnd(Node** head, int data){
	// tao 1 node moi
	Node* newNode = createNode(data);
	// tim phan tu cuoi
	Node* temp = *head;
	 
	while(temp -> next != NULL){
		temp = temp-> next;
			
	} 
	temp -> next = newNode;
	newNode -> prev = temp ; 
	
} 
// chen 1 phan tu vao vi tri bat ky 
 void insertElement(Node **head, int value, int position){
 	// kiem position < 0 ko hop le
	// vi tri position 0 ==> chen vao dau danh sach
	
	// tim vi tri
	 
 } 
int main(){
	Node* head = NULL;
	int data; 
	do{
		printf("==================================Menu=============================\n");
		printf("1. Them 1 phan tu vao dau danh sach\n");
		printf("2. Hien thi danh sach\n");
		printf("3. Them phan tu vao cuoi danh sach\n"); 
		printf("4. Thoat \n");
		printf("MOi ban chon tu 1-3\n");
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Moi ban nhap vao gia tri cho phan tu");
				scanf("%d", &data);
				insertHead(&head, data); 
				break;
			case 2:
				printList(head);
				break;
			case 3: 
				printf("Moi ban nhap vao gia tri cho phan tu");
				scanf("%d", &data);
				insertEnd(&head, data); 
				break; 
			case 4: 
				exit(0);
			default: 
				printf("Vui long chon tu 1 - 3"); 
		}
		 
	} while (1==1); 
	return 0;  
} 
 
 
