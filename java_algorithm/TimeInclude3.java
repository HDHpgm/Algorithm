import java.io.*;

public class TimeInclude3 {
    public static boolean check(int h, int m, int s) {
        if(h % 10 == 3 || m % 10 == 3 || m / 10 == 3 || s % 10 == 3 || s / 10 == 3)
            return true;

        return false;
    }
    // 완전탐색
    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int cnt = 0; // 3을 포함하는 시간 카운트
        int h = Integer.parseInt(br.readLine()); // 시간 입력
        br.close();
        for (int i = 0; i <= h; i++) { // h 시
            for (int j = 0; j < 60; j++) { // 분
                for (int k = 0; k < 60; k++) { // 초
                    if (check(i, j, k)) {
                        cnt++;
                    }
                }
            }
        }
        bw.write(cnt+"");
        bw.flush();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        solution();
    }
}
