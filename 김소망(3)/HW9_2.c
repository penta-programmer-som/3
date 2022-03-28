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

	printf("주민등록번호 입력<'-'포함>:");
	fgets(id, sizeof(id), stdin);
	id[6] = '-';
	printf("당신은 19%c%c년도 생이시군요\n", id[0], id[1]);

	for (i = 0; i < 1; i++)
		n1 = id[i];
	for (i = 1; i < 2; i++)
		n2 = id[i];

	year = atoi(&n1) * 10 + atoi(&n2) + 1900;

	if (id[7] == '1') {
		printf("남자분이시군요.\n");
		printf("평균수명 77를 더하면 %d까지 산다고 계산됩니다\n", year + 77);
	}
	else if (id[7] == '2') {
		printf("여자분이시군요.\n");
		printf("평균수명 84를 더하면 %d까지 산다고 계산됩니다\n", year + 84);
	}
}