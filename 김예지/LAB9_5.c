#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char str[50];
	int i;
	char* name;
	char* age;

	printf("�̸�(������� ���ĺ���� ����)�� ���̸� �Է��϶�(��: Abba 50): ");
	gets(str);

	puts("�Է��� ����: ");
	puts(str);

	name = strtok(str, " ");
	age = strtok(NULL, "\0");

	i = atoi(age) + 10;
	printf("�̸��� %s �̰� �ѱ� ���̴� %s �Դϴ�.\n", name, age);
	printf("10 �� �Ŀ��� %d ���Դϴ�.\n", i);
}