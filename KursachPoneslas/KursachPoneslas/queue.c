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
		return 0;
	}
	outTablePhone(queue);
	PHONE *val = (PHONE*)malloc(sizeof(PHONE));
	int pos;
	printf("\n\t\t\tIf you want retun on the \"MENU\",write -1");
	printf("\n\t\t\tEnter the position you want to insert (0<%d): ",id);
	scanf("%d", &pos);
	if (pos == -1) {
		menu();
	}
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
	else {
		Queue *buferqueue = (Queue*)malloc(sizeof(Queue));
		CreateQueue(buferqueue);
		ELEMENT tmp;
		int count = 0;
		while (!isQueueEmpty(queue)) {
			takeFromQueue(queue, &tmp);
			if (count == pos) {
				putToQueue(buferqueue, *val);
			}
			putToQueue(buferqueue, tmp.val);
			count++;
		}
		while (!isQueueEmpty(buferqueue)) {
			takeFromQueue(buferqueue, &tmp);
			putToQueue(queue, tmp.val);
		}
	}

	return 1;
}

int isQueueEmpty(Queue *q){ 
	if (q->head == NULL) return 1;
	return 0;
}

int ClearQueue(Queue *queue){
	if (isQueueEmpty(queue)) return 0;
	struct _ELEMENT *tmp, *t;
	tmp = queue->head;
	while (tmp->next != NULL){
		t = tmp;
		tmp = tmp->next;
		free(t);
	}
	queue->head = NULL;
	queue->tail = NULL;
	return 1;
}

