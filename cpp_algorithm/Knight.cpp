#include <iostream>
using namespace std;
string inputData;
// ����Ʈ�� �̵��� �� �ִ� 8���� ���� ����
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

void main() {
	// ���� ����Ʈ�� ��ġ �Է¹ޱ�
	cin >> inputData;
	int row = inputData[1] - '0';
	int column = inputData[0] - 'a' + 1;
	// 8���� ���⿡ ���Ͽ� �� ��ġ�� �̵��� �������� Ȯ��
	int result = 0;
	for (int i = 0; i < 8; i++) {
		// �̵��ϰ��� �ϴ� ��ġ Ȯ��
		int nextRow = row + dx[i];
		int nextColumn = column + dy[i];
		// �ش� ��ġ�� �̵��� �����ϴٸ� ī��Ʈ ����
		if (nextRow >= 1 && nextRow <= 8 && nextColumn >= 1 && nextColumn <= 8) {
			result += 1;
		}
	}
	cout << result << '\n';
}