#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Student {
	char name[20];
	int midterm;
	int final;
	int average;
}Student;

typedef struct CClass {
	int num;
	Student s[40];
}CClass;

Student calculateAll2(CClass* cp)
{
	Student pAll = { "All", 0,0,0 };

	for (int i = 0; i < cp->num; i++)
	{
		pAll.midterm += cp->s[i].midterm;
		pAll.final += cp->s[i].final;
		pAll.average += cp->s[i].average;
	}
	pAll.midterm /= 3;
	pAll.final /= 3;
	pAll.average /= 3;
	return pAll;
	/*
	void calculateAll(CClass* cp, Student* pAll)
{
	for (int i = 0; i < cp->num; i++)
	{
		pAll->midterm += cp->s[i].midterm;
		pAll->final += cp->s[i].final;
		pAll->average += cp->s[i].average;
	}
	pAll->midterm /= 3;
	pAll->final /= 3;
	pAll->average /= 3;
}*/
}
void printStudent(Student* sp)
{
	printf("%s\t", sp->name);
	printf("%d\t%d\t%d\n", sp->midterm, sp->final, sp->average);
}

void readStudentScore(Student* sp)
{
	printf("Enter student name: ");
	scanf("%s", sp->name);
	printf("Enter midterm and final score: ");
	scanf("%d %d", &sp->midterm, &sp->final);
}

void calculateStudentAverage(Student* sp)
{
	sp->average = (sp->midterm + sp->final) / 2;
}

int main(void)
{
	CClass cp;
	int i;
	Student all = { "Total", 0, 0, 0 };

	printf("Enter a number of student: ");
	scanf("%d", &cp.num);
	//a)

	for (i = 0; i < cp.num; i++)
		readStudentScore(&cp.s[i]);


	//b)
	for (i = 0; i < cp.num; i++)
		calculateStudentAverage(&cp.s[i]);


	printf("\n이름\t중간\t학기말\t평균\n");
	for (i = 0; i < cp.num; i++)
		printStudent(&cp.s[i]);

	all = calculateAll2(&cp);
	printStudent(&all);
}