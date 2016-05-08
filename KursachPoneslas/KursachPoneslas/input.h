#ifndef INPUT_H
#define INPUT_H

#include"queue.h"


void phoneAdd(PHONE *list); //���� 
int search(Queue *,int); //����� 
void outTablePhone(Queue *temp); //����� ����� �����������
void CopyBuf(PHONE *val, Queue *list);//����������� �����
void InputPhone(PHONE *newPhone);
void InputName(PHONE*);
void InputSurname(PHONE *);
void InputHomePhone(PHONE *);
void InputEmail(PHONE *);
void InputCity(PHONE *);
void InputSkype(PHONE *);
void show(ELEMENT *tmp,int i);//����� ��������
int EditElement(Queue*); //��������� ��������

void CopyBufL(PHONE *val, Queue *list);
void inBuffer(Queue *list,Queue *buf, int pos,int n);//���� � �����
void outBuffer(Queue *,Queue *, int);//����� �� ������
int DelPos(Queue *,int);//�������� �� �������
int DelTail(Queue *);//�������� ���������� ��������

int AddArray(Queue *queue, Queue *buffer, PHONE *value);
int OutArray(Queue *queue, Queue *buffer, PHONE *value);
void SorBuble(PHONE *,int);
void SortBublePhone(PHONE *);

int fileSaveTxt(Queue *, const char *);
int loadBinFile(Queue *);
int saveBinFile(Queue *);

#endif
