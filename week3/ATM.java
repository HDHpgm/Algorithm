import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ATM {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int temp = 0;
        int result = 0;
        int n = Integer.parseInt(br.readLine()); // 사람 수
        int[] time = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine()); // 3 1 4 3 2 처럼 입력
        for (int i = 0; i < time.length; i++) {
            time[i] = Integer.parseInt(st.nextToken()); // 한개씩 잘라서 넣어줌
        }
        br.close();
        Arrays.sort(time); // 오름차순 정렬 -> 짧은 것부터 해결해야 최대한 빠름
        for (int j = 0; j < time.length; j++) {
            temp += time[j]; // 각 사람마다 ATM 이용하는 시간 누적
            result += temp;  // 앞의 사람 기다리는데 걸리는 시간까지 모두 누적
        }
        bw.write(result+"\n"); // 결과 출력
        bw.flush();
        bw.close();
    }
}
