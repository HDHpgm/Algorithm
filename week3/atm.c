#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	int num1 = *(int*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (num1 > num2)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}

int main() {
	int n, temp = 0, result = 0;
	scanf("%d", &n);

	int* time = malloc(sizeof(int) * n); // 메모리 할당
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &time[i]);
	}
	
	qsort(time, n, sizeof(time[0]), compare); // 퀵 정렬

	for (int j = 0; j < n; j++)
	{
		temp += time[j];
		result += temp;
	}

	printf("%d\n", result);

}