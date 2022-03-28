#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct student {
	char name[20];
	int midterm;
	int final;
	int average;
};

// typedef 사용하여 Student 정의 
typedef struct student Student;

struct cClass {
	int num;
	Student s[40]; // 구조체 안의 구조체 
};

// typedef 사용하여 CClass 정의 
typedef struct cClass CClass;

void printClass(CClass* cp)
{
	for (int i = 0; i < cp->num; i++) {
		printf("%s\t", cp->s[i].name);
		printf("%d\t%d\t%d\n", cp->s[i].midterm, cp->s[i].final, cp->s[i].average);
	}
}

// Student 구조체 변수에 name, midterm, final을 읽는다
void readClass(CClass* cp)
{
	int i;

	for (i = 0; i < cp->num; i++) {
		printf("Enter student name : ");
		scanf("%s", cp->s[i].name);
		printf("Enter midterm and final score : ");
		scanf("%d %d", &cp->s[i].midterm, &cp->s[i].final);
	}
}

// Student 구조체 변수에 average 값을 계산한다 average = (mid + fin) / 2
void calculateStudentAverage(CClass* cp)
{
	int i;

	for (i = 0; i < cp->num; i++)
		cp->s[i].average = (cp->s[i].midterm + cp->s[i].final) / 2;
}

void calculateAll(CClass* cp, Student* ap)
{
	int i;

	for (i = 0; i < cp->num; i++) {
		ap->midterm += cp->s[i].midterm;
		ap->final += cp->s[i].final;
		ap->average += cp->s[i].average;
	}
	ap->midterm = ap->midterm / 3;
	ap->final = ap->final / 3;
	ap->average = ap->average / 3;
}

void printStudent(Student* ap)
{
	printf("%s\t", ap->name);
	printf("%d\t%d\t%d\n", ap->midterm, ap->final, ap->average);
}
int main(void)
{
	CClass cp;

	Student all = { "All",0,0,0 };

	printf("Enter a number of student : ");
	scanf("%d", &cp.num);

	readClass(&cp); // a) 부분

	calculateStudentAverage(&cp); // b) 부분 

	printf("\n이름\t중간\t학기말\t평균\n");
	printClass(&cp);

	calculateAll(&cp, &all);
	printf("-----------------------------------------\n");
	printStudent(&all);
}