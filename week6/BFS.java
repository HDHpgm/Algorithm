package com.algorithm;

import java.util.LinkedList;
import java.util.Queue;

public class BFS {
    public static boolean[] visited = new boolean[9];
    static int[][] graph = {{}, {2,3,8}, {1,7}, {1,4,5}, {3,5}, {3,4}, {7}, {2,6,8}, {1,7}};

    public static void bfs(int start) {
        // queue 선언 linkedlist로 선언해야함
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.offer(start); // 시작노드 추가

        // 현재 노드 방문처리
        visited[start] = true;


        // 큐가 빌 때 까지
        while(!queue.isEmpty()) {
            int v = queue.poll(); // 값 꺼내기

            // 방문 노드 하나씩 출력
            System.out.print(v + " ");

            for (int node : graph[v]) { // 인접 노드를 모두 방문하기 위해서
                if (!visited[node]) { // 방문 안했다면
                    queue.offer(node); // 추가
                    visited[node] = true; // 방문 처리
                }
            }
        }
    }

    public static void main(String[] args) {
        bfs(1);
    }
}
