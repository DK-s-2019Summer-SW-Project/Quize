#include<stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNNINGS

#define NAME_LEN 20
#define GRADE_LEN 20
#define MAX_PERSON 100

typedef struct _PERSON
{
	char name[NAME_LEN];
	char grade[GRADE_LEN];

}PERSON;

void menu(void);
void insertinfo(PERSON*, int*); // insert the data
void searchinfo(PERSON*, int*); // search the data
void printinfo(PERSON*, int*); // print the data
void loadinfo(PERSON*, int*); // load the data
void storeinfo(PERSON*, int*); // store the data
void endinfo(PERSON*, int*); // finish the statement

int main()
{
	int choice;
	PERSON PerArr[MAX_PERSON]; // data to store array
	int PerNum = 0; // number of people that is stored

	loadinfo(PerArr, &PerNum);

	while (1)
	{
		menu();
		printf("Chose the menu: ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			insertinfo(PerArr, &PerNum);
			break;
		case 2:
			searchinfo(PerArr, &PerNum);
			break;
		case 3:
			printinfo(PerArr, &PerNum);
			break;
		case 4:
			loadinfo(PerArr, &PerNum);
			break;
		case 5:
			storeinfo(PerArr, &PerNum);
			break;
		case 6:
			endinfo(PerArr, &PerNum);
			break;
		default:
			printf("wrong input\n");
			break;
		}
	}
	return 0;
}

void menu(void)
{
	printf("\n---------Menu--------\n");
	printf("             1. Insert \n");
	printf("             2. Search \n");
	printf("             3. printfinfo \n");
	printf("             4. load data\n");
	printf("             5. Storeinfo\n");
	printf("             6. Exit\n");
}

void insertinfo(PERSON *parr, int*pnum)
{
	char name[NAME_LEN], grade[GRADE_LEN];
	int l, m, s;
	double avg = 0;

	printf("[ INSERT ]\n");
	printf("insert the student ID: ");
	scanf("%s", name);
	printf("input student grade -Language: ");
	printf("input student grade -Math: ");
	printf("input student grade -Science: ");
	scanf_s("%d", &l);
	scanf_s("%d", &m);
	scanf_s("%d", &s);
	avg = (l + m + s) / 3;
	printf("The average of student is: %lf", avg);
	strcpy(parr[*pnum].name, name);
	//strcpy(parr[*pnum].grade,avg);
	(*pnum)++;

	printf("---------------------> Data insert complit-----------\n");
}

void searchinfo(PERSON*parr, int num)
{
	int i;
	char name[NAME_LEN];
	printf("[ SEARCH ]\n");
	printf("insert the n for searching: ");
	scanf("%s", name);

	for (i = 0; i < num; i++)
	{
		printf("--> Name: %s / total: %s\n", 
			parr[i].name,parr[i].grade);
		return;
	}
	printf("------------Data Not found-------------\n");
}

void printinfo(PERSON*parr, int num) // print  all the information
{
	int i;
	printf("[ Print All Data ]\n");

	for (i = 0; i < num; i++)
	printf("Name is : %s / total: %s\n", parr[i].name, parr[i].grade);
}

void loadinfo(PERSON*parr, int *pnum)
{
	FILE*file = fopen("data.dat", "rt");
	if (file == NULL)
	{
		return;
	}
	while (1)
	{
		fscanf(file, "%s %s", parr[*pnum].name, parr[*pnum].grade);
		if (feof(file) != 0)
			break;
		(*pnum)++;
	}
}

void storeinfo(PERSON*parr, int num)
{
	int i;

	FILE*file = fopen("data/data", "wt");
	if (file == NULL)
	{
		printf("file open error!\n");
		return;
	}

	for (i = 0; i < num; i++)
		fprintf(file, "%s %s", parr[i].name, parr[i].grade);
}

void exit(void)
{
	printf("thank you for using!\n");
	return 0;
}