package com.algorithm;

import java.util.Scanner;

public class ToggleCase {
    /*  예를들어
        ‘A＇
        0 1 0 0 0 0 0 1
        ‘a’
        0 1 1 0 0 0 0 1
        위 비트중에서 6번째인 비트를 32와 XOR 연산 -> 비트 값이 0이면 1로, 1이면 0으로 바꾼다. (대문자 소문자 토글한다는 의미)
*/
    static char[] toggle(String str) {
        char[] temp = str.toCharArray();

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ' ') continue; // 문자열에 공백이 있을 시 넘어감
            temp[i] = (char) (str.charAt(i) ^ 32); // 6번째 비트에 xor 연산 -> 결과 0 나오면 대문자로 1 나오면 소문자로 변경
        }

        return temp;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        scanner.close();

        System.out.println(toggle(str));
    }
}
