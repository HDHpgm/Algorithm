import java.io.*;
import java.util.StringTokenizer;

public class Becomes1 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int count = 0;

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        br.close();

        while (true) {
            int target = (n / k) * k;
            count = count + (n - target);
            n = target;

            if (n == 0) break; // if(n < k) 랑 같은 역할

            n = n / k;
            count++;
        }
        // n이 1이 될 때까지의 최소횟수(count) -> 구한횟수는 n이 0일 때 이므로 결과에서 1을 빼준다
        bw.write(--count + "\n");
        bw.flush();
        bw.close();
    }
}
