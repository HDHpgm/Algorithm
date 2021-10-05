import java.io.*;

public class MultiplyOrPlus {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = br.readLine();
        br.close();
        long result = str.charAt(0) - '0';
        for (int i = 1; i < str.length(); i++) {
            int next = str.charAt(i) - '0';
            if (result <= 1 || next <= 1) result += next;
            else result *= next;
        }
        bw.write(result + "\n");
        bw.flush();
        bw.close();
    }
}
