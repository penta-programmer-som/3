#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	char s[50];
	char birth[50] = { 0 };
	char f[] = "여자";
	char m[] = "남자";
	char* token1;
	char* token2;
	char delimiters[] = "-";
	char id[50] = { 0 };
	int year;

	printf("주민등록번호 입력<'-'포함>:");
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

	printf("당신은 %s년도 생이시군요\n", birth);

	year = atoi(birth);
	if (id[0] == '2' || id[0] == '4') {
		printf("%s분이시군요\n", f);
		printf("평균 수명 84을 더하면 %d년까지 산다고 계산됩니다.", year + 84);
	}
	else if (id[0] == '1' || id[0] == '3') {
		printf("%s분이시군요\n", m);
		printf("평균 수명 77을 더하면 %d년까지 산다고 계산됩니다.", year + 77);
	}
}