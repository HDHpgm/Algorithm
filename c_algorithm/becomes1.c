#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, k, cnt = 0;

	scanf("%d %d", &n, &k);

	while (1) {
		int target = (n / k) * k;
		cnt += (n - target);
		n = target;

		if (n == 0) break;

		n /= k;
		cnt++;
	}
	
	printf("%d\n", --cnt);

	return 0;
}