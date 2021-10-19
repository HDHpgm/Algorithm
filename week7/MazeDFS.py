# DFS 소스코드 구현
def dfs(x, y):
    stack = []
    stack.append((x, y))

    while stack:
        x, y = stack.pop()
        # 현재 위치에서 4가지 방향으로의 위치 확인
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # 미로 찾기 공간을 벗어난 경우 무시
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            # 벽인 경우 무시
            if graph[nx][ny] == 0:
                continue

            # 처음 방문한 경우 수행
            if graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] + 1
                stack.append((nx, ny))
            # 방문한 적이 있다면 저장된 값보다 작아야 수행 -> 최단거리 찾아야해서
            elif graph[nx][ny] > graph[x][y] + 1:
                graph[nx][ny] = graph[x][y] + 1
                stack.append((nx, ny))

    return graph[n - 1][m - 1]


# N x M 입력받기
n, m = map(int, input().split())

# 2차원 리스트의 맵 정보 입력 받기
graph = []
for i in range(n):
    graph.append(list(map(int, input())))

# 이동할 네 가지 방향 정의 (상, 하, 좌, 우)
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
# DFS를 수행한 결과 출력
print(dfs(0, 0))