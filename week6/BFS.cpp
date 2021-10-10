#include <bits/stdc++.h>

using namespace std;
bool visited[9];

int graph[9][3] = { {}, {2,3,8}, {1,7}, {1,4,5}, {3,5}, {3,4}, {7}, {2,6,8}, {1,7} };


void bfs(int start) {
	// queue ����
	queue<int> queue;
	// ���� �� �߰�
	queue.push(start);

	// ���� ��� �湮ó��
	visited[start] = true;

	// ť�� �� �� ����
	while (!queue.empty()) {
		int v = queue.front(); // ���� ���� ���� �� ����
		queue.pop(); // ���� ���� ���� �� ����

		// �湮 ��� �ϳ��� ���
		cout << v << ' ';

		// ���� ��带 ��� �湮�ϱ� ���ؼ�
		for (int node : graph[v]) { 
			if (!visited[node]) { // �湮���� �ʾҴٸ�
				queue.push(node);
				visited[node] = true;
			}
		}
	}
}

void main() {
	// �迭 ũ�⸦ 3���� �ν��ؼ� ���� ������ 0���ε����� true�� ����� 3��° ��Ұ� 0�� ������ �湮���� �ʵ���
	visited[0] = true; 
	bfs(1);
}