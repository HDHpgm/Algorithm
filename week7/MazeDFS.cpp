#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

// �����¿�� �̵��Ҷ� ���ϴ� x,y ��
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, m;
int graph[200][200];

int dfs(int x, int y) {
	// stack ���̺귯�� ���
	stack<pair<int, int>> stack;
	stack.push({ x, y }); // ���� ��ǥ �� push

	// ������ �� ������ �ݺ��ϱ�
	while (!stack.empty()) {
		int x = stack.top().first;
		int y = stack.top().second;
		stack.pop(); // ť���� ����

		// �����¿� 4���� ���������� ��ġ Ȯ��
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// ���̸� �������� / dfs�� �ϸ� �ִܰŸ��� �ƴϿ��� �������� �����̴� ��찡 ����
			// �����ذ� -> ������ 1�� ������ �񱳸� �ؼ� ���� ���� �� ũ�� continue || graph[nx][ny] <= graph[x][y]
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (graph[nx][ny] == 0)
				continue;

			// ó�� �湮�ϴ� ��쿡��
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[x][y] + 1;
				stack.push({ nx, ny });
			}
			// ó���湮�� �ƴϸ� ���� �������� ���� �۾ƾ� ����
			else if (graph[nx][ny] > graph[x][y] + 1) {
				graph[nx][ny] = graph[x][y] + 1;
				stack.push({ nx, ny });
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

	cout << dfs(0, 0);
	return 0;
}