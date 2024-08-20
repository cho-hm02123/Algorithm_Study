/* [HSAT 7ȸ ���� �ڵ� ������ ����] �ڵ��� �׽�Ʈ
* 
* ����: �ڵ����� ���� �������� ���� �Һ� ����, �� ���� �Ÿ��� ���� ����
*	n���� �ڵ����� ���� ��������� ���ǻ� 3���� �ڵ����� ���ؼ��� �׽�Ʈ�� ����
*	n���� ���� ���� �־����� �� q���� ���ǿ� ���� ���Ƿ� 3���� �ڵ����� ��� �׽�Ʈ�� �߾Ӱ��� m_j�� ������ ���� �ٸ� ����� ���� ���Ͽ���
* 
* �Է�: n, q
*	n���� �ڵ��� ���� (���� �ٸ��� long long��)
*	q���� �׽�Ʈ �� m_j
* 
* ���: �߾Ӱ��� m_j �� ������ ����� �� "\n"
* 
* Ǯ��: �׳� find�� �ϸ� �ð��ʰ��� ���� �̺�Ž�� ���
*	���� ���� longlong ���� ���� ����
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int n, q;
vector <ll> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		ll a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	while (q--) {
		ll m;
		cin >> m;

		int st = 0; 
		int en = n - 1;

		while (st != en) {
			int mid = (st + en+1) / 2;
			if (v[mid] < m)
				st = mid;
			else if (v[mid] == m) {
				cout << mid * (n - 1 - mid) << "\n";
				break;
			}
			else
				en = mid - 1;
		}

		if (st == en)
			cout << "0\n";
	}

	return 0;
}