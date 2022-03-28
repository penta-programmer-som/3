#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
struct student {
	char name[20];
	int midterm;
	int final;
	int average;
};
typedef struct student Student;
struct cClass {
	int num;
	Student s[40];
};
typedef struct cClass CClass;

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

void caculateStudentAverage(Student* sp)
{
	sp->average = (sp->midterm + sp->final) / 2;
}

Student caculateAll2(CClass* cp)
{
	Student pAll = { "All", 0, 0, 0 };
	int i;

	for (i = 0; i < cp->num; i++) {
		pAll.midterm += cp->s[i].midterm;
		pAll.final += cp->s[i].final;
		pAll.average += cp->s[i].average;
	}

	pAll.midterm /= i;
	pAll.final /= i;
	pAll.average /= i;

	return pAll;
}

int main(void)
{
	CClass cp;
	int i;
	Student all;

	printf("Enter a number of student:");
	scanf("%d", &cp.num);

	for (i = 0; i < cp.num; i++)
		readStudentScore(&cp.s[i]);
	for (i = 0; i < cp.num; i++)
		caculateStudentAverage(&cp.s[i]);

	printf("\n이름\t중간\t학기말\t평균\n");
	for (i = 0; i < cp.num; i++)
		printStudent(&cp.s[i]);
	all = caculateAll2(&cp);
	printf("-----------------------------------------\n");
	printStudent(&all);
}