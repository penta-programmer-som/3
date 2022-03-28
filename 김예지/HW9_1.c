#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char string[50]; // 입력되는 문자열을 저장
	char alphaString1[50]; // 입력문자열에서 알파벳만 저장
	char alphaString2[50]; // 대소문자를 바꿈
	char digitString[50];
	char convertedString[50]; // 문자들과 숫자들로 재배열한 문자열 
	int i;
	int a = 0, b = 0;
	int len = 0;

	printf("문자열을 입력하세요 : "); // fgets 사용
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

	printf("문자들은 %s\n", alphaString1);
	printf("숫자들은 %s\n", digitString);

	for (i = 0; i < alphaString1[i] != '\0'; i++) {
		if (isupper(alphaString1[i] != '\0'))
			alphaString2[i] = tolower(alphaString1[i]);
		else
			alphaString2[i] = toupper(alphaString1[i]);
	}
	alphaString2[i] = '\0';

	strcat(alphaString1, digitString);
	strcpy(convertedString, alphaString1);

	printf("대소문자를 바꾼 문자들은 %s\n", alphaString2);
	printf("문자들과 숫자들로 재배열한 문자열은 %s\n", convertedString);
}