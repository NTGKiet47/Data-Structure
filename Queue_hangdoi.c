#include<stdio.h>
#define MAX 100
typedef int ElementType;
typedef struct{
	ElementType elements[MAX];
	int front, rear;
}Queue;
void makenullQueue(Queue *q){
	q->front = 0;
	q->rear = -1;
}
int empty_queue(Queue q){
	return q.front > q.rear;
}
int full_queue(Queue q){
	return (q.rear-q.front==MAX-1);
}
void enqueue(Queue *q, ElementType x){
	if(!full_queue(*q)){
		// neu hang doi chua day ma rear nam o vi tri MAX-1 thi doi phtu
		if(q->rear == MAX-1){
			int i;
			for(i=q->front; i<=q->rear; i++){
				q->elements[i-q->front] = q->elements[i];
			}
			// dat lai gtri cho rear va front
			q->rear = MAX-q->front-1;
			q->front = 0;
		}
		// thuc hien them
		q->rear++;
		q->elements[q->rear] = x;
	}
}
void dequeue(Queue *q){
	if(!empty_queue(*q)){
		q->front++;
		if(empty_queue(*q)){
			makenullQueue(q);
			// q->front = 0 voi q->rear = -1
		}
	}
}
ElementType ele_at_queue(Queue q, int pos){
	return q.elements[pos];//pos la chi so
}
void print_queue(Queue q){
	if(empty_queue(q)){
		printf("Hang doi rong");
	}else{
		int i;
		for(i=q.front; i<=q.rear; i++){
			printf("%d ", ele_at_queue(q, i));
		}
		printf("\n");
	}
}
int main(){
	int n, i;
	printf("Nhap so phan tu ");
	scanf("%d", &n);
	Queue q;
	makenullQueue(&q);
	for(i=1;i<=n;i++){
		printf("Nhap phan tu thu %d: ", i);
		ElementType x;
		scanf("%d", &x);
		enqueue(&q, x);
	}
	print_queue(q);
//	printf("Dung ham dequeue\n");
//	dequeue(&q);
//	print_queue(q);
	enqueue(&q, 100);
	print_queue(q);
	return 0;
}

























