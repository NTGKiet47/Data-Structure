#include<stdio.h>
#include "LinkedListLib.c"
void readList(List *l){
	makenullList(l);
	int i, n;
	ElementType x;
	Position p = *l;
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		scanf("%d", &x);
		insertList(x, p, l);
		p = p->Next;
	}
}
