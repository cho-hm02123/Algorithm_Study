/* https://softeer.ai/practice/6277 [HSAT 2ȸ ���� �ڵ� ������ ����] �繰�ν� �ּ� ���� ���� ���α׷�
* 
* ����: ���̴��� ���� �νĵ� ������ �Է°��� ��鿡 N���� ������ �־���
*	�� ������ �� K���� ���� �� �ϳ��� ����
*	k���� ���� ���� �ش� ���� ��� �ϳ��� �����ϴ� �繰 �� ���̰� ���� ���� ���� ã�� �ش� ���̸� ���
*	�� ���� ������ �繰�� �ݵ�� ���簢��
*	���簢���� �� ���� ��� ���� Ȥ�� ����, ���ΰ� �ƴ� ��迡 ���� ���鵵 ����
*	���� Ȥ�� ������ ���̰� 0�̸� ���� 0
* 
* �Է�: N, K
*	N�ٿ� x, y, k
* 
* ���: �־��� �Է¿� ���� k���� �� ������ ��� �ϳ� �����ϴ� ���簢�� �� ���̰� ���� ���� ���� ����
* 
* Ǯ��: k�� �������� ��Ʈ��ŷ ��ü Ž��
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1000
#define X first
#define Y second

int n, k;
int sz[21];
int mm = 0x3f3f3f3f;
vector <pair<int, int>> v[21];

void bt(int knum, int xMin, int yMin, int xMax, int yMax) {
	if (knum > k) {
		mm = min(mm, abs((xMax - xMin) * (yMax - yMin)));
		return;
	}

	for (int i = 0; i < v[knum].size(); i++) {
		int xmx = max(xMax, v[knum][i].X);
		int ymx = max(yMax, v[knum][i].Y);
		int xmn = min(xMin, v[knum][i].X);
		int ymn = min(yMin, v[knum][i].Y);
		int rec = abs((xmx - xmn) * (ymx - ymn));
		if (knum == 1 || rec < mm)
			bt(knum + 1, xmn, ymn, xmx, ymx);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[z].push_back({x,y});
	}

	bt(1, MAX, MAX, -MAX, -MAX);
	cout << mm;

	return 0;
}