#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	char string[50];//�ԷµǴ� ���ڿ��� ����
	char alphaString1[50];//�Է¹��ڿ����� ���ĺ��� ����
	char alphaString2[50];//��ҹ��ڸ� �ٲ�
	char digitString[50];
	char convertedString[50];//���ڵ�� ���ڵ�� ��迭�� ���ڿ�
	int i = 0;
	int j = 0;
	int k = 0;

	printf("���ڿ��� �Է��ϼ���:");
	fgets(string, sizeof(string), stdin);

	while (string[i] != '\0')
	{
		if (isalpha(string[i]))
			alphaString1[j++] = string[i++];
		else if (isdigit(string[i]))
			digitString[k++] = string[i++];
	}
	alphaString1[j] = '\0';
	digitString[k] = '\0';

	printf("���ڵ��� %s\n", alphaString1);
	printf("���ڵ��� %s\n", digitString);
}