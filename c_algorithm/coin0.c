#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, K, cnt = 0;
	scanf("%d %d", &N, &K);

	int* coins = malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &coins[i]);
	}
	for (int j = N-1; j >= 0; j--)
	{
		cnt += K / coins[j];
		K %= coins[j];
	}
	free(coins);
	printf("%d\n", cnt);
	return 0;
}