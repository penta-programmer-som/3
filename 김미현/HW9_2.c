#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	char s[50];
	char birth[50] = { 0 };
	char f[] = "����";
	char m[] = "����";
	char* token1;
	char* token2;
	char delimiters[] = "-";
	char id[50] = { 0 };
	int year;

	printf("�ֹε�Ϲ�ȣ �Է�<'-'����>:");
	scanf("%s", s);

	token1 = strtok(s, delimiters);
	token2 = strtok(NULL, "\0");

	strncpy(id, token2, 1);
	id[1] = '\0';

	if (id[0] == '1' || id[0] == '2')
		strcpy(birth, "19");
	else if (id[0] == '3' || id[0] == '4')
		strcpy(birth, "20");

	strncat(birth, token1, 2);

	printf("����� %s�⵵ ���̽ñ���\n", birth);

	year = atoi(birth);
	if (id[0] == '2' || id[0] == '4') {
		printf("%s���̽ñ���\n", f);
		printf("��� ���� 84�� ���ϸ� %d����� ��ٰ� ���˴ϴ�.", year + 84);
	}
	else if (id[0] == '1' || id[0] == '3') {
		printf("%s���̽ñ���\n", m);
		printf("��� ���� 77�� ���ϸ� %d����� ��ٰ� ���˴ϴ�.", year + 77);
	}
}