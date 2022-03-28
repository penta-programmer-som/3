#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <string.h> 
int main(void)
{
	char string[50]; // 입력되는 문자열을 저장
	char alphaString1[50]; // 입력문자열에서 알파벳만 저장
	char alphaString2[50]; // 대소문자를 바꿈
	char digitString[50];
	char convertedString[50]; // 문자들과 숫자들로 재배열한 문자열

	printf("문자열을 입력하세요:");
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

	printf("문자들은 %s\n", alphaString1);
	printf("숫자들은 %s\n", digitString);

	strcpy(alphaString2, alphaString1);

	for (int i = 0; i < (int)strlen(alphaString2); i++) {
		if (alphaString2[i] == tolower(alphaString2[i]))
			alphaString2[i] = toupper(alphaString2[i]);
		else if (alphaString2[i] == toupper(alphaString2[i]))
			alphaString2[i] = tolower(alphaString2[i]);
	}

	strcat(alphaString1, digitString);
	strcpy(convertedString, alphaString1);

	printf("대소문자를 바꾼 문자들은 %s\n", alphaString2);
	printf("문자들과 숫자들로 재배열한 문자열은 %s\n", convertedString);
}