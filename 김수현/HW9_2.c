/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char numbers[14];
	printf("�ֹε�Ϲ�ȣ �Է�<'-'����>:");
	scanf("%s", numbers);
	int n;
	printf("����� 19%c%c�⵵ ���̱���\n", numbers[0], numbers[1]);
	if (numbers[7] == '2') {
		printf("���ں��̽ñ���.");
		n = (int)numbers[0]-48;
		n *= 10;
		n +=(int)numbers[1]-48;
		n = 100 - n;
		n = 84 - n;
		printf("��� ���� 84�� ���ϸ� 20%d���� ��ٰ� ���˴ϴ�.\n", n);
	}
	else if (numbers[7] == '1') {
		printf("���ں��̽ñ���.");
		n = (int)numbers[0] - 48;
		n *= 10;
		n += (int)numbers[1] - 48;
		n = 100 - n;
		n = 77 - n;
		printf("��� ���� 77�� ���ϸ� 20%d���� ��ٰ� ���˴ϴ�.", n);
	}
	else printf("�ٽ� �Է��ϼ���");
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
	printf("�ֹε�Ϲ�ȣ �Է�<'-'����> : ");
	fgets(str, sizeof(str), stdin);


	birthYear[0] = '41';
	birthYear[1] = '49';
	birthYear[2] = str[0];
	birthYear[3] = str[1];
	birthYear[4] = '\0';
	printf("����� %s �⵵ ���̱���\n", birthYear);

	life = atoi(birthYear);
	life = 2021 - life + 1;

	if (str[7] == 1) {
		printf("���ں��̽ñ���\n");
		future = 2021 + 77 - life + 1;
		printf("��ռ��� 77�� ���ϸ� %d���� ��ٰ� ���˴ϴ�.", future);
	}

	else printf("���ں��̽ñ���\n");
	{	future = 2021 + 84 - life + 1;
	printf("��ռ��� 84�� ���ϸ� %d���� ��ٰ� ���˴ϴ�.", future);
	}
}