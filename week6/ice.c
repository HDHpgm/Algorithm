#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int n, m;
int graph[1000][1000];

bool dfs(int x, int y) {
	// 주어진 범위를 벗어나는 경우에는 즉시 종료
	if (x <= -1 || x >= n || y <= -1 || y >= m) {
		return false;
	}

	// 현재 노드를 아직 방문하지 않았다면
	if (graph[x][y] == 0) {

		// 해당 노드 방문 처리
		graph[x][y] = 1;

		// 상, 하, 좌, 우의 위치들 재귀 호출
		dfs(x - 1, y); // 상
		dfs(x + 1, y); // 하
		dfs(x, y - 1); // 좌
		dfs(x, y + 1); // 우
		return true;
	}
	return false;
}

void main() {
	// N, M을 공백을 기준으로 구분하여 입력 받기
	scanf("%d %d", &n, &m);

	// 2차원 리스트의 맵 정보 입력 받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 현재 위치에서 DFS 수행
			if (dfs(i, j)) {
				result += 1;
			}
		}
	}

	printf("%d\n", result);
}