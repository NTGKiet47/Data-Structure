#include<stdio.h>
#include "LinkedListLib.c"
void readList(List *l){
	makenullList(l);
	int i, n;
	ElementType x;
	Position p=*l;
	printf("Nhap so phan tu danh sach: ");
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		printf("Nhap phan tu thu %d: ",i);
		scanf("%d", &x);
		insertList(x, p, l);
		p=p->Next;
	}
}
void sort(List *l){
	Position p = *l, q;
	ElementType tmp;
	while(p->Next->Next != NULL){
		q = p->Next;
		while(q->Next != NULL){
			if(p->Next->Element > q->Next->Element){
				// hoan vi
				tmp = p->Next->Element;
				p->Next->Element = q->Next->Element;
				q->Next->Element = tmp;
			}
			q=q->Next;
		}
		p = p->Next;
	}
}
//hieu 2 ds
List difference(List l1, List l2){
	List res;
	makenullList(&res);
	Position p=l1;
	while(p->Next != NULL){
		if(!member(p->Next->Element, l2)){
			append(p->Next->Element, &res);
		}
		p = p->Next;
	}
	return res;
}
// giao 2 ds
List intersection(List l1, List l2){
	List res;
	makenullList(&res);
	Position p=l1;
	while(p->Next != NULL){
		if(member(p->Next->Element, l2)){
			append(p->Next->Element, &res);
		}
		p = p->Next;
	}
	return res;	
}
// giao 2 ds
List unionSet(List l1, List l2){
	List res;
	makenullList(&res);
	Position p=l1;
	while(p->Next != NULL){
		if(!member(p->Next->Element, res)){
			append(p->Next->Element, &res);
		}
		p = p->Next;
	}
	p=l2;
	while(p->Next != NULL){
		if(!member(p->Next->Element, res)){
			append(p->Next->Element, &res);
		}
		p = p->Next;
	}
	return res;
}
// chuan hoa (xoa phan tu trung)
void normalize(List *l){
	Position p, q;
	p = *l;
	ElementType tmp;
	while(p->Next != NULL){
		q = p->Next;
		while(q->Next != NULL){
			if(p->Next->Element == q->Next->Element){
				deleteList(q, l); // xoa tai q
			}else{
				q = q->Next;
			}
		}
		p = p->Next;
	}
}
void removeAll(ElementType x, List *l){
	Position p = locate(x, *l);
	while(p->Next != NULL){
		deleteList(p, l);
		p = locate(x, *l);
	}
}
int main(){
	List l1, l2, res;
	readList(&l1);
//	readList(&l2);
//	printf("Hieu: ");
//	res = difference(l1, l2);
//	printList(res);
//	printf("Giao: ");
//	res = intersection(l1, l2);
//	printList(res);
//	printf("Hop: ");
//	res = unionSet(l1, l2);
//	printList(res);
//	printf("Chuan hoa: ");
//	normalize(&l1);
//	printList(l1);
	printf("Xoa tat ca so 5: ");
	removeAll(5, &l1);
	printList(l1);
	return 0;
}
