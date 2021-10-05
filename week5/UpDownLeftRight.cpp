#include <iostream>
#include <string>
using namespace std;
int n;
string plans;
int x = 1, y = 1;
// L, R, U, D�� ���� �̵� ����
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
char moveTypes[4] = { 'L', 'R', 'U', 'D' };
int main(void) {
	cin >> n;
	cin.ignore(); // ���� ����
	getline(cin, plans);

	// �̵� ��ȹ�� �ϳ��� Ȯ���ϱ�
	for (int i = 0; i < plans.size(); i++) {
		char plan = plans[i];
		// �̵� �� ��ǥ ���ϱ�
		int nx = -1, ny = -1;
		for (int j = 0; j < 4; j++) {
			if (plan == moveTypes[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}
		// ������ ����� ��� ����
		if (nx < 1 || ny < 1 || nx > n || ny > n)
			continue;
		// �̵� ����
		x = nx;
		y = ny;
	}
	cout << x << ' ' << y << '\n';
	return 0;
}