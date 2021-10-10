#include <bits/stdc++.h>

using namespace std;
bool visited[9];

int graph[9][3] = { {}, {2,3,8}, {1,7}, {1,4,5}, {3,5}, {3,4}, {7}, {2,6,8}, {1,7} };

void dfs(int v) {
	// ���� ��� �湮ó��
	visited[v] = true;

	// �湮 ��� �ϳ��� ���
	cout << v << ' ';

	// ����� ��� �湮�� ���� ��� ȣ��
	for (int node : graph[v]) {
		if (!visited[node]) {
			dfs(node);
		}
	}
}

void main() {
	// �迭 ũ�⸦ 3���� �ν��ؼ� ���� ������ 0���ε����� true�� ����� 3��° ��Ұ� 0�� ������ �湮���� �ʵ���
	visited[0] = true;
	dfs(1);
}