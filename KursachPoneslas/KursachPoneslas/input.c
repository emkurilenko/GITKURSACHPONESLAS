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

void CopyBuf(PHONE *val, ELEMENT *element){
	strcpy(val->name, element->val.name);
	strcpy(val->surname, element->val.surname);
	val->mob_one = element->val.mob_one;
	val->mob_two = element->val.mob_two;
	val->mob_three = element->val.mob_three;
	strcpy(val->homephone, element->val.homephone);
	strcpy(val->skype, element->val.skype);
	strcpy(val->city, element->val.city);
	strcpy(val->email, element->val.email);
}

int DelPos(Queue *queue, int pos){
	if (isQueueEmpty(queue)){
		return 0;
	}
	int num = id;
	while (pos > num-1){
		printf("\t\t\tEnter again!\n");
		fflush(stdin);
		printf("\t\t\t\t");
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
			if (count == pos-1) {
				if (queue->head == queue->tail) {
					ELEMENT *delet = queue->head;
					queue->head = NULL;
					queue->tail = NULL;
					free(delet);
					break;
				}
				ELEMENT *delet = queue->head;
				queue->head = delet->next;
				free(delet);
			 }
			putToQueue(bufqueue, tmp->val);
			count++;
		}
		while (!isQueueEmpty(bufqueue)) {
			takeFromQueue(bufqueue, tmp);
			putToQueue(queue, tmp->val);
		}
		id--;
		return 1;
	}
	
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

void InputName(PHONE *val) {
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
	if (!isupper(str[0])) {
		str[0] = toupper(str[0]);
	}
	if (strlen(val->name) == 0) {
		printf("An empty string.");
		_getch();
		InputName(val);
	}
	if (strlen(val->name) > 20) {
		printf("\t\t\tThe number of characters exceeds the limit.");
		_getch();
		InputName(val);
	}
	if (strcmp(str, str1) == 0) {
		system("cls");
		menu();
	}
	fflush(stdin);
	for (int i = 0; i < num; i++) {
		if (!isalnum(str[i]) || !isalpha(str[i])) {
			printf("Enter again!");
			_getch();
			InputName(val);
		}
	}
}

void InputSurname(PHONE *val) {
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

void InputHomePhone(PHONE *val) {
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

void InputEmail(PHONE *val) {
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

void InputCity(PHONE *val) {
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

void InputSkype(PHONE *val) {
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
	//strcpy(str, val->name);
	str = val->skype;
	num = strlen(str);
	if (strlen(val->name) == 0) {
		printf("An empty string");
		_getch();
		InputSkype(val);
	}
	if (strlen(val->name) > 25) {
		printf("\t\t\tThe number of characters exceeds the limit.");
		_getch();
		InputSkype(val);
	}
	if (strcmp(str, str1) == 0) {
		system("cls");
		menu();
	}
	for (int i = 0; i < num; i++) {
		if (!(str[i] <= 'z'&& str[i] >= 'a')) {  //& (str[i]<48 || str[i] > 57) && (str[i]<192 || str[i]>255) && (str[i] != 95 || str[i] !=46)){
			printf("Enter again!");
			_getch();
			InputSkype(val);
		}
	}
}

int EditElement(Queue *queue){
	if (isQueueEmpty(queue)){
		return 0;
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
	int count = 0;
	Queue *bufqueue = (Queue*)malloc(sizeof(Queue));
	CreateQueue(bufqueue);
	ELEMENT *tmp = (ELEMENT*)malloc(sizeof(ELEMENT));
	while (!isQueueEmpty(queue)) {
		takeFromQueue(queue, tmp);
		if (count == pos) {
			Edit(tmp, count);
		}
		putToQueue(bufqueue, tmp->val);
		count++;
	}
	while (!isQueueEmpty(bufqueue)) {
		takeFromQueue(bufqueue, tmp);
		putToQueue(queue, tmp->val);
	}
	outTablePhone(queue);
	ClearQueue(bufqueue);
	free(bufqueue);
	system("pause");
	if (saveBinFile(queue) == 0) printf("Error write!\n");
	_getch();
	menu();
	return 1;
}

int Edit(ELEMENT *tmp,int pos) {
	system("cls");
	printf("\n");
	printf("+===+==========+=============+==============+=============+=============+===========================+===============+\n");
	printf("| ID|   NAME   |   Surname   |     Phone    |    HPhone   |     City    |           E-mail          |     Skype     |\n");
	printf("+===+==========+=============+==============+=============+=============+===========================+===============+\n");
	show(tmp, pos);
	printf("+===+==========+=============+==============+=============+=============+===========================+===============+\n");
	printf("\n\n");
	EditMenu();
	switch (_getch()) {
	case '1': {
		fflush(stdin);
		InputName(&tmp->val);
		break;
	}
	case '2': {
		fflush(stdin);
		InputSurname(&tmp->val);
		break;
	}
	case '3': {
		fflush(stdin);
		InputPhone(&tmp->val);
		break;
	}
	case '4': {
		fflush(stdin);
		InputHomePhone(&tmp->val);
		break;
	}
	case '5': {
		fflush(stdin);
		InputEmail(&tmp->val);
		break;
	}
	case '6': {
		fflush(stdin);
		InputSkype(&tmp->val);
		break;
	}
	case '7': {
		fflush(stdin);
		InputCity(&tmp->val);
		break;
	}
	case '0': {
		return 0;
		break;
	}

			  break;
	}
}

int AddArray(Queue *queue, PHONE *value){
	PHONE *temp;
	ELEMENT *element = (ELEMENT*)malloc(sizeof(ELEMENT));
	int i = 0;
	while (!isQueueEmpty(queue))
	{
		temp = value + i;
		takeFromQueue(queue, element);
		CopyBuf(temp, element);
		i++;
	}	
	return 1;
}

int OutArray(Queue *queue, PHONE *value){
	PHONE *temp;
	for (int i = 0; i < id; i++){
		temp = value + i;
		putToQueue(queue, *temp);
	}
	return 1;
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