# dfs 함수
def dfs(graph, v, visited):
    # 현재 노드 방문처리
    visited[v] = True
    # 방문 노드 하나씩 출력
    print(v, end = ' ')

    # 연결된 노드 방문을 위해 재귀 호출
    for node in graph[v]:
        if not visited[node]: # 방문하지 않았다면
            dfs(graph, node, visited)


# 각 노드가 연결된 정보를 표현 (2차원 리스트)
graph = [
    [], # 0번은 비워두고 시작
    [2, 3, 8],
    [1, 7],
    [1, 4, 5],
    [3, 5],
    [3, 4],
    [7],
    [2, 6, 8],
    [1, 7]
]

# 각 노드가 방문된 정보를 표현 (1차원 리스트)
visited = [False] * 9

dfs(graph, 1, visited)
