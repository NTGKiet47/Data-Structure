#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct Node{
	ElementType Element;
	struct Node *Next;
}Node;
typedef Node *Position;
typedef Position List;
void makenullList(List *l){
	// vi ban than L da la 1 con tro
	(*l) = (Node*)malloc(sizeof(Node));
	(*l)->Next = NULL;
}
int emptyList(List l){
	return l->Next == NULL;
}
void insertList(ElementType x, Position p, List *l){
	Position t = (Node*)malloc(sizeof(Node));
	t->Next = p->Next;
	p->Next = t;
	t->Element = x;
}
void append(ElementType x, List *l){
	// them vao cuoi danh sach
	Position p = *l;
	while(p->Next != NULL)
		p = p->Next;
	Position tmp = (Node*)malloc(sizeof(Node));
	tmp->Next = NULL;
	p->Next = tmp;
	tmp->Element = x;
}
void addFirst(ElementType x, List *l){
	Position p = *l;
	Position tmp = (Node*)malloc(sizeof(Node));
	tmp->Next = p->Next;
	p->Next = tmp;
	tmp->Element = x;
}
void deleteList(Position p, List *l){
	Position t;
	if(p->Next != NULL){
		t = p->Next;
		p->Next = t->Next;
		free(t);
	}
}
int member(ElementType x, List l){
	Position p = l;
	while(p->Next!=NULL){
		if(p->Next->Element == x)
			return 1;
		p = p->Next;
	}
	return 0;
}
Position locate(ElementType x, List l){
	Position p = l;
	while(p->Next != NULL){
		if(p->Next->Element==x)
			return p;
		p = p->Next;
	}
	return p; // khi nay p = NULL, neu ko tim thay x thi ham tra ve NULL
}
void printList(List l){
	Position p = l;
	while(p->Next != NULL){
		printf("%d ", p->Next->Element);
		p = p->Next;
	}	
}
int main(){
	int i, n;
	printf("Nhap so phan tu: ");
	scanf("%d", &n);
	List l;
	makenullList(&l);
	Position p = l;
	for(i=1;i<=n;i++){
		ElementType tmp;
		printf("Nhap so phan tu thu %d: ", i);
		scanf("%d", &tmp);
		insertList(tmp, p, &l);
		p = p->Next;
	}
	printf("Danh sach vua nhap: ");
	printList(l);
	
	return 0;
}




