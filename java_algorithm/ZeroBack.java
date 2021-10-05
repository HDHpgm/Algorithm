import java.util.Arrays;

public class ZeroBack {
    public static void main(String[] args) {
        int[] arr = {6, 0, 8, 2, 3, 0, 4, 0, 1};
        int j = 0;

        for (int item : arr) { // arr의 원소 하나씩 꺼내서 i에 넣어 for문 돌림
            if (item != 0) {
                arr[j] = item; // 0이 아닌 원소만 j를 인덱스로 하여 삽입
                j++; // 0이 아닐때만 증가
            } // 나올 때는 6
        }
        for (int i = j; i < arr.length; i++)  // 나머지는 모두 0으로 채움
            arr[i] = 0;

        System.out.println(Arrays.toString(arr)); // 출력
    }
}
