package com.algorithm;

public class Right0 {
    static int getPosOfRightmostSetBit(int n) { // 마지막 0의 위치찾는 공식
        // log2(~n & (n+1)) + 1 을 구현한 식
        return (int) (Math.log(~n & (n+1)) / Math.log(2)) + 1;
    }

    static int setRightmostUnsetBit(int n) {
        if (n == 0) return 1;
        if ((n & (n+1)) == 0) return n;

        int pos = getPosOfRightmostSetBit(n);
        System.out.println("제일 끝의 0 위치 : " + pos + "번째");
        return ((1 << pos - 1) | n); // 구한 0의 위치에 1을 넣고 원래수에 더해줌
    }

    public static void main(String[] args) {
        int n = 21;
        System.out.println(setRightmostUnsetBit(n));
    }
}
