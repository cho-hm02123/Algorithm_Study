/* https://softeer.ai/practice/6274 [HSAT 1ȸ ���� �ڵ� ������ ����] ���������� ������ ������ ������ ����ý���
* 
* 1h 43m 34s
* 
* ����: ���� ������� �ǽð� ����� �ϴ� �������� ���� ���� ���� N���� �����η� ������ ���θ� ���� ��
*	�����ΰ� ����� ���� ����, ������ �������� ������
*	���� �� ĭ �̵� �� 1T�� �ɸ�
* 
*	�������� ��ȣ���� 12���� ���� �� 4������ ������ ���� �ݺ���
*		��ȣ 1: ��) ������  /  ��ȣ 2: ��) ������  /  ��ȣ 3: ��) ������  /  ��ȣ 4: ��) ������
*		��ȣ 5: ��) ����    /  ��ȣ 6: ��) ����	   /  ��ȣ 7: ��) ����    /  ��ȣ 8: ��) ����
*		��ȣ 9: ��) ����    /  ��ȣ 10: ��) ����   /  ��ȣ 11: ��) ����   /  ��ȣ 12: ��) ����
* 
*	�������� �ڵ����� ������ �ʰ� �ð� T �̳��� �� �� �ִ� �������� �� (��ȣ�� ���� ������ �� �����ο� �� �� ����)
*	
*  �Է�: N, �ð� T
*	N^2���� �ٿ� �� �������� ��ȣ ���� (��ȣ�� �׻� 4��, ������ x�� ����)
* 
* ���: �̵� ��ο� �ִ� ��� �������� ���� ��� (�ѹ� ���� �����δ� �ߺ��ؼ� ���� ����)
* 
* Ǯ��: ���� ���� ������ dir �߰��ؾ���
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX 10000

struct numt {
	int num, dir, t;
};

int n, t, ans;
int goway[13][3] = {
	{4, 4, 4},
	{1, 0, 3},
	{2, 1, 0},
	{1, 2, 3},
	{2, 3, 0},
	{1, 0, 4},
	{2, 1, 4},
	{3, 2, 4},
	{0, 3, 4},
	{3, 0, 4},
	{0, 1, 4},
	{1, 2, 4},
	{2, 3, 4}
};
int dx[5] = { 0, -1, 0, 1, 0 }; //  0, 1, 2, 3
int dy[5] = { 1, 0, -1, 0, 0 }; // ��, ��, ��, ��
int arr[MAX + 2][4];
bool flag[MAX + 2];

void findway() {
	stack <numt> q;
	q.push({ 0, 1, 0 });

	while (!q.empty()) {
		numt cur = q.top(); q.pop();
		if (cur.t > t) continue;
		int light = arr[cur.num][cur.t % 4];
		if (!flag[cur.num]){
			flag[cur.num] = 1;
			ans++;
		}

		if (goway[light][1] != cur.dir) continue;

		for (int i = 0; i < 3; i++) {
			if (goway[light][i] == 4) continue;

			int x = cur.num / n + dx[goway[light][i]];
			int y = cur.num % n + dy[goway[light][i]];
			int nnum = x * n + y;

			if (x < 0 || y < 0 || x > n-1 || y > n-1) continue;
			q.push({ nnum, goway[light][i], cur.t + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> t;
	int k = pow(n, 2);
	for (int i = 0; i < k; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[i][j];

	findway();

	cout << ans;

	return 0;
}