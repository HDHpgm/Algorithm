#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	int num1 = *(int*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	int num2 = *(int*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (num1 < num2)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (num1 > num2)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}

int main() {
	int n, temp = 0, result = 0;
	scanf("%d", &n);

	int* time = malloc(sizeof(int) * n); // �޸� �Ҵ�
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &time[i]);
	}
	
	qsort(time, n, sizeof(time[0]), compare); // �� ����

	for (int j = 0; j < n; j++)
	{
		temp += time[j];
		result += temp;
	}

	printf("%d\n", result);

}