#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ����Ʈ�� �̵��� �� �ִ� 8���� ���� ����
int dx[] = { -2, -2, 2, 2, -1, -1, 1, 1 };
int dy[] = { -1, 1, -1, 1, -2, 2, -2, 2 };
char knight[3];
void main() {
	// ���� ����Ʈ�� ��ġ �Է¹ޱ�
	scanf("%s", knight);
	int row = knight[1] - '0';
	int column = knight[0] - 'a' + 1;
	int result = 0;

	// 8���� ���⿡ ���Ͽ� �� ��ġ�� �̵��� �������� Ȯ��
	for (int i = 0; i < 8; i++) {
		// �̵��ϰ��� �ϴ� ��ġ Ȯ��
		int nRow = row + dx[i];
		int nCol = column + dy[i];

		// �ش� ��ġ�� �̵��� �����ϴٸ� ī��Ʈ ����
		if (nRow >= 1 && nRow <= 8 && nCol >= 1 && nCol <= 8)
			result++;
	}
	printf("%d\n", result);

}