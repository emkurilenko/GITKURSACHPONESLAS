#ifndef INPUT_H
#define INPUT_H

#include"queue.h"


void phoneAdd(PHONE *list); //Ввод 
int search(Queue *,int); //поиск 
void outTablePhone(Queue *temp); //вывод всего справочника
void CopyBuf(PHONE *val, ELEMENT *element);//Копирование полей
void InputPhone(PHONE *newPhone);
void InputName(PHONE*);
void InputSurname(PHONE *);
void InputHomePhone(PHONE *);
void InputEmail(PHONE *);
void InputCity(PHONE *);
void InputSkype(PHONE *);
void show(ELEMENT *tmp,int i);//вывод элемента
int EditElement(Queue*); //Изменение элемента
int Edit(ELEMENT *,int pos);

int DelPos(Queue *,int);//Удаление по позиции

int AddArray(Queue *queue, PHONE *value);
int OutArray(Queue *queue, PHONE *value);
void SorBuble(PHONE *,int);
void SortBublePhone(PHONE *);

int fileSaveTxt(Queue *, const char *);
int loadBinFile(Queue *);
int saveBinFile(Queue *);

#endif
