#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "input.h"
#include "queue.h"

void menu1(void){
	system("cls");
	for (int i = 0; i < 5; i++)
		puts("");
	printf("\t\t\t\t =================PHONE BOOK MENU=================           \n\n\n");
	printf("\t\t\t\t\t\t1.Add new contact\n");
	printf("\t\t\t\t\t\t2.Search contacts\n");
	printf("\t\t\t\t\t\t3.View full phone book\n");
	printf("\t\t\t\t\t\t4.Delete\n");
	printf("\t\t\t\t\t\t5.Edit contacts\n");
	printf("\t\t\t\t\t\t6.Sort out contacts\n");
	printf("\t\t\t\t\t\t7.Export to txt\n");
	printf("\t\t\t\t\t\t0.Exit\n");

}


void Exit(void){
	printf("\n");
	printf("                 Write in any field 'Exit'. To return to the menu.\n");
	printf("________________________________________________________________________________\n\n");
}

void Warning(void){
	printf("Phone Book clear\n");
}
void AddMenu(void){
	system("cls");
	for (int i = 0; i < 5; i++)
		puts("");
	printf("\t\t\t\t =================ADDITIONAL MENU=================           \n\n\n");
	printf("\t\t\t\t\t\t1.To end\n");
	printf("\t\t\t\t\t\t2.To start\n");
	printf("\t\t\t\t\t\t3.To position\n");
	printf("\t\t\t\t\t\t0.Back to menu\n");
}
void DelMenu(void){
	system("cls");
	for (int i = 0; i < 5; i++)
		puts("");
	printf("\t\t\t\t =================DELETE=================           \n\n\n");
	printf("\t\t\t\t\t\t1.Delete all telephone directory\n");
	printf("\t\t\t\t\t\t2.Delete contact\n");
	printf("\t\t\t\t\t\t0.Back to menu\n");
}
void SearchMenu(void){
	system("cls");
	for (int i = 0; i < 5; i++)
		puts("");
	printf("\t\t\t\t =================SEARCH=================           \n\n\n");
	printf("\t\t\t\t\t\t1.By name\n");
	printf("\t\t\t\t\t\t2.By surname\n");
	printf("\t\t\t\t\t\t3.By city\n");
	printf("\t\t\t\t\t\t4.By Skype\n");
	printf("\t\t\t\t\t\t0.Back to menu\n");
}



void EditMenu(void){
	printf("\t\t\t\t =================EDITING MENU=================           \n\n\n");
	printf("\t\t\t\t\t\t1.Name\n");
	printf("\t\t\t\t\t\t2.Surname\n");
	printf("\t\t\t\t\t\t3.Phone number\n");
	printf("\t\t\t\t\t\t4.Home number\n");
	printf("\t\t\t\t\t\t5.E-mail\n");
	printf("\t\t\t\t\t\t6.Skype\n");
	printf("\t\t\t\t\t\t7.City\n");
	printf("\t\t\t\t\t\t0.Back to menu\n");
}

void SortMenu(void){
	//system("cls");
	for (int i = 0; i < 5; i++)
		puts("");
	printf("\t\t\t\t =================SORT OUT MENU=================           \n\n\n");
	printf("\t\t\t\t\t\t1.By name\n");
	printf("\t\t\t\t\t\t2.By surname\n");
	printf("\t\t\t\t\t\t3.By city\n");
	printf("\t\t\t\t\t\t4.By Skype\n");
	printf("\t\t\t\t\t\t5.By Phone\n");
	printf("\t\t\t\t\t\t0.Back to menu\n");
}


void menu(void){
	Queue* line = (Queue*)malloc(sizeof(Queue));
	id = 0;
	CreateQueue(line);
	loadBinFile(line);
	while (1){
		menu1();
		switch (_getch())
		{
		case '1':{
					 int i = 0;
					 while(!i){
						 AddMenu(); 
						 PHONE *val = (PHONE*)malloc(sizeof(PHONE));

						 switch (_getch())
						 {	
						 case '1':{
									  phoneAdd(val);
									  putToQueue(line, *val);
									  printf("\t\t\tNew contact added!\n");
										int i = saveBinFile(line);
										if (i==0) printf("Error!\n");
									  _getch();
									   break;
						 }
						 case '2':{
									  phoneAdd(val);
									  AddHead(line, *val);
									  printf("\t\t\tNew contact added!\n");
									  int i = saveBinFile(line);
									  if (i ==0) printf("Write Error!\n");
									  _getch();
									  break;
						 }
						 case '3':
						 {		 
									 InsertPos(line);
									 int i = saveBinFile(line);
									 if (i == 0) printf("Write Error!\n");
									 _getch();
									 break;
						 }
						 case '0':{
									  i = 1;
									  break;
						 }
						 }
						
					 }
					 break;
		}
		case '2': {			 
					  int i = 0;
					  while (!i){
						  SearchMenu();
						  switch (_getch())
						  {
						  case '1':{
									   int tm = search(line,0);
									   if (tm == 0){
										   Warning();
										   system("pause");
									   }
									    
									   break;
						  }
						  case '2':{
									   int tm = search(line, 1);
									   if (tm == 0){
										   Warning();
										   system("pause");
									   }
									   
									   break;

						  }
						  case '3':{
									   int tm = search(line, 2);
									   if (tm == 0){
										   Warning();
										   system("pause");
									   }
									   
									   break;
						  }
						  case '4':{
									   int tm = search(line, 3);
									   if (tm == 0){
										   Warning();
										   system("pause");
									   }
									   					
										   break;
						  }
						  case '0':{
									   i = 1;
									   break;
						  }
						  }
					  }
					 
						  break;
		}
		case '3':{

					 if (line->head == NULL){
						 Warning();
						 system("pause");
						 _getch();
						 break;
					 }
					 else {
						outTablePhone(line);
						printf("\n\t\tTo exit the menu, press any key");
						 _getch();
						 break;
					 }
		}
		case '4':{
						int i=0;
					 while (!i)
					 {
						 DelMenu();
						 switch (_getch())
						 {
						 case '1': {
									int tm=ClearQueue(line);
									id = 0;
									saveBinFile(line);
									if (tm == 1){
										Warning();
										system("pause");
									}
										else
								printf("\n\n\t\t\tDatabase is clean!\n");		
									 break;
						 }
						 case '2':{
									  outTablePhone(line);
									  printf("\n\n\t\tEnter ID to dalete: ");
									  int pos;
									  scanf("%d", &pos);
									  int tm = DelPos(line,pos);
									  if (tm == 0){
										  Warning();
										  system("pause");
										  _getch();
									  }
									  else{
										  outTablePhone(line);
										  _getch();
									  }
								
									  break;
						 }
						 case '0':{
									 i=1;
									 saveBinFile(line);
									 break;							 
							}
						 }

					 }
			break;	
		}
		case '5':{
					 EditElement(line);
					 break;
		}
		case '6':{
					 if (isQueueEmpty(line)){
						 Warning();
						 _getch();
						 break;
					 }
					 int i = 0;
					 while (!i){
						 outTablePhone(line);
						 SortMenu();
						 PHONE *phoneArray = (PHONE*)malloc(id*sizeof(PHONE));
						 if (!phoneArray){
							 printf("Please restart program");
							 _getch();
							 exit(1);
						 }
						 Queue *buffer = (Queue*)malloc(sizeof(Queue));
						 if (!buffer){
							 printf("Please restart program");
							 _getch();
							 exit(1);
						 }
						 CreateQueue(buffer);
						 fflush(stdin);
						 switch (_getch())
						 {
						 case '1':{
									  if (AddArray(line, buffer, phoneArray) == 0){
										  Warning();
										  _getch();
										  i = 1;
									  }
									  SorBuble(phoneArray,1);
									  OutArray(line, buffer, phoneArray);
									  saveBinFile(line);
									  break;
						 }
						 case '2':{
									  if (AddArray(line, buffer, phoneArray) == 0){
										  Warning();
										  _getch();
										  i = 1;
									  }
									  SorBuble(phoneArray, 2);
									  OutArray(line, buffer, phoneArray);
									  saveBinFile(line);
									  break;
						 }
						 case '3':{
									  if (AddArray(line, buffer, phoneArray) == 0){
										  Warning();
										  _getch();
										  i = 1;
									  }
									  SorBuble(phoneArray, 3);
									  OutArray(line, buffer, phoneArray);
									  saveBinFile(line);
									  break;
						 }
						 case '4':{
									  if (AddArray(line, buffer, phoneArray) == 0){
										  Warning();
										  _getch();
										  i = 1;
									  }
									  SorBuble(phoneArray, 3);
									  OutArray(line, buffer, phoneArray);
									  saveBinFile(line);
									  break;
						 }
						 case '5':{
									  if (AddArray(line, buffer, phoneArray) == 0){
										  Warning();
										  _getch();
										  i = 1;
									  }
									  SortBublePhone(phoneArray);
									  OutArray(line, buffer, phoneArray);
									  saveBinFile(line);
									  break;

						 }
						 case '0':{
									  free(phoneArray);
									  menu();
									  break;

						 }
						 default:{ printf("\n\t\t\tEnter Again");
							 _getch();
						 }
						 }
					 }
					 break;
		}
		case '7':{
					 if (isQueueEmpty(line)){
						 Warning();
						 _getch();
						 break;
					 }
					 char namefile[15];
					 printf("\n\t\t\t\tEnter file name: ");
					 fflush(stdin);
					 gets(namefile);
					 while (strlen(namefile) == 0){
						 printf("\t\t\t\tEnter again!");
						 printf("\n\t\t\t\tEnter file name: ");
						 fflush(stdin);
						 gets(namefile);
					 }
					 if (fileSaveTxt(line, namefile) == 0){
						 Warning();
						 _getch();
					 }
					 else {
						 printf("\t\t\t\tExport successful!");
							 _getch();
					 }
					 break;
		}
		case '0': {
					 if (saveBinFile(line) == 0){
						  printf("Error write!");
						  _getch();
					 }
					 free(line);
					exit(1);
					}
		}
		}
}



