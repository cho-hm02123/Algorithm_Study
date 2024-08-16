/* https://www.acmicpc.net/problem/4803 트리
* 
*
* 문제: 그래프가 주어졌을 때 트리의 개수를 세는 프로그램
* 
* 입력: 정점의 개수 n과 간선의 개수 m, m개 줄에 간선을 나타내는 두 개의 정수
* 
* 출력: 트리가 없다면 "Case n: No trees."
*	트리가 하나면 "Case n: There is one tree."
*	트리가 T개 이면 "Case n: A forest of T trees."
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector <int> v[501];
bool flag[501];
bool tr;

void bfs(int cur, int pre) {
	for (int nxt : v[cur]) {
		if (nxt == pre) continue;
		if (flag[nxt]) {
			tr = false;
			continue;
		}
		flag[nxt] = true;
		bfs(nxt, cur);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt = 1;
	while (1) {
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		for (int i = 0; i <= n; i++)
			v[i].clear();
		fill(flag, flag + n + 1, 0);
		int ans = 0;
		tr = false;

		while (m--) {
			int a, b;
			cin >> a >> b;

			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int i = 1; i <= n; i++) {
			if (flag[i]) continue;
			flag[i] = 1;
			tr = 1;
			bfs(i, 0);
			ans += tr;
		}

		if (ans == 0)
			cout << "Case " << cnt << ": No trees.\n";
		else if (ans == 1)
			cout << "Case " << cnt << ": There is one tree.\n";
		else
			cout << "Case " << cnt << ": A forest of " << ans << " trees.\n";
		cnt++;
	}

	return 0;
}
