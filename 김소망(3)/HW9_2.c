#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include<stdlib.h>
#include <string.h> 
int main(void)
{
	char id[15];
	char n1;
	char n2;
	int i;
	int year = 0;

	printf("�ֹε�Ϲ�ȣ �Է�<'-'����>:");
	fgets(id, sizeof(id), stdin);
	id[6] = '-';
	printf("����� 19%c%c�⵵ ���̽ñ���\n", id[0], id[1]);

	for (i = 0; i < 1; i++)
		n1 = id[i];
	for (i = 1; i < 2; i++)
		n2 = id[i];

	year = atoi(&n1) * 10 + atoi(&n2) + 1900;

	if (id[7] == '1') {
		printf("���ں��̽ñ���.\n");
		printf("��ռ��� 77�� ���ϸ� %d���� ��ٰ� ���˴ϴ�\n", year + 77);
	}
	else if (id[7] == '2') {
		printf("���ں��̽ñ���.\n");
		printf("��ռ��� 84�� ���ϸ� %d���� ��ٰ� ���˴ϴ�\n", year + 84);
	}
}