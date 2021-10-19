#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

// �����¿�� �̵��Ҷ� ���ϴ� x,y ��
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m;
int graph[200][200];

int bfs(int x, int y) {
	// queue ���̺귯�� ���
	queue<pair<int, int>> queue; 
	queue.push({ x, y }); // ���� ��ǥ �� push

	// ť�� �� ������ �ݺ��ϱ�
	while (!queue.empty()) {
		int x = queue.front().first;
		int y = queue.front().second;
		queue.pop(); // ť���� ����

		// �����¿� 4���� ���������� ��ġ Ȯ��
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// ���̸� ��������
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (graph[nx][ny] == 0)
				continue;

			// ó�� �湮�ϴ� ��쿡��
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[x][y] + 1;
				queue.push({ nx, ny });
			}
		}
	}
	// ������ ��ȯ -> �ִܰŸ��� ���������
	return graph[n - 1][m - 1];
}

int main(void) {
	cin >> n >> m; // N x M ũ��

	// �̷� ���� �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	cout << bfs(0, 0);
	return 0;
}