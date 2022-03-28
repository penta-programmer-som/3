#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct student {
	char name[20];
	int midterm;
	int final;
	int average;
};

// typedef ����Ͽ� Student ���� 
typedef struct student Student;

struct cClass {
	int num;
	Student s[40]; // ����ü ���� ����ü 
};

// typedef ����Ͽ� CClass ���� 
typedef struct cClass CClass;

void printClass(CClass* cp)
{
	for (int i = 0; i < cp->num; i++) {
		printf("%s\t", cp->s[i].name);
		printf("%d\t%d\t%d\n", cp->s[i].midterm, cp->s[i].final, cp->s[i].average);
	}
}

// Student ����ü ������ name, midterm, final�� �д´�
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

// Student ����ü ������ average ���� ����Ѵ� average = (mid + fin) / 2
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

	readClass(&cp); // a) �κ�

	calculateStudentAverage(&cp); // b) �κ� 

	printf("\n�̸�\t�߰�\t�б⸻\t���\n");
	printClass(&cp);

	calculateAll(&cp, &all);
	printf("-----------------------------------------\n");
	printStudent(&all);
}