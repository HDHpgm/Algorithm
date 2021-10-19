#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

// 상하좌우로 이동할때 변하는 x,y 값
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m;
int graph[200][200];

int dfs(int x, int y) {
	// stack 라이브러리 사용
	stack<pair<int, int>> stack;
	stack.push({ x, y }); // 현재 좌표 값 push

	// 스택이 빌 때까지 반복하기
	while (!stack.empty()) {
		int x = stack.top().first;
		int y = stack.top().second;
		stack.pop(); // 큐에서 제거

		// 상하좌우 4가지 방향으로의 위치 확인
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 벽이면 다음으로 / dfs로 하면 최단거리가 아니여도 마지막에 덮쓰이는 경우가 있음
			// 문제해결 -> 마지막 1로 나갈때 비교를 해서 덮을 값이 더 크면 continue || graph[nx][ny] <= graph[x][y]
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (graph[nx][ny] == 0)
				continue;

			// 처음 방문하는 경우에만
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[x][y] + 1;
				stack.push({ nx, ny });
			}
			// 처음방문이 아니면 전에 지나간것 보다 작아야 수행
			else if (graph[nx][ny] > graph[x][y] + 1) {
				graph[nx][ny] = graph[x][y] + 1;
				stack.push({ nx, ny });
			}
		}
	}
	// 마지막 반환 -> 최단거리가 저장돼있음
	return graph[n - 1][m - 1];
}

int main(void) {
	cin >> n >> m; // N x M 크기

	// 미로 정보 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	cout << dfs(0, 0);
	return 0;
}