#include "queue.h"
#include "input.h"
#include "menu.h"
#include<stdio.h> 
#include<stdlib.h>

Queue *CreateQueue(Queue* q){
	q->head = NULL;
	q->tail = NULL;
	return q;
}

void putToQueue(Queue *queue, PHONE val){
	ELEMENT *tmp = (ELEMENT*)malloc(sizeof(ELEMENT));
	tmp->next = NULL;
	tmp->val = val;
	if (queue->tail != NULL)
		queue->tail->next = tmp;
	else
		queue->head = tmp;
	queue->tail = tmp;
}

int takeFromQueue(Queue *queue, ELEMENT *val) {
	if (queue->head==NULL) return 0;
	ELEMENT *tmp = queue->head;
	*val = *tmp;
	queue->head = tmp->next;
	free(tmp);
	if (queue->head == NULL) queue->tail = NULL;
	return 1;
}

void AddHead(Queue *queue, PHONE val){
	ELEMENT *tmp = (ELEMENT*)malloc(sizeof(ELEMENT));
	if (isQueueEmpty(queue)){
		putToQueue(queue, val);
	}
	else{
		Queue *buf = queue;
		tmp->next = buf->head;
		tmp->val = val;
		queue->head = tmp;
	}
}

int InsertPos(Queue *queue){
	system("cls");
	if (isQueueEmpty(queue)){
		Warning();
		return 1;
	}
	outTablePhone(queue);
	PHONE *val = (PHONE*)malloc(sizeof(PHONE));
	int pos;
	printf("\n\t\tEnter the position you want to insert (0<%d): ",id);
	scanf("%d", &pos);
	while (pos > id){
		printf("Error!Enter again \n");
		fflush(stdin);
		scanf("%d", &pos);
	}
	fflush(stdin);
	phoneAdd(val);
	if (pos == id){
		putToQueue(queue, *val);
	}
	
	if (pos == 0){
		AddHead(queue, *val);
	}
	else{
		Queue *bufqueue = (Queue*)malloc(sizeof(Queue));
		CreateQueue(bufqueue);
		inBuffer(queue,bufqueue, pos,0);
		AddHead(queue, *val);
		outBuffer(queue,bufqueue, pos);
	}
	return 0;

}

int isQueueEmpty(Queue *q){ 
	if (q->head == NULL) return 1;
	return 0;
}

int ClearQueue(Queue *queue){
	if (isQueueEmpty(queue)) return 1;
	struct _ELEMENT *tmp, *t;
	tmp = queue->head;
	while (tmp->next != NULL){
		t = tmp;
		tmp = tmp->next;
		free(t);
	}
	queue->head = NULL;
	queue->tail = NULL;
	return 0;
}

