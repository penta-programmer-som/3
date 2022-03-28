﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct student {
	char name[20];
	int midterm;
	int final;
	int average;
} Student;

typedef struct cClass {
	int num;
	Student s[40];
} CClass;

void readClass(CClass* cp)
{
	for (int i = 0; i < cp->num; i++) {
		printf("Enter a student name : ");
		scanf("%s", cp->s[i].name);
		printf("Enter midterm and final score : ");
		scanf("%d %d", &cp->s[i].midterm, &cp->s[i].final);
	}
}

void calculateClassAverage(CClass* cp)
{
	for (int i = 0; i < cp->num; i++)
		cp->s[i].average = (cp->s[i].midterm + cp->s[i].final) / 2;
}

void printClass(CClass* cp)
{
	for (int i = 0; i < cp->num; i++)
		printf("%s\t%d\t%d\t%d\n", cp->s[i].name, cp->s[i].midterm, cp->s[i].final, cp->s[i].average);
}

void calculateAll(CClass* cp, Student* all)
{
	for (int i = 0; i < cp->num; i++) {
		all->midterm += cp->s[i].midterm;
		all->final += cp->s[i].final;
		all->average += cp->s[i].average;
	}
	all->midterm /= cp->num;
	all->final /= cp->num;
	all->average /= cp->num;
}

void printStudent(Student* all)
{
	printf("\n%s\t%d\t%d\t%d\n", all->name, all->midterm, all->final, all->average);
}

int main(void)
{
	CClass cp;
	Student all = { "All", 0, 0, 0 };

	printf("Enter a number of student: ");
	scanf("%d", &cp.num);
	readClass(&cp);
	calculateClassAverage(&cp);

	printf("\n이름\t중간\t기말\t평균\n");
	printClass(&cp);
	calculateAll(&cp, &all);
	printf("__________________________\n");
	printStudent(&all);
	return 0;
}