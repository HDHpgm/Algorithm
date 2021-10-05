class CoinEx { // 거스름돈 연습문제
    final static int[] coins = {500, 100, 50, 10}; // 동전단위 4가지 고정

    public static void main (String[] args) {
        int goal = 1260; // 목표값 1260원
        int count = 0; // 동전갯수

        // 루프 다 돌면 갯수 나오도록
        for (int i = 0; i < coins.length; i++) {
            count += goal / coins[i]; // 나눈 몫을 더해줌
            goal %= coins[i]; // 나눈 나머지를 넣어줌
        }

        System.out.println("최소 동전 갯수 : " + count);

    }
}
