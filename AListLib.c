#include<stdio.h>

#define MAX_LENGTH 100
typedef int ElementType;
typedef int Position;
typedef struct{
	ElementType Elements[MAX_LENGTH];
	Position Last;
}List;
void makenullList(List *l){
	l->Last = 0;
}
int emptyList(List l){
	return l.Last == 0;
}
ElementType retrieve(Position p, List l){
	return l.Elements[p-1];
}
Position first_list(List l){
	return 1;
}
Position end_list(List l){
	return l.Last;
}
Position next(Position p, List l){
	return p+1;
}
Position previous(Position p, List l){
	return p-1;
}
Position locate(ElementType x, List l){
	Position p;
	for(p=1; p<=l.Last; p++){
		if(l.Elements[p-1] == x)
			return p;
	}
	return -1;
}
void insertList(ElementType x, Position p, List *l){
	if(l->Last == MAX_LENGTH){
		printf("Danh sach day\n");
		return;
	}
	Position i;
	for(i=l->Last+1; i>p; i--){
		l->Elements[i-1] = l->Elements[i-2];
	}
	l->Elements[p-1] = x;
	l->Last++;
}
void deleteList(Position p, List *l){
	if(p<1 || p>l->Last){
		printf("Vi tri khong hop le\n");
		return;
	}
	Position i;
	for(i=p;i<l->Last;i++){
		l->Elements[i-1] = l->Elements[i];
	}
	l->Last--;
}

