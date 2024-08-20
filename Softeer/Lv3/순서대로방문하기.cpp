/* [HSAT 7ȸ ���� �ڵ� ������ ����] ������� �湮�ϱ�
* 
* ����: ������ �̵� ������ ����� �� ã��
*	NxN ���� 0�� �� ���� 1�� ��
*	���� ������ m���� ������ ������� �湮 �̵��� �����¿� �ѹ� ������ ���� �ٽ� ������ �� ����
*	
* �Է�: N, M
*	������ ����
*	m���� ĭ
* 
* ���: m���� ������ ������� �湮�� �� �ִ� ���� �ٸ� ����� ��
* 
* Ǯ��: dfs ���, flag�� �� ��츶�� �ٸ��Ƿ� ���������� ���� �����ؼ� �Ѱ��ִ� ��� ���
*	������ ��ǥ�� ���� �������� �����ϴ��� k�� m+1�� �������� ������ �߰��� �������� �鸮�� ���� �� �̹Ƿ� �̸� Ȱ��
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

struct pointxy {
	int x, y;
};

int n, m, cnt;
int arr[5][5];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
pointxy p[20];

void dfs(pointxy a, bool cp[5][5], int k) {
	bool flag[5][5];
	copy(&cp[0][0], &cp[0][0] + 25, &flag[0][0]);
	if (flag[a.x][a.y]) return;
	if (k == m + 1 && a.x == p[k-1].x && a.y == p[k-1].y) {
		cnt++;
		return;
	}

	flag[a.x][a.y] = 1;

	for (int i = 0; i < 4; i++) {
		pointxy xy;
		xy.x = a.x + dx[i];
		xy.y = a.y + dy[i];

		if (xy.x < 1 || xy.y < 1 || xy.x > n || xy.y > n) continue;
		if (flag[xy.x][xy.y] || arr[xy.x][xy.y]) continue;
		if (xy.x == p[k].x && xy.y == p[k].y)
			dfs(xy, flag, k + 1);
		else
			dfs(xy, flag, k);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= m; i++)
		cin >> p[i].x >> p[i].y;

	bool flag[5][5] = { 0, };
	dfs(p[1], flag, 2);

	cout << cnt;

	return 0;
}