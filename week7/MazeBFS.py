from collections import deque

# BFS 로 특정 노드를 방문하고 상하좌우로 연결된 모든 노드들도 방문
def bfs(x, y):
    # 큐 라이브러리 사용
    queue = deque()
    queue.append((x, y))

    # 큐가 빌 때까지
    while queue:
        x, y = queue.popleft();
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            # 벽이면 무시
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if graph[nx][ny] == 0:
                continue

            # 처음 방문하는 경우에만
            if graph[nx][ny] == 1:
                # 해당 위치 값을 전 위치의 +1 해줌 -> 최단거리 계산
                graph[nx][ny] = graph[x][y] + 1
                # 다음 갈 곳을 큐에 추가
                queue.append((nx, ny))

    return graph[n-1][m-1] # 마지막 반환 -> 최단거리가 저장돼있음

# start main
# n, m을 공 기준으로 구분하여 입력
n, m = map(int, input().split())

dx = [-1, 1, 0, 0];
dy = [0, 0, -1, 1];

# 2차원 리스트 미로 정보 입력
graph = []
for i in range(n):
    graph.append(list(map(int, input())))

print(bfs(0, 0))
# end main