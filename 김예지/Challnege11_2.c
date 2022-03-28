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

void printStudent(Student* ap)
{
	printf("%s\t", ap->name);
	printf("%d\t%d\t%d\n", ap->midterm, ap->final, ap->average);
}

Student calculateAll2(CClass* cp)
{
	Student pAll = { "All",0,0,0 };
	int i;

	for (i = 0; i < cp->num; i++) {
		pAll.midterm += cp->s[i].midterm;
		pAll.final += cp->s[i].final;
		pAll.average += cp->s[i].average;
	}
	pAll.midterm = pAll.midterm / cp->num;
	pAll.final = pAll.final / cp->num;
	pAll.average = pAll.average / cp->num;

	return pAll;
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

	all = calculateAll2(&cp);
	printf("-----------------------------------------\n");
	printStudent(&all);
}