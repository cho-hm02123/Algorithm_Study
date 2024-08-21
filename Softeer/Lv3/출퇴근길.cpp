/* https://softeer.ai/practice/6248 [HSAT 6ȸ ���� �ڵ� ������ ����] ����ٱ�
* 
* 1h 23m 28s
* 
* ����: ����ٱ��� �ܹ��� �׷����� ��Ÿ�� �� ���� n���� ����, m���� ����
*	S���� T�� ���� ��ο� T���� S�� ���� ��ο� ��� ���ԵǴ� ������ ����
* 
* �Է�: N, M
*	M���� ���� ���� x, y (x -> y)
*	��ȯ�� �� S, ȸ�� T
* 
* ���: ����ٱ濡 ��ġ�� ������ ����
* 
* Ǯ��: ��� �� �鸮�� ��� ��� üũ, ��� �� �鸮�� ��� ��� üũ �̶� �鸮�⸸ �ϰ� �������� �������� �ʴ� ���� �Ÿ��� ���� ������ ���͸� �߰��ؼ� �˻�
* 
* �ݷ�
* 4 5		
* 3 2
* 3 1
* 1 2
* 1 4
* 4 3
* 1 3
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

# define MAX 100001

int n, m, st, en, ans;
bool flag1[MAX];
bool flag2[MAX];
bool flag3[MAX];
bool flag4[MAX];
vector <int> v[MAX];
vector <int> rv[MAX];

void dfs (int cur, bool flag[], vector <int> cv[]) {
	if (flag[cur]) return;

	flag[cur] = 1;
	for (int nxt : cv[cur])
		dfs(nxt, flag, cv);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		rv[y].push_back(x);
	}
	cin >> st >> en;

	flag1[en] = 1;
	flag2[st] = 1;

	dfs(st, flag1, v);
	dfs(en, flag2, v);
	dfs(st, flag3, rv);
	dfs(en, flag4, rv);

	for (int i = 1; i <= n; i++)
		if (flag1[i] && flag2[i] && flag3[i] && flag4[i])
			ans++;

	cout << ans-2; // st, en ���ֱ�
	return 0;
}