#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
char moveTypes[4] = { 'L', 'R', 'U', 'D' };

int n;
char str[100];
char plans[100];
int x = 1, y = 1;

void main() {
	scanf("%d\n", &n); // n X n �Է¹ް� ������ϸ� �Ʒ� ���ڿ� �ȹ޾��� (�����ε�)
	int cnt = 0, count = 0;
	scanf("%[^\n]s", str); // �������� ���ڿ� ��� �о� ����


	while (1) {
		if (str[count] == '\n' || '\0') break; // ���ڿ� ���̸� break;
		if (str[count] == ' ') {
			count++;
			continue;
		}

		plans[cnt++] = str[count++];
		char plan = plans[cnt];

		// �̵� �� ��ǥ ���ϱ�
		int nx = 0, ny = 0;
		for (int j = 0; j < 4; j++)
		{
			if (plan == moveTypes[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
				break;
			}
		}
		// ���� ����� ����
		if (nx < 1 || ny < 1 || nx > n || ny > n) continue;

		x = nx;
		y = ny;

	}
	printf("%d %d\n", x, y);

}