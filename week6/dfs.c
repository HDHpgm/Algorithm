#include <stdio.h>
#include <stdbool.h>

bool visited[9];

int graph[9][3] = { {NULL}, {2,3,8}, {1,7}, {1,4,5}, {3,5}, {3,4}, {7}, {2,6,8}, {1,7} };


void dfs(int v) {
	// 현재 노드 방문처리
	visited[v] = true;

	// 방문 노드 하나씩 출력
	printf("%d ", v);

	// 연결된 노드 방문을 위해 재귀 호출
	for (int i = 0; i < 3 && graph[v][i] != 0; i++) {
		if (!visited[graph[v][i]]) {
			dfs(graph[v][i]);
		}
	}
}

void main() {
	dfs(1);
}