#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int n, m;
int graph[1000][1000];

// DFS�� Ư�� ��带 �湮�ϰ� ����� ��� ���鵵 �湮
bool dfs(int x, int y) {

	// �־��� ������ ����� ��쿡�� ��� ����
	if (x <= -1 || x >= n || y <= -1 || y >= m) {
		return false;
	}

	// ���� ��带 ���� �湮���� �ʾҴٸ�
	if (graph[x][y] == 0) {
		// �ش� ��� �湮 ó��
		graph[x][y] = 1;

		// ��, ��, ��, ���� ��ġ�� ��� ȣ��
		dfs(x - 1, y); // ��
		dfs(x + 1, y); // ��
		dfs(x, y - 1); // ��
		dfs(x, y + 1); // ��
		return true;
	}
	return false;
}

int main() {
	// N, M�� ������ �������� �����Ͽ� �Է� �ޱ�
	cin >> n >> m;

	// 2���� ����Ʈ�� �� ���� �Է� �ޱ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	// ��� ���(��ġ)�� ���Ͽ� ����� ä���
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// ���� ��ġ���� DFS ����
			if (dfs(i, j)) {
				result += 1;
			}
		}
	}
	cout << result << '\n';
}