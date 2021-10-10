package com.algorithm;

import java.util.Scanner;

public class ICE {
    public static int N,M;
    public static int [][] graph = new int[1000][1000];

    // DFS로 특정 노드를 방문하고 상하좌우로 연결된 모든 노드들도 방문
    public static boolean dfs(int x, int y){

        // 주어진 범위를 벗어나는 경우에는 종료
        if(x <= -1 || x>= N || y <= -1 || y >= M)
            return false;

        //현재 노드를 아직 방문하지 않았다면
        if(graph[x][y] == 0){
            //해당 노드 방문 처리
            graph[x][y] = 1;

            // 상, 하, 좌, 우의 위치들 재귀 호출
            dfs(x - 1, y); // 상
            dfs(x + 1, y); // 하
            dfs(x, y - 1); // 좌
            dfs(x, y + 1); // 우
            return true;
        }
        return false;
    }

    // 스캐너로 하면 느리다 -> 버퍼로 해야 빠름
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // N, M 입력
        N = scanner.nextInt();
        M = scanner.nextInt();

        // 버퍼 비워주기 -> 다음 입력 때 오류 방지
        scanner.nextLine();

        // 2차원 리스트 정보 입력
        for (int i = 0; i < N; i++){
            String str = scanner.nextLine();
            for (int j = 0; j < M; j++){
                // 문자를 숫자로 변환해서 넣어줌
                graph[i][j] = str.charAt(j) - '0';
            }
        }
        scanner.close();

        int result = 0;

        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
        //현재 위치에서 DFS 수행
                if(dfs(i, j)) {
                    result += 1;
                }
            }
        }
        System.out.println(result);
    }
}
