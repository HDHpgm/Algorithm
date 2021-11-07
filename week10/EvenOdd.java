package com.algorithm;

import java.util.Scanner;

public class EvenOdd {
    static boolean isEvenOrOdd(int num) { // 홀짝 판별

        if ((num ^ 1) == num + 1) { // xor 연산 후 1 감소하면 홀수, 증가하면 짝수
            return true; // 짝수
        }
        else return false; // 홀수
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int num = scanner.nextInt();
        scanner.close();

        if (isEvenOrOdd(num))
            System.out.println("Even");
        else
            System.out.println("Odd");

    }
}
