#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 나이트가 이동할 수 있는 8가지 방향 정의
int dx[] = { -2, -2, 2, 2, -1, -1, 1, 1 };
int dy[] = { -1, 1, -1, 1, -2, 2, -2, 2 };
char knight[3];
void main() {
	// 현재 나이트의 위치 입력받기
	scanf("%s", knight);
	int row = knight[1] - '0';
	int column = knight[0] - 'a' + 1;
	int result = 0;

	// 8가지 방향에 대하여 각 위치로 이동이 가능한지 확인
	for (int i = 0; i < 8; i++) {
		// 이동하고자 하는 위치 확인
		int nRow = row + dx[i];
		int nCol = column + dy[i];

		// 해당 위치로 이동이 가능하다면 카운트 증가
		if (nRow >= 1 && nRow <= 8 && nCol >= 1 && nCol <= 8)
			result++;
	}
	printf("%d\n", result);

}