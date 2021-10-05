#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
char moveTypes[4] = { 'L', 'R', 'U', 'D' };

int n;
char str[100];
char plans[100];
int x = 1, y = 1;

void main() {
	scanf("%d\n", &n); // n X n 입력받고 개행안하면 아래 문자열 안받아짐 (버그인듯)
	int cnt = 0, count = 0;
	scanf("%[^\n]s", str); // 공백포함 문자열 모두 읽어 저장


	while (1) {
		if (str[count] == '\n' || '\0') break; // 문자열 끝이면 break;
		if (str[count] == ' ') {
			count++;
			continue;
		}

		plans[cnt++] = str[count++];
		char plan = plans[cnt];

		// 이동 후 좌표 구하기
		int nx = 0, ny = 0;
		for (int j = 0; j < 4; j++)
		{
			if (plan == moveTypes[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
				break;
			}
		}
		// 공간 벗어나면 무시
		if (nx < 1 || ny < 1 || nx > n || ny > n) continue;

		x = nx;
		y = ny;

	}
	printf("%d %d\n", x, y);

}