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

	printf("주민등록번호 입력('-' 포함) : ");
	fgets(number, sizeof(number), stdin);

	strncpy(year, number, 2);
	year[2] = '\0';
	printf("당신은 19%s년도 생이군요\n", year);
	age = atoi(year) + 1900;

	if (number[7] == '1') {
		printf("남자분이시군요.\n");
		printf("평균 수명 77을 더하면 %d까지 산다고 계산됩니다.\n", age + 77);
	}
	else if (number[7] == '2') {
		printf("여자분이시군요.\n");
		printf("평균 수명 84를 더하면 %d까지 산다고 계산됩니다.\n", age + 84);
	}

}