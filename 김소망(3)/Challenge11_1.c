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

void printClass(CClass* cp) {
	int i;

	for (i = 0; i < cp->num; i++) {
		printf("%s\t", cp->s[i].name);
		printf("%d\t%d\t%d\n", cp->s[i].midterm, cp->s[i].final, cp->s[i].average);
	}
}

void printStudent(Student* pAll)
{
	printf("%s\t%d\t%d\t%d\t", pAll->name, pAll->midterm, pAll->final, pAll->average);

}

void readClass(CClass* cp)
{
	int i;

	for (i = 0; i < cp->num; i++) {
		printf("Enter student name: ");
		scanf("%s", cp->s[i].name);
		printf("Enter midterm and final score: ");
		scanf("%d %d", &cp->s[i].midterm, &cp->s[i].final);
	}
}

void calculateClassAverage(CClass* cp)
{
	int i;

	for (i = 0; i < cp->num; i++)
		cp->s[i].average = (cp->s[i].midterm + cp->s[i].final) / 2;
}

void calculateAll(CClass* cp, Student* pAll) {
	int i;

	for (i = 0; i < cp->num; i++)
		pAll->midterm += cp->s[i].midterm;
	pAll->midterm /= cp->num;

	for (i = 0; i < cp->num; i++)
		pAll->final += cp->s[i].final;
	pAll->final /= cp->num;

	for (i = 0; i < cp->num; i++)
		pAll->average += cp->s[i].average;
	pAll->average /= cp->num;
}
int main(void)
{
	CClass cp;

	Student all = { "All", 0, 0, 0 };

	printf("Enter a number of student:");
	scanf("%d", &cp.num);

	readClass(&cp);

	calculateClassAverage(&cp);

	printf("\n 이름\t 중간\t 학기말\t 평균\n");
	printClass(&cp);

	calculateAll(&cp, &all);
	printf("----------------------------------\n");
	printStudent(&all);
}