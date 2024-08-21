/* https://softeer.ai/practice/6250 [HSAT 5ȸ ���� �ڵ� ������ ����] ���� ��
* 
* 30m 14s
* 
* ����: N���� �����ϴ� ���͵�
*	��ȸ�� 3�� ����, ��� �������� ���� �� ��ȸ���� 0 �̻� 1000 ������ ������ ���� �� ���� ( �� ��ȸ�� �� �̻��� ������ ����)
*	�� ��ȸ�� ��� �� ���� ��� ������ ���� �� ������ ���� ���
*	���� ����� �� ��ȸ���� ���� ���� ������ �ٽ� �ޱ�
*	�� �������� ��ȸ�� ��� �� ���� ��� ���
* 
* �Է�: ������ �� N (3 �̻� 100,000 ����), ������ �ٿ� �� ��ȸ ������ N��
* 
* ���: ù ������ �ٿ��� �� �������� ��ȸ�� ��� ������ �ٿ� ���� ���
* 
* Ǯ��: �� �޾Ƽ� ������������ sort ��Ŵ �̶� index�� �����ϱ� ���� pair�� ���� �ε����� ���� ��������
*	�ϳ��� for������ �Լ��� ���� ����� ��� ���� ���յ� ������ �Է¶� �־���
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100001
#define X first
#define Y second

int n;
int rst[4][MAX];
vector <pair <int, int>> v[4];

void cal(int k, vector <pair<int, int>> cp) {
	int cnt = 1;
	int num = 1;
	int cur = cp[0].X;
	rst[k][cp[0].Y] = cnt;

	for (int i = 1; i < n; i++) {
		num++;
		if (cur == cp[i].X)
			rst[k][cp[i].Y] = cnt;
		else {
			cnt = num;
			rst[k][cp[i].Y] = cnt;
			cur = cp[i].X;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			v[i].push_back({ a,j });
			if (i == 2) {
				int sum = v[0][j].X + v[1][j].X + v[2][j].X;
				v[3].push_back({ sum, j });
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		sort(v[i].begin(), v[i].end(), greater<>());
		cal(i, v[i]);
	}

	for (int i = 0; i < 4; i++) {
		cout << "\n";
		for (int j = 0; j < n; j++)
			cout << rst[i][j] << " ";
	}

	return 0;
}