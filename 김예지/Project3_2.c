#define _CRT_SECURE_NO_WARNINGS
#define MAX_VIDEO 100
#define MAX_CUST 200
#define MAX_CHAR 100 // 문자열의 max 문자 
#include <stdio.h>
#include <string.h>

typedef struct {  // 재고대장 : 현재 보유하고 있는 video 저장 
	char title[MAX_CHAR];
	int qty; // 수량
}VideoInfo;

typedef struct { // 대출대장 : 대출해간 (고객 id와 video id)들을 저장 
	int custId; // 고객 id : 1, 2, 3
	char title[MAX_CHAR]; // Video 제목 
}RentInfo;

void printAllVideo(VideoInfo videoList[], int videoCount)
{
	// 보유 video 출력
	printf("Video 제목\t수량\n");
	printf("------------------------\n");
	for (int i = 0; i < videoCount; i++)
		printf("%s\t%d\n", videoList[i].title, videoList[i].qty);
}

void purchaseVideo(VideoInfo videoList[], int* videoCountPtr, char* title, int qty)
{
	//  Video 구입 
	strcpy(videoList[*videoCountPtr].title, title);
	videoList[*videoCountPtr].qty = qty;
	(*videoCountPtr)++;
}

VideoInfo *searchVideoByTitle(VideoInfo videoList[], int videoCount, char* title)
{
	// title로 video 찾기 
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

	printf("고객 id   Video 제목\n----------------\n");
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
	int rentCount = 0; // 현재 대출 건수는 0임 
	RentInfo rentList[MAX_CHAR];

	int choice;
	int indexSearched;
	char title[MAX_CHAR];
	int custId, qty;

	printf("1(ALL Video 출력), 2(구입), 3(검색), 4(대여), 5(All 대여정보 출력), 6(종료) : ");
	scanf("%d", &choice);
	while (choice != 6) {
		switch (choice) {
		case 1: // 보유 video 출력 
			printAllVideo(videoList, videoCount);
			break;

		case 2: // video 구입 
			printf("Enter video 제목 : ");
			scanf("%s", title);
			printf("Enter video 수량 : ");
			scanf("%d", &qty);
			purchaseVideo(videoList, &videoCount, title, qty);
			break;

		case 3:// title로 video 찾기 
			printf("Enter video 제목 : ");
			scanf("%s", title);
			if ((searchVideoByTitle(videoList, videoCount, title)) == title)
				printf("대여가능합니다.\n");
			else
				printf("그런 비디오는 없습니다.\n");
			break;

		case 4:// video 대여  
			printf("Enter video 제목 : ");
			scanf("%s", title);
			printf("Enter 고객 Id : ");
			scanf("%d", &custId);
			rentVideo(videoList, videoCount, rentList, &rentCount, title, custId);
			break;

		case 5: // 대여 정보들 출력 
			printAllRent(rentList, rentCount);
			break;
		}
		printf("1(ALL Video 출력), 2(구입), 3(검색), 4(대여), 5(All 대여정보 출력), 6(종료) : ");
		scanf("%d", &choice);
	}
}