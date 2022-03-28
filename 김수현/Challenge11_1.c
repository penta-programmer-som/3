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

void printClass(CClass* sp)
{
	for (int i = 0; i < sp->num; i++) {
		printf("%s\t", sp->s[i].name);
		printf("%d\t%d\t%d\n", sp->s[i].midterm, sp->s[i].final, sp->s[i].average);
	}
}
//print 함수 challange2와 비교
void printStudent(Student* pAll)
{
	printf("%s\t%d\t%d\t%d\t", pAll->name, pAll->midterm, pAll->final, pAll->average);

}

void readClass(CClass* sp)
{
	for (int i = 0; i < sp->num; i++) {
		printf("Enter student name: ");
		scanf("%s", sp->s[i].name);
		printf("Enter midterm and final score: ");
		scanf("%d %d", &sp->s[i].midterm, &sp->s[i].final);
	}
}

void calculateStudentAverage(CClass* sp)
{
	for (int i = 0; i < sp->num; i++)
		sp->s[i].average = (sp->s[i].midterm + sp->s[i].final) / 2;
}

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
}

int main(void)
{
	CClass cp;

	Student all = { "All", 0, 0, 0 };

	printf("Enter a number of student: ");
	scanf("%d", &cp.num);
	//a)

	readClass(&cp);

	//b)
	calculateStudentAverage(&cp);

	printf("\n이름\t중간\t학기말\t평균\n");
	printClass(&cp);

	calculateAll(&cp, &all);
	printf("-------------------------------\n");
	printStudent(&all);
}