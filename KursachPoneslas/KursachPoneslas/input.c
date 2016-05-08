#include "input.h"
#include"queue.h"
#include"menu.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void phoneAdd(PHONE *val){
	system("cls");
	fflush(stdin);
	InputName(val);
	fflush(stdin);
	InputSurname(val);
	fflush(stdin);
	InputPhone(val);
	fflush(stdin);
	InputHomePhone(val);
	fflush(stdin);
	InputSkype(val);
	fflush(stdin);
	InputCity(val);
	fflush(stdin);
	InputEmail(val);
	id++;
}

void CopyBuf(PHONE *val, Queue *list){
	strcpy(val->name, list->head->val.name);
	strcpy(val->surname, list->head->val.surname);
	val->mob_one = list->head->val.mob_one;
	val->mob_two = list->head->val.mob_two;
	val->mob_three = list->head->val.mob_three;
	strcpy(val->homephone, list->head->val.homephone);
	strcpy(val->skype, list->head->val.skype);
	strcpy(val->city, list->head->val.city);
	strcpy(val->email, list->head->val.email);
}

void CopyBufL(PHONE *val, Queue *list){
	strcpy(val->name, list->tail->val.name);
	strcpy(val->surname, list->tail->val.surname);
	val->mob_one = list->tail->val.mob_one;
	val->mob_two = list->tail->val.mob_two;
	val->mob_three = list->tail->val.mob_three;
	strcpy(val->homephone, list->tail->val.homephone);
	strcpy(val->skype, list->tail->val.skype);
	strcpy(val->city, list->tail->val.city);
	strcpy(val->email, list->tail->val.email);
}

void inBuffer(Queue *queue, Queue *buf, int pos, int n){
	for (int i = 0; i < pos; i++){
		PHONE *val = (PHONE*)malloc(sizeof(PHONE));
		CopyBuf(val, queue);
		putToQueue(buf, *val);
		if (n == 1){
			putToQueue(queue, *val);
		}
		if (queue->head == queue->tail){
			ELEMENT* tmp = queue->head;
			queue->head = queue->tail = NULL;
			free(tmp);
			break;
		}
		ELEMENT* tmp = queue->head;
		queue->head = queue->head->next;
		free(tmp);
		free(val);
	}
}

void outBuffer(Queue* list, Queue *buf, int pos){
	for (int i = 0; i < pos; i++){
		PHONE *val = (PHONE*)malloc(sizeof(PHONE));
		CopyBufL(val, buf);
		AddHead(list, *val);
		DelTail(buf);
		free(val);
	}
}

int DelTail(Queue *queue){
	if (isQueueEmpty(queue)){
		return 0;
	}
	if (queue->head == queue->tail){
		queue->head = queue->tail = NULL;
	}
	else{
		int num = id - 1;
		Queue *buffer = (Queue*)malloc(sizeof(Queue));
		CreateQueue(buffer);
		inBuffer(queue, buffer, num, 1);
		ELEMENT *delet = queue->head;
		queue->head = queue->head->next;
		free(delet);
		ClearQueue(buffer);
		free(buffer);
	}
	return 1;
}

int DelPos(Queue *queue, int pos){
	if (isQueueEmpty(queue)){
		return 0;
	}
	int num = id;
	while (pos > num-1){
		printf("Enter again!\n");
		fflush(stdin);
		scanf("%d", &pos);
	}
	ELEMENT* tmp1 = queue->head;
	if (0 == pos){
		if (queue->head == queue->tail){
			queue->head = NULL;
			queue->tail = NULL;
			id = 0;
			free(tmp1);
		}
		else{
			queue->head = queue->head->next;
			free(tmp1);
			id--;
		}
		return 1;
	}
	else {
		Queue *bufqueue = (Queue*)malloc(sizeof(Queue));
		CreateQueue(bufqueue);
		int count = 0;
		ELEMENT *tmp = (ELEMENT*)malloc(sizeof(ELEMENT));
		while (!isQueueEmpty(queue)){
		
			takeFromQueue(queue, tmp);
			show(tmp, count);
			_getch();
			if (count == pos-1) {
				ELEMENT *delet = tmp;
				tmp = tmp->next;
				free(delet);
				id--;
				continue;
			}
			putToQueue(bufqueue, tmp->val);
			count++;
			//free(tmp);
		}
		while (!isQueueEmpty(bufqueue)) {
			takeFromQueue(bufqueue, tmp);
			putToQueue(queue, tmp->val);
		}
	}
	return 1;
}

void show(ELEMENT *tmp, int i){
	printf("|%3d|%10s|%13s|   %d-%d-%d  |%13s|%13s|%27s|%15s|\n", i,
		tmp->val.name,
		tmp->val.surname,
		tmp->val.mob_one, tmp->val.mob_two, tmp->val.mob_three,
		tmp->val.homephone,
		tmp->val.city,
		tmp->val.email,
		tmp->val.skype);
}

void outTablePhone(Queue *queue){
	system("cls");
	Queue *bufqueue;
	bufqueue = (Queue*)malloc(sizeof(Queue));
	CreateQueue(bufqueue);
	int i = 0;
	ELEMENT val;
	printf("+===+==========+=============+==============+=============+=============+===========================+===============+\n");
	printf("| ID|   NAME   |   Surname   |     Phone    |    HPhone   |     City    |           E-mail          |     Skype     |\n");
	printf("+===+==========+=============+==============+=============+=============+===========================+===============+\n");
	while (!isQueueEmpty(queue)){
		takeFromQueue(queue, &val);
		show(&val, i);
		putToQueue(bufqueue, val.val);
		i++;
	}
	
	while (!isQueueEmpty(bufqueue))
	{
	takeFromQueue(bufqueue, &val);
	putToQueue(queue, val.val);
	}
	printf("+===+==========+=============+==============+=============+=============+===========================+===============+\n");
	return;
}

int search(Queue *temp, int k){

	if (isQueueEmpty(temp)) return 0;
	system("cls");
	char str[15];
	printf("\n\n\t\t\tEnter a string to search for: ");
	fflush(stdin);
	gets(str);
	if (strlen(str) == 0){
		printf("Enter again!\n");
		_getch();
		fflush(stdin);
		search(temp, k);
	}
	int i = 1;
	int count = 0;
	char buf[30];
	Queue *bufqueue = (Queue*)malloc(sizeof(Queue));
	CreateQueue(bufqueue);
	ELEMENT tmp;
	while (!isQueueEmpty(temp)){
		//ELEMENT *tmp = bufqueue->head;
		
		takeFromQueue(temp, &tmp);
		if (k == 0) {
			strcpy(buf, tmp.val.name);
		}
		if (k == 1) {
			strcpy(buf, tmp.val.surname);
		}
		if (k == 2) {
			strcpy(buf, tmp.val.city);
		}
		if (k == 3) {
			strcpy(buf, tmp.val.skype);
		}
		if (strstr(buf, str) != 0) {
			//if (strcmp(buf,str)==0){
			
			if (i == 1) {
				printf("+===+==========+=============+==============+=============+=============+===========================+===============+\n");
				printf("| ID|   NAME   |   Surname   |     Phone    |    HPhone   |     City    |           E-mail          |     Skype     |\n");
				printf("+===+==========+=============+==============+=============+=============+===========================+===============+\n");
			}
			show(&tmp, count);
			i++;
		}
		putToQueue(bufqueue, tmp.val);
		
			count++;
	}
	
	if (i != 1) {
		printf("+===+==========+=============+==============+=============+=============+===========================+===============+\n");
		_getch();
		while (!isQueueEmpty(bufqueue))
		{
			takeFromQueue(bufqueue, &tmp);
			putToQueue(temp, tmp.val);
		}
	}
	system("cls");
	if (i == 1){
		printf("\tNothing found!");
		_getch();
		menu();

	}
	return 1;
}

void InputPhone(PHONE *newPhone){

	char *str;
	str = (char*)calloc(40, sizeof(char));
	char *str1;
	str1 = "Exit";
	system("cls");
	Exit();
	printf("Enter the mobile number in formate: 534-37-46\n\n");
	printf("Phone number:");
	gets(str);
	if ((sscanf(str, "%d - %d - %d", &newPhone->mob_one, &newPhone->mob_two, &newPhone->mob_three) != 3))
	{
		printf("Enter again.\n");
		InputPhone(newPhone);
	}

	free(str);
}

void InputName(PHONE *val){
	int num = 0;
	char *str;
	str = (char*)calloc(40, sizeof(char));
	char *str1;
	str1 = "Exit";
	system("cls");
	Exit();
	printf("(Input the name: Evgeniy)\n\n");
	printf("NAME: ");
	fflush(stdin);
	gets(val->name);
	str = val->name;
	num = strlen(str);
	if (!isupper(str[0])){
		str[0] = toupper(str[0]);
	}
	if (strlen(val->name) == 0){
		printf("An empty string.");
		_getch();
		InputName(val);
	}
	if (strlen(val->name) > 20){
		printf("\t\t\tThe number of characters exceeds the limit.");
		_getch();
		InputName(val);
	}
	if (strcmp(str, str1) == 0){
		system("cls");
		menu();
	}
	fflush(stdin);
	for (int i = 0; i < num; i++){
		if (!isalnum(str[i]) || !isalpha(str[i])){
			printf("Enter again!");
			_getch();
			InputName(val);
		}
	}
}

void InputSurname(PHONE *val){
	int num = 0;
	char *str;
	str = (char*)calloc(40, sizeof(char));
	system("cls");
	char *str1;
	str1 = "Exit";
	Exit();
	printf("(Input surname: Kurilenko)\n\n");
	printf("Surname:");
	gets(val->surname);
	str = val->surname;
	num = strlen(str);

	if (!isupper(str[0]))
	{
		str[0] = toupper(str[0]);
	}

	if (strlen(val->surname) == 0)
	{
		printf("An empty string.");
		InputSurname(val);
	}

	if (strlen(val->surname)>20)
	{
		printf("\t\t\tThe number of characters exceeds the limit.");
		_getch();
		InputSurname(val);
	}

	if (strcmp(str, str1) == 0)
	{
		system("cls");
		menu();
	}

	for (int i = 0; i <num; i++)
	{
		if (!isalnum(str[i]) || !isalpha(str[i]))
		{
			printf("Enter again!");
			_getch();
			InputSurname(val);
		}
	}
}

void InputHomePhone(PHONE *val){
	int num = 0;
	char *str;
	str = (char*)calloc(40, sizeof(char));
	system("cls");
	char *str1;
	str1 = "Exit";
	Exit();
	printf("(Enter the home number in formate: 357984)\n\n");
	printf("Home number: ");
	gets(val->homephone);
	str = val->homephone;
	num = strlen(str);
	if (strlen(val->homephone) == 0)
	{
		printf("An empty string.");
		InputHomePhone(val);
	}

	if (strlen(val->homephone)>6 || strlen(val->homephone)<5)
	{
		printf("\t\t\tThe number of characters exceeds the limit.");
		_getch();
		InputHomePhone(val);
	}

	if (strcmp(str, str1) == 0)
	{
		system("cls");
		menu();
	}

	for (int i = 0; i <num; i++)
	{
		if (!isdigit(str[i]))
		{
			printf("Enter again");
			_getch();
			InputHomePhone(val);
		}
	}
}

void InputEmail(PHONE *val){
	int num = 0, c = 0;
	char *str;
	str = (char*)calloc(30, sizeof(char));
	system("cls");
	char *str1;
	str1 = "Exit";
	Exit();
	printf("(E-MAIL CONTACT: kurilenko.e.m@outlook.com)\n\n");
	printf("E-MAIL:");
	gets(val->email);
	str = val->email;
	num = strlen(str);
	if (strcmp(str, str1) == 0)
	{
		system("cls");
		menu();
	}
	for (int i = 0; i < num; i++)
	{
		if (!isalnum(str[i]) && !isalpha(str[i]) && str[i] != '@' && str[i] != '.' && str[i] != '_')
		{
			printf("Enter again!");
			InputEmail(val);
		}
	}
	if (strlen(val->email)>25)
	{
		printf("The number of characters exceeds the limit.");
		_getch();
		InputEmail(val);
	}
	if (strlen(val->email) == 0)
	{
		printf("An empty string.");
		_getch();
		InputEmail(val);
	}

	for (int i = 0; i < num; i++)
	{
		if (str[0] == '@')
		{
			InputEmail(val);
		}
		if (str[i] == '@')
		{
			c++;
		}
	}
	if (c == 0 || c != 1)
	{
		c = 0;
		InputEmail(val);
	}

}

void InputCity(PHONE *val){
	int num = 0;
	char *str;
	str = (char*)calloc(30, sizeof(char));
	system("cls");
	char *str1;
	str1 = "Exit";
	Exit();
	printf("(Enter a city: Borisov)\n\n");
	printf("City: ");
	gets(val->city);

	str = val->city;
	num = strlen(str);

	if (!isupper(str[0]))
	{
		str[0] = toupper(str[0]);
	}

	if (strlen(val->city) == 0)
	{
		printf("An empty string");
		_getch();
		InputCity(val);
	}

	if (strlen(val->city)>25)
	{
		printf("The number of characters exceeds the limit.");
		_getch();
		InputCity(val);
	}

	if (strcmp(str, str1) == 0)
	{
		system("cls");
		menu();
	}

	for (int i = 0; i <num; i++)
	{
		if (!isalnum(str[i]) || !isalpha(str[i]))
		{
			printf("Enter again!");
			InputCity(val);
		}
	}
}

void InputSkype(PHONE *val){
	int num = 0;
	char *str;
	str = (char*)calloc(40, sizeof(char));
	char *str1;
	str1 = "Exit";
	system("cls");
	Exit();
	printf("(Enter Skype: badmatroskin)\n\n");
	printf("Skype: ");
	gets(val->skype);
	str = val->skype;
	num = strlen(str);
	if (strlen(val->name) == 0){
		printf("An empty string");
		_getch();
		InputSkype(val);
	}
	if (strlen(val->name) > 25){
		printf("\t\t\tThe number of characters exceeds the limit.");
		_getch();
		InputSkype(val);
	}
	if (strcmp(str, str1) == 0){
		system("cls");
		menu();
	}
	for (int i = 0; i < num; i++){
	if (!(str[i]<='z'&& str[i]>='a')){  //& (str[i]<48 || str[i] > 57) && (str[i]<192 || str[i]>255) && (str[i] != 95 || str[i] !=46)){
	printf("Enter again!");
	_getch();
	InputSkype(val);
	}
	}
}

int EditElement(Queue *queue){
	if (isQueueEmpty(queue)){
		Warning();
		_getch();
		return 1;
	}
	outTablePhone(queue);
	int pos;
	printf("\n\t\tEnter the ID you want to change: ");
	scanf("%d", &pos);
	while (pos > id - 1){
		printf("Error! Enter again! \n");
		fflush(stdin);
		scanf("%d", &pos);
	}
	ELEMENT *tmp;;
	/*printf("%d", id);
	_getch();*/
	Queue *bufqueue = (Queue*)malloc(sizeof(Queue));
	CreateQueue(bufqueue);
	inBuffer(queue, bufqueue, pos, 0);
	tmp = queue->head;
	system("cls");
	printf("\n");
	printf("+===+==========+=============+==============+=============+=============+===========================+===============+\n");
	printf("| ID|   NAME   |   Surname   |     Phone    |    HPhone   |     City    |           E-mail          |     Skype     |\n");
	printf("+===+==========+=============+==============+=============+=============+===========================+===============+\n");
	show(tmp, pos);
	printf("+===+==========+=============+==============+=============+=============+===========================+===============+\n");
	printf("\n\n");
	EditMenu();
	switch (_getch()){
	case '1':{
				 fflush(stdin);
				 InputName(&tmp->val);
				 break;
	}
	case '2':{
				 fflush(stdin);
				 InputSurname(&tmp->val);
				 break;
	}
	case '3':{
				 fflush(stdin);
				 InputPhone(&tmp->val);
				 break;
	}
	case '4':{
				 fflush(stdin);
				 InputHomePhone(&tmp->val);
				 break;
	}
	case '5':{
				 fflush(stdin);
				 InputEmail(&tmp->val);
				 break;
	}
	case '6':{
				 fflush(stdin);
				 InputSkype(&tmp->val);
				 break;
	}
	case '7':{
				 fflush(stdin);
				 InputCity(&tmp->val);
				 break;
	}
	case '0':{
				 return 0;
				 break;
	}

		break;
	}
	queue->head = tmp;
	outBuffer(queue, bufqueue, pos);
	outTablePhone(queue);
	ClearQueue(bufqueue);
	system("pause");
	//free(tmp);
	//free(val);
	int i = saveBinFile(queue);
	if (i == 1) printf("Error write!\n");
	_getch();
	menu();
	return 0;
}

int AddArray(Queue *queue, Queue *buffer, PHONE *value){
	PHONE *temp;
	for (int i = 0; i < id; i++){
		temp = value + i;
		CopyBuf(temp, queue);
		inBuffer(queue, buffer, 1, 0);
		if (isQueueEmpty(queue)){
			break;
		}
	}
	return 1;
}

int OutArray(Queue *queue, Queue *buffer, PHONE *value){
	PHONE *temp;
	for (int i = 0; i < id; i++){
		temp = value + i;
		putToQueue(queue, *temp);
	}
	ClearQueue(buffer);
}

void SorBuble(PHONE *phArr,int num){
	printf("\n\t\t1.Ascending\n\t\t2.Descending\n");
	char ch[5];
	int way;
	fflush(stdin);
	gets(ch);
	while (ch == "1" || ch == "2"){
		printf("\n\t\t\tEnter Again");
		fflush(stdin);
		gets(ch);
	}
	way = atoi(ch);
	char str[12], str2[12];
	for (int i = 0; i < id; i++){
		for (int j = 0; j < id - 1; j++){
			if (num == 1){
				strcpy(str, phArr[j].name);
				strcpy(str2, phArr[j + 1].name);
			}
			if (num == 2){
				strcpy(str, phArr[j].surname);
				strcpy(str2, phArr[j + 1].surname);
			}
			if (num == 3){
				strcpy(str, phArr[j].city);
				strcpy(str2, phArr[j + 1].city);
			}
			if (num == 4){
				strcpy(str, phArr[j].skype);
				strcpy(str2, phArr[j + 1].skype);
			}
			switch (way){
			case 1:{
					   if (strcmp(str, str2)>0){
						   PHONE tmp = phArr[j];
						   phArr[j] = phArr[j + 1];
						   phArr[j + 1] = tmp;
					   }
					   break;
			}
			case 2:{
					   if (strcmp(str, str2)<0){
						   PHONE tmp = phArr[j];
						   phArr[j] = phArr[j + 1];
						   phArr[j + 1] = tmp;
					   }
					   break;
				}
			}
		}
	}
}

void SortBublePhone(PHONE *phArr){
	printf("\n\t\t1.Ascending\n\t\t2.Descending\n");
	char ch[5];
	int way;
	fflush(stdin);
	gets(ch);
	while (ch == "1" || ch == "2"){
		printf("\n\t\t\tEnter Again");
		fflush(stdin);
		gets(ch);
	}
	way = atoi(ch);
	int num, num2;
	for (int i = 0; i < id; i++){
		for (int j = 0; j < id - 1; j++){
			num = phArr[j].mob_one;
			num2 = phArr[j + 1].mob_one;
			switch (way){
			case 1:{
					   if (num>num2){
						   PHONE tmp = phArr[j];
						   phArr[j] = phArr[j + 1];
						   phArr[j + 1] = tmp;
					   }
					   break;
			}
			case 2:{
					   if (num<num2){
						   PHONE tmp = phArr[j];
						   phArr[j] = phArr[j + 1];
						   phArr[j + 1] = tmp;
					   }
					   break;
				}
			}
		}
	}
}

int fileSaveTxt(Queue *queue, const char *name){
	if (isQueueEmpty(queue)){
		return 0;
	}
	FILE *file;
	char namebuf[20];
	strcpy(namebuf, name);
	strcat(namebuf, ".txt");
	if ((file = fopen(namebuf, "w")) == NULL){
		printf("Error open\n");
		_getch();
		return 0;
	}
	int i = 0;
	fprintf(file, "+===+==========+=============+==============+=============+=============+===========================+===============+\n");
	fprintf(file, "| ID|   NAME   |   Surname   |     Phone    |    HPhone   |     City    |           E-mail          |     Skype     |\n");
	fprintf(file, "+===+==========+=============+==============+=============+=============+===========================+===============+\n");
	Queue *bufqueue = (Queue*)malloc(sizeof(Queue));
	CreateQueue(bufqueue);
	ELEMENT value;
	//inBuffer(line, bufqueue, id, 1);
	while (!isQueueEmpty(queue))
	{
		takeFromQueue(queue, &value);
		fprintf(file, "|%3d|%10s|%13s|   %d-%d-%d  |%13s|%13s|%27s|%15s|\n", i,
			value.val.name,
			value.val.surname,
			value.val.mob_one, value.val.mob_two, value.val.mob_three,
			value.val.homephone,
			value.val.city,
			value.val.email,
			value.val.homephone,
			value.val.skype);
		i++;
		putToQueue(bufqueue, value.val);
	}
	while (!isQueueEmpty(bufqueue)) {
		takeFromQueue(bufqueue, &value);
		putToQueue(queue, value.val);
	}
	fprintf(file, "+===+==========+=============+==============+=============+=============+===========================+===============+\n");
	free(bufqueue);
	fclose(file);
	return 1;
}

int loadBinFile(Queue *q){
	FILE *file = fopen("FILE_BD.bin", "rb");
	if (!file)
	{
		return 0;
	}
	PHONE ph;
	while (!feof(file))
	{
		if (fread(&ph, sizeof(PHONE), 1, file) > 0)
		{
			id++;
			putToQueue(q, ph);
		}
	}
	fclose(file);
	return 1;
}

int saveBinFile(Queue *temp){
	FILE *file = fopen("FILE_BD.bin", "wb");

	if (!file){
		return 0;
	}
	Queue *bufqueue = (Queue*)malloc(sizeof(Queue));
	CreateQueue(bufqueue);
	ELEMENT value;
	int flag = 0;
	while (!isQueueEmpty(temp))
	{
		takeFromQueue(temp, &value);
		if (fwrite(&value.val, sizeof(PHONE), 1, file) < 1){
			fclose(file);
			return 1;
		}
		putToQueue(bufqueue, value.val);
		flag++;
	}
	if (flag != 0) {
		while (!isQueueEmpty(bufqueue)){
			takeFromQueue(bufqueue, &value);
			putToQueue(temp, value.val);
		}
	}
	free(bufqueue);
	fclose(file);
	return 1;
}