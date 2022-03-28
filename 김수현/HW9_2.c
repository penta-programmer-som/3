/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char numbers[14];
	printf("주민등록번호 입력<'-'포함>:");
	scanf("%s", numbers);
	int n;
	printf("당신은 19%c%c년도 생이군요\n", numbers[0], numbers[1]);
	if (numbers[7] == '2') {
		printf("여자분이시군요.");
		n = (int)numbers[0]-48;
		n *= 10;
		n +=(int)numbers[1]-48;
		n = 100 - n;
		n = 84 - n;
		printf("평균 수명 84를 더하면 20%d까지 산다고 계산됩니다.\n", n);
	}
	else if (numbers[7] == '1') {
		printf("남자분이시군요.");
		n = (int)numbers[0] - 48;
		n *= 10;
		n += (int)numbers[1] - 48;
		n = 100 - n;
		n = 77 - n;
		printf("평균 수명 77를 더하면 20%d까지 산다고 계산됩니다.", n);
	}
	else printf("다시 입력하세요");
}
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
#include<stdlib.h>
int main(void) {
	char str[14];
	char birthYear[5];
	int life = 0;
	int future = 0;
	printf("주민등록번호 입력<'-'포함> : ");
	fgets(str, sizeof(str), stdin);


	birthYear[0] = '41';
	birthYear[1] = '49';
	birthYear[2] = str[0];
	birthYear[3] = str[1];
	birthYear[4] = '\0';
	printf("당신은 %s 년도 생이군요\n", birthYear);

	life = atoi(birthYear);
	life = 2021 - life + 1;

	if (str[7] == 1) {
		printf("남자분이시군요\n");
		future = 2021 + 77 - life + 1;
		printf("평균수명 77을 더하면 %d까지 산다고 계산됩니다.", future);
	}

	else printf("여자분이시군요\n");
	{	future = 2021 + 84 - life + 1;
	printf("평균수명 84을 더하면 %d까지 산다고 계산됩니다.", future);
	}
}