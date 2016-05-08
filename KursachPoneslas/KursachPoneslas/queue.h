#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
	int ID;
	char name[21];
	char surname[21];
	int  mob_one, mob_two, mob_three;
	//char mobilephone[11];
	char homephone[8];
	char email[24];
	char skype[25];
	char city[25];
}PHONE;

int id;

typedef struct _ELEMENT{
	PHONE val;
	struct _ELEMENT *next;
} ELEMENT;

typedef struct {
	ELEMENT *head;
	ELEMENT *tail;
}Queue;


void putToQueue(Queue *, PHONE);//добавление в очередь
int takeFromQueue(Queue *, ELEMENT *);//взятие из очереди
Queue *CreateQueue(Queue*);//Создание очереди
int ClearQueue(Queue *);//Удаление очереди
int isQueueEmpty(Queue *q);//Проверка существования
void AddHead(Queue *,PHONE); //Добавление в начало очереди
int InsertPos(Queue *);//Вставка в позицию

#endif
