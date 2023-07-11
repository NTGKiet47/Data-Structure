#include<stdio.h>
#define MAX 100
typedef int ElementType;
typedef struct{
	ElementType elements[MAX];
	int top_stack;
}Stack;
void makenullStack(Stack *s){
	s->top_stack = 0;
}
int empty_stack(Stack s){
	return s.top_stack == 0;
}
int full_stack(Stack s){
	return s.top_stack == MAX;
}
void push(Stack *s, ElementType x){
//	s->elements[s->top_stack] = x;
//	s->top_stack++;
	s->elements[s->top_stack++] = x;
}
ElementType top(Stack s){
	return s.elements[s.top_stack];
}
void pop(Stack *s){
	s->top_stack--;
}
// gop top va pop
ElementType top_stack(Stack *s){
	int res = s->elements[s->top_stack];
	s->top_stack--;
	return res;
}
ElementType ele_at_stack(Stack s, int pos){
	return s.elements[pos];
}
void print_stack(Stack s){
	int i;
	for(i=0; i<s.top_stack; i++){
		printf("%d ", ele_at_stack(s, i));
	}
	printf("\n");
}
int main(){
	int n, i;
	printf("Nhap so ptu cua ngan xep: ");
	scanf("%d", &n);
	Stack s;
	makenullStack(&s);
	for(i=1;i<=n;i++){
		printf("Nhap ptu thu %d: ", i);
		ElementType x;
		scanf("%d", &x);
		push(&s, x);
	}
	printf("Ngan xep vua nhap: ");
	print_stack(s);
	printf("Dung pop: ");
	pop(&s);
	print_stack(s);
	return 0;
}
















