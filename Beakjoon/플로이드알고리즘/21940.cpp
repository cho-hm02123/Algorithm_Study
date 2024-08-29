/* https://www.acmicpc.net/problem/21940 ������� ������
* 
* ����: ���ø� �����ϴ� ���δ� �Ϲ� ���ุ ����
*	�Ʒ� ������ �����ϴ� X ���ÿ��� ����
*		1. �պ� �ð��� �ڽ��� ����ִ� ���ÿ��� X ���÷� �̵��ϴ� �ð��� �ٽ� X���� �ڱ� ���÷� ���ư��� �ð��� ��
*		2. ��ΰ� ���θ� �̿��� �� �� �ִ� ���ø� ����
*		3. ����� �պ� �ð� �� �ִ밡 �ּ��� ���� X�� ����
*		4. ���� X�� �ϳ� �̻� ������ ����
* 
* �Է�: ������ �� N, ���� �� M
*	M���� A, B, C (A->B�� �ɸ��� �ð� C)
*	�� �ο� K
*	ģ������ ��� �ִ� ���� ��ȣ
* 
* ���: ���� X (���� �������� ��������)
* 
* Ǯ��: �� ��庰 �ִ� �ð� ���� �� �ֵ��� ��� �ִ� ���ÿ��� X���ñ��� �պ� �ִ�ð� ���ϱ�
*	X ������ �ִ� �ð��� ���������� ���� ���� �ð��� ���ؼ� ���� �ð����� ������ ���� �ʱ�ȭ �� ���� X�� ����, ���� �ð��� ����
*	������ ���Ϳ� X �߰�
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX 200
#define ll long long

int n, m, knum;
int city[MAX + 2];
ll arr[MAX + 2][MAX + 2];
vector <int> x;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) arr[i][j] = INF;

	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		arr[a][b] = t;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (arr[i][j] > arr[i][k] + arr[k][j]) arr[i][j] = arr[i][k] + arr[k][j];

	cin >> knum;
	for (int i = 1; i <= knum; i++)
		cin >> city[i];

	int bi = INF;
	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (int j = 1; j <= knum; j++) {
			if (arr[i][city[j]] == INF || arr[city[j]][i] == INF) break;
			if (arr[i][city[j]] + arr[city[j]][i] > mx)
				mx = arr[i][city[j]] + arr[city[j]][i];
		}

		if (bi > mx) {
			x.clear();
			x.push_back(i);
			bi = mx;
		}
		else if (bi == mx) x.push_back(i);
	}

	for (int i = 0; i < x.size(); i++)
		cout << x[i] << " ";

	return 0;
}