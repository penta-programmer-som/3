#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <string.h> 
int main(void)
{
	char string[50]; // �ԷµǴ� ���ڿ��� ����
	char alphaString1[50]; // �Է¹��ڿ����� ���ĺ��� ����
	char alphaString2[50]; // ��ҹ��ڸ� �ٲ�
	char digitString[50];
	char convertedString[50]; // ���ڵ�� ���ڵ�� ��迭�� ���ڿ�

	printf("���ڿ��� �Է��ϼ���:");
	fgets(string, sizeof(string), stdin);

	int j = 0, k = 0;
	for (int i = 0; string[i] != '\0'; i++) {
		//strcpy(alphaString1, isalpha(string[i]));
		if (isalpha(string[i]))
			alphaString1[j++] = string[i];

		else if (isdigit(string[i]))
			digitString[k++] = string[i];
	}
	alphaString1[j] = '\0';
	digitString[k] = '\0';

	printf("���ڵ��� %s\n", alphaString1);
	printf("���ڵ��� %s\n", digitString);

	strcpy(alphaString2, alphaString1);

	for (int i = 0; i < (int)strlen(alphaString2); i++) {
		if (alphaString2[i] == tolower(alphaString2[i]))
			alphaString2[i] = toupper(alphaString2[i]);
		else if (alphaString2[i] == toupper(alphaString2[i]))
			alphaString2[i] = tolower(alphaString2[i]);
	}

	strcat(alphaString1, digitString);
	strcpy(convertedString, alphaString1);

	printf("��ҹ��ڸ� �ٲ� ���ڵ��� %s\n", alphaString2);
	printf("���ڵ�� ���ڵ�� ��迭�� ���ڿ��� %s\n", convertedString);
}