import java.io.*;
import java.util.StringTokenizer;

public class UpDownLeftRight {

    static int x = 1, y = 1;
    static final char[] moveTypes = {'L', 'R', 'U', 'D'};
    static final int[] dx = {0, 0, -1, 1};
    static final int[] dy = {-1, 1, 0, 0};

    public static void solution() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine()); // n x n 을 위해 입력받음

        StringTokenizer st = new StringTokenizer(br.readLine()); // 공백기준으로 분리
        br.close();
        char[] plans = new char[st.countTokens()]; // 분리된 char 갯수 로 선언

        int index = 0; // plans 인덱스 역할
        while(st.hasMoreTokens()) {
            plans[index++] = st.nextToken().charAt(0); // char 로 변환해 넣어줌
        }

        int tempX = 0;
        int tempY = 0;
        for (char plan : plans) { // plans 요소를 하나씩 꺼내서 반복
            for (int i = 0; i < moveTypes.length; i++) { // L, R, U, D 4개만 비교하면 됨
                if (plan == moveTypes[i]) { // 문자 비교 -> 같다면?
                    tempX = x + dx[i];
                    tempY = y + dy[i];
                    break;
                }
            }
            if (tempX < 1 || tempX > 5 || tempY < 1 || tempY > 5 )
                continue;
            x = tempX;
            y = tempY;
        }
        bw.write(x+" "+y);
        bw.flush();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        solution();
    }
}
