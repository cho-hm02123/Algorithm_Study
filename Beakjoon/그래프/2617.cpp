#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans;
vector <int> hv[101];
vector <int> lt[101];

bool bfs(int k, vector <int> v[101]) {
	bool flag[101] = { 0, };
	queue <int> q;
	q.push(k);
	flag[k] = 1;
	int cnt = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			if (flag[v[cur][i]]) continue;
			cnt++;
			flag[v[cur][i]] = 1;
			q.push(v[cur][i]);
		}
	}

	if (cnt > n / 2) return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		hv[a].push_back(b);
		lt[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (bfs(i, hv) || bfs(i, lt))
			ans++;
	}

	cout << ans;
	return 0;
}
