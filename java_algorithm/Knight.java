import java.io.*;

public class Knight {

    public static final int[] dx = {-2, -2, 2, 2, -1, -1, 1, 1};
    public static final int[] dy = {-1, 1, -1, 1, -2, 2, -2, 2};

    public static void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int result = 0;

        String str = br.readLine(); // a1 형식으로 입력
        br.close();
        int row = str.charAt(1) - '0'; // 행
        int column = str.charAt(0) - 'a' + 1; // 열 -> 숫자로 바꿔줌

        for (int i = 0; i < 8; i++) {
            int tempRow = row + dx[i];
            int tempColumn = column + dy[i];

            if (tempRow >= 1 && tempRow <= 8 && tempColumn >= 1 && tempColumn <= 8)
                result++;
        }
        bw.write(result+"");
        bw.flush();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        solution();
    }
}
