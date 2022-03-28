#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	char string[50];//입력되는 문자열을 저장
	char alphaString1[50];//입력문자열에서 알파벳만 저장
	char alphaString2[50];//대소문자를 바꿈
	char digitString[50];
	char convertedString[50];//문자들과 숫자들로 재배열한 문자열
	int i = 0;
	int j = 0;
	int k = 0;

	printf("문자열을 입력하세요:");
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

	printf("문자들은 %s\n", alphaString1);
	printf("숫자들은 %s\n", digitString);
}