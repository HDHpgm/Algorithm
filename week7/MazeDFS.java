package com.algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class MazeDFS {
    // 상하좌우로 이동할때 변하는 x,y 값
    public static final int[] dx = {-1, 1, 0, 0};
    public static final int[] dy = {0, 0, -1, 1};

    public static int n;
    public static int m;
    public static int[][] graph;

    // DFS 로 특정 노드를 방문하고 상하좌우로 연결된 모든 노드들도 방문
    public static int dfs(int x, int y) {

        Stack<Node> stack = new Stack<Node>();
        Node node = new Node(x, y);
        stack.push(node);

        while (!stack.empty()) {
            node = stack.pop();
            x = node.getX();
            y = node.getY();

            // 상하좌우 4방향 모두 방문하기 위해
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // 벽이면 넘어감
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (graph[nx][ny] == 0) continue;

                // 처음 방문하는 경우에만
                if (graph[nx][ny] == 1) {
                    graph[nx][ny] = graph[x][y] + 1; // 해당 위치 값을 전 위치의 +1 해줌 -> 최단거리 계산
                    stack.push(new Node(nx, ny)); // 다음 갈 곳을 큐에 추가
                }
                // 처음방문이 아니면 전에 지나간것 보다 작아야 수행
                else if (graph[nx][ny] > graph[x][y] + 1) {
                    graph[nx][ny] = graph[x][y] + 1; // 해당 위치 값을 전 위치의 +1 해줌 -> 최단거리 계산
                    stack.push(new Node(nx, ny)); // 다음 갈 곳을 큐에 추가
                }
            }
        }

        return graph[n - 1][m - 1]; // 마지막 반환 -> 최단거리가 저장돼있음

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // N x M 크기의 미로 입력
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        // graph(미로) 정보 입력받기
        graph = new int[n][m];
        for (int i = 0; i < n; i++) {
            String mazeStr = br.readLine();
            for (int j = 0; j < m; j++) {
                graph[i][j] = mazeStr.charAt(j) - '0';
            }
        }
        br.close(); // 입력 종료
        System.out.println(dfs(0, 0));
    }

    static class Node {
        final private int x;
        final private int y;

        Node(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }
    }

}
