#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char string[50]; // �ԷµǴ� ���ڿ��� ����
	char alphaString1[50]; // �Է¹��ڿ����� ���ĺ��� ����
	char alphaString2[50]; // ��ҹ��ڸ� �ٲ�
	char digitString[50];
	char convertedString[50]; // ���ڵ�� ���ڵ�� ��迭�� ���ڿ� 
	int i;
	int a = 0, b = 0;
	int len = 0;

	printf("���ڿ��� �Է��ϼ��� : "); // fgets ���
	fgets(string, sizeof(string), stdin);

	len = strlen(string);

	for (i = 0; i < len; i++) {
		if (isalpha(string[i]) != '\0')
			alphaString1[a++] = string[i];
		else if (isdigit(string[i]) != '\0')
			digitString[b++] = string[i];
	}
	alphaString1[a] = '\0';
	digitString[b] = '\0';

	printf("���ڵ��� %s\n", alphaString1);
	printf("���ڵ��� %s\n", digitString);

	for (i = 0; i < alphaString1[i] != '\0'; i++) {
		if (isupper(alphaString1[i] != '\0'))
			alphaString2[i] = tolower(alphaString1[i]);
		else
			alphaString2[i] = toupper(alphaString1[i]);
	}
	alphaString2[i] = '\0';

	strcat(alphaString1, digitString);
	strcpy(convertedString, alphaString1);

	printf("��ҹ��ڸ� �ٲ� ���ڵ��� %s\n", alphaString2);
	printf("���ڵ�� ���ڵ�� ��迭�� ���ڿ��� %s\n", convertedString);
}