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
	Student pAll = { "All", 0, 0, 0 };
	int i;

	for (i = 0; i < cp->num; i++)
		pAll.midterm += cp->s[i].midterm;
	pAll.midterm /= cp->num;

	for (i = 0; i < cp->num; i++)
		pAll.final += cp->s[i].final;
	pAll.final /= cp->num;

	for (i = 0; i < cp->num; i++)
		pAll.average += cp->s[i].average;
	pAll.average /= cp->num;

	return pAll;
}

void printStudent(Student* cp)
{
	printf("%s\t", cp->name);
	printf("%d\t%d\t%d\n", cp->midterm, cp->final, cp->average);
}

void readStudentScore(Student* cp)
{
	printf("Enter student name: ");
	scanf("%s", cp->name);
	printf("Enter midterm and final score: ");
	scanf("%d %d", &cp->midterm, &cp->final);
}

void calculateStudentAverage(Student* cp)
{
	cp->average = (cp->midterm + cp->final) / 2;
}

int main(void)
{
	int i;
	CClass cp;
	Student all = { "All", 0, 0, 0 };

	printf("Enter a number of student:");
	scanf("%d", &cp.num);

	for (i = 0; i < cp.num; i++)
		readStudentScore(&cp.s[i]);

	for (i = 0; i < cp.num; i++)
		calculateStudentAverage(&cp.s[i]);

	printf("\n 이름\t 중간\t 학기말\t 평균\n");
	for (i = 0; i < cp.num; i++)
		printStudent(&cp.s[i]);

	all = calculateAll2(&cp);
	printf("----------------------------------\n");
	printStudent(&all);
}