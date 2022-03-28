#define _CRT_SECURE_NO_WARNINGS
#define MAX_VIDEO 100
#define MAX_CUST 200
#define MAX_CHAR 100 // ���ڿ��� max ���� 
#include <stdio.h>
#include <string.h>

typedef struct {  // ������ : ���� �����ϰ� �ִ� video ���� 
	char title[MAX_CHAR];
	int qty; // ����
}VideoInfo;

typedef struct { // ������� : �����ذ� (�� id�� video id)���� ���� 
	int custId; // �� id : 1, 2, 3
	char title[MAX_CHAR]; // Video ���� 
}RentInfo;

void printAllVideo(VideoInfo videoList[], int videoCount)
{
	// ���� video ���
	printf("Video ����\t����\n");
	printf("------------------------\n");
	for (int i = 0; i < videoCount; i++)
		printf("%s\t%d\n", videoList[i].title, videoList[i].qty);
}

void purchaseVideo(VideoInfo videoList[], int* videoCountPtr, char* title, int qty)
{
	//  Video ���� 
	strcpy(videoList[*videoCountPtr].title, title);
	videoList[*videoCountPtr].qty = qty;
	(*videoCountPtr)++;
}

VideoInfo *searchVideoByTitle(VideoInfo videoList[], int videoCount, char* title)
{
	// title�� video ã�� 
	int i;
	for (i = 0; i < videoCount; i++) {
		if (strcmp(title, videoList[i].title) == 0) {
			return title;
			break;
		}
	}

	if (i == videoCount)
		return NULL;
}

void rentVideo(VideoInfo videolist[], int videoCount, RentInfo rentList[], int* rentCount, char* title, int id)
{
	int i;

	for (i = 0; i < videoCount; i++) {
		if (searchVideoByTitle(videolist, videoCount, title) == title) {
			(*rentList).custId = id;
			strcpy((*rentList).title, title);
			(*rentCount)++;
			rentList++;
			(*videolist).qty--;
			break;
		}
		videolist++;

	}
}

void printAllRent(RentInfo rentList[], int rentCount)
{
	int i;
	for (i = 0; i < rentCount - 2; i++)
		rentList--;

	printf("�� id   Video ����\n----------------\n");
	for (i = 0; i < rentCount; i++) {
		printf("%d\t%s\n", (*rentList).custId, (*rentList).title);
		rentList++;
	}
}

int main(void)
{
	int videoCount = 5;
	VideoInfo videoList[MAX_VIDEO] = { {"BeforeSunrise",1},{"BeforeSunset",3},
				{"BeforeMidnight",5},{"Casablanca",7},{"EdgeOfTomorrow",9} };
	int rentCount = 0; // ���� ���� �Ǽ��� 0�� 
	RentInfo rentList[MAX_CHAR];

	int choice;
	int indexSearched;
	char title[MAX_CHAR];
	int custId, qty;

	printf("1(ALL Video ���), 2(����), 3(�˻�), 4(�뿩), 5(All �뿩���� ���), 6(����) : ");
	scanf("%d", &choice);
	while (choice != 6) {
		switch (choice) {
		case 1: // ���� video ��� 
			printAllVideo(videoList, videoCount);
			break;

		case 2: // video ���� 
			printf("Enter video ���� : ");
			scanf("%s", title);
			printf("Enter video ���� : ");
			scanf("%d", &qty);
			purchaseVideo(videoList, &videoCount, title, qty);
			break;

		case 3:// title�� video ã�� 
			printf("Enter video ���� : ");
			scanf("%s", title);
			if ((searchVideoByTitle(videoList, videoCount, title)) == title)
				printf("�뿩�����մϴ�.\n");
			else
				printf("�׷� ������ �����ϴ�.\n");
			break;

		case 4:// video �뿩  
			printf("Enter video ���� : ");
			scanf("%s", title);
			printf("Enter �� Id : ");
			scanf("%d", &custId);
			rentVideo(videoList, videoCount, rentList, &rentCount, title, custId);
			break;

		case 5: // �뿩 ������ ��� 
			printAllRent(rentList, rentCount);
			break;
		}
		printf("1(ALL Video ���), 2(����), 3(�˻�), 4(�뿩), 5(All �뿩���� ���), 6(����) : ");
		scanf("%d", &choice);
	}
}