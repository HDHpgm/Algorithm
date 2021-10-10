#include <bits/stdc++.h>

using namespace std;
bool visited[9];

int graph[9][3] = { {}, {2,3,8}, {1,7}, {1,4,5}, {3,5}, {3,4}, {7}, {2,6,8}, {1,7} };

void dfs(int v) {
	// 현재 노드 방문처리
	visited[v] = true;

	// 방문 노드 하나씩 출력
	cout << v << ' ';

	// 연결된 노드 방문을 위해 재귀 호출
	for (int node : graph[v]) {
		if (!visited[node]) {
			dfs(node);
		}
	}
}

void main() {
	// 배열 크기를 3으로 인식해서 돌기 때문에 0번인덱스를 true로 만들어 3번째 요소가 0이 나오면 방문하지 않도록
	visited[0] = true;
	dfs(1);
}