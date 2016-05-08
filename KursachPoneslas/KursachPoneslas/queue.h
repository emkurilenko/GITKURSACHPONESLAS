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


void putToQueue(Queue *, PHONE);//���������� � �������
int takeFromQueue(Queue *, ELEMENT *);//������ �� �������
Queue *CreateQueue(Queue*);//�������� �������
int ClearQueue(Queue *);//�������� �������
int isQueueEmpty(Queue *q);//�������� �������������
void AddHead(Queue *,PHONE); //���������� � ������ �������
int InsertPos(Queue *);//������� � �������

#endif
