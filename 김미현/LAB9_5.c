#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str[50];
	char* name, * age;
	char delimeter[] = " \n,\0";
	char* token;

	printf("�̸�(������� ���ĺ���� ����)�� ���̸� �Է��϶� (��: Abba 50): ");
	gets(str);
	puts("�Է��� ���� : ");
	puts(str);

	token = strtok(str, delimeter);
	name = token;
	token = strtok(NULL, delimeter);
	age = token;

	printf("�̸��� %s�̰� �ѱ� ���̴� %s�Դϴ�.\n", name, age);
	printf("10�� �Ŀ��� %d���Դϴ�.\n", atoi(age) + 10);
	return 0;
}
