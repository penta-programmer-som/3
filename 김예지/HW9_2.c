#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
	char number[20];
	char year[5];
	int age;

	printf("�ֹε�Ϲ�ȣ �Է�('-' ����) : ");
	fgets(number, sizeof(number), stdin);

	strncpy(year, number, 2);
	year[2] = '\0';
	printf("����� 19%s�⵵ ���̱���\n", year);
	age = atoi(year) + 1900;

	if (number[7] == '1') {
		printf("���ں��̽ñ���.\n");
		printf("��� ���� 77�� ���ϸ� %d���� ��ٰ� ���˴ϴ�.\n", age + 77);
	}
	else if (number[7] == '2') {
		printf("���ں��̽ñ���.\n");
		printf("��� ���� 84�� ���ϸ� %d���� ��ٰ� ���˴ϴ�.\n", age + 84);
	}

}