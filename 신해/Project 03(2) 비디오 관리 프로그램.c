#define	_CRT_SECURE_NO_WARNINGS
#define MAX_VIDEO 100
#define MAX_CUST 200
#define MAX_CHAR 100
#include <stdio.h>
#include <string.h>

typedef struct VideoInfo {
	char title[MAX_CHAR];
	int qty;
	int point;
}VideoInfo;

typedef struct RentInfo {
	int custId;
	char title[MAX_CHAR];
}RentInfo;

void printAllVideo(VideoInfo videoList[], int VideoCount)
{
	int i;
	printf("Video제목\t수량\n");
	printf("---------------------\n");
	for (i = 0; i < VideoCount; i++)
		printf("%s\t%d\n", videoList[i].title, videoList[i].qty);
}

void purchaseVode(VideoInfo videoList[], int* videoCountPtr, char* title, int qty)
{
	*videoCountPtr += 1;
	strcpy(videoList[*videoCountPtr - 1].title, title);
	videoList[*videoCountPtr - 1].qty = qty;

}

void rentVideo(VideoInfo searchVideoByTitle, VideoInfo videoList[], int videoCount, RentInfo rentList[], int* rentCount, char* title, int custId)
{

	rentCount += 1;
	rentList[*rentCount - 1].custId = custId;
	strcpy(rentList[*rentCount - 1].title, title);

}

void printAllRent(RentInfo rentList[], int rentCount)
{
	printf("고객id\tVideo제목\n");
	printf("---------------------\n");
	printf("%d\t%s", rentList[rentCount - 1].custId, rentList[rentCount - 1].title);
}

VideoInfo* searchVideoByTitle(VideoInfo videoList[], int videoCount, char* title)
{
	VideoInfo search;

	int i, j;
	for (i = 0; i < videoCount; i++) {
		if (strcmp(videoList[i].title, title) == 0) {
			for (j = 0; videoList[i].title[j] != '\0'; j++) {
				if (videoList[i].title[j] != title[j])
				{
					title = '\0';
					return title;
				}
			}
			title[j] = '\0';

			{
				title = i;
				return title;
			}
		}
		if (i == videoCount - 1 && strcmp(videoList[i].title, title) != 0)
		{
			title = '\0';
			return title;
		}
	}
}

int main(void)
{
	int videoCount = 5;
	VideoInfo videoList[MAX_VIDEO] = { {"BeforeSunrise",1},{"BeforeSunset",3},{"BeforeMidnight",5},{"Casablanca",7},{"EdgeOfTomorrow",9} };

	int rentCount = 0;
	RentInfo rentList[MAX_CUST];

	int choice;
	int indexSearched;
	char title[MAX_CHAR];
	int custId, qty;

	printf("1(All Video 출력), 2(구입), 3(검색), 4(대여), 5(ALL 대여정보 출력), 6(종료): ");
	scanf("%d", &choice);
	while (choice != 6) {
		switch (choice) {
		case 1: printAllVideo(videoList, videoCount); break;
		case 2:
			printf("Enter video 제목: ");
			scanf("%s", title);
			printf("Enter video 수량: ");
			scanf("%d", &qty);
			purchaseVode(videoList, &videoCount, title, qty); break;
		case 3:
			printf("Enter video 제목: ");
			scanf("%s", title);

			if (searchVideoByTitle(videoList, videoCount, title) == '\0')
				printf("그런 비디오는 없습니다.\n");
			else
				printf("대여 가능합니다.\n");
			break;
			
		case 5:
			printAllRent(rentList, rentCount); break;
		}
		printf("1(All Video 출력), 2(구입), 3(검색), 4(대여), 5(ALL 대여정보 출력), 6(종료): ");
		scanf("%d", &choice);
	}

}