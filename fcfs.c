#include <stdio.h>
#include <stdlib.h>

#define ABS(a) a<0?-a:a


typedef struct
{
	int *arr;
	int head;
	int tail;
}Queue;


int dequeue(Queue* q){
	return q->arr[q->head++];
}

void enqueue(Queue* q,int i){
	q->arr[q->tail++] = i;
}

void init_q(Queue* q,int n){
	q->arr = (int*) malloc(sizeof(Queue)*n);
	q->head = 0;
	q->tail = 0;
}


int main(void){

	int head_pos,n,i,temp,diff,seek_time=0;
	Queue q;
	scanf("%d",&n);
	init_q(&q,n);
	scanf("%d",&head_pos);
	
	for(i=0;i<n;++i){
		scanf("%d",&temp);
		enqueue(&q,temp);
	}

	for(i=0;i<n;++i){
		temp = dequeue(&q);
		diff = head_pos - temp;
		seek_time += ABS(diff);
		
		head_pos = temp;
	}



	// for(i=0;i<n;i++){
	printf("seek_time: %d \n",seek_time);
	// }



	return 0;
}
