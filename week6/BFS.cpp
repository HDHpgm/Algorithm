#include <bits/stdc++.h>

using namespace std;
bool visited[9];

int graph[9][3] = { {}, {2,3,8}, {1,7}, {1,4,5}, {3,5}, {3,4}, {7}, {2,6,8}, {1,7} };


void bfs(int start) {
	// queue 선언
	queue<int> queue;
	// 시작 값 추가
	queue.push(start);

	// 현재 노드 방문처리
	visited[start] = true;

	// 큐가 빌 때 까지
	while (!queue.empty()) {
		int v = queue.front(); // 가장 먼저 나갈 값 저장
		queue.pop(); // 가장 먼저 나갈 값 삭제

		// 방문 노드 하나씩 출력
		cout << v << ' ';

		// 인접 노드를 모두 방문하기 위해서
		for (int node : graph[v]) { 
			if (!visited[node]) { // 방문하지 않았다면
				queue.push(node);
				visited[node] = true;
			}
		}
	}
}

void main() {
	// 배열 크기를 3으로 인식해서 돌기 때문에 0번인덱스를 true로 만들어 3번째 요소가 0이 나오면 방문하지 않도록
	visited[0] = true; 
	bfs(1);
}