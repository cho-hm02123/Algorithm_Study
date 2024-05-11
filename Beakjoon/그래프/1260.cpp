/*
  bfs는 push하고 바로 flag
  dfs는 빼고 flag
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int n, m, k, u, v;
bool bf[1001];
bool df[1001];
queue <int> q;
stack <int> s;
vector <int> vc[1001];

void bfs() {
	q.push(k);
	bf[k] = 1;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << " ";

		for (int i = 0; i < vc[cur].size(); i++) {
			int x = vc[cur][i];
			if (bf[x]) continue;
			q.push(x);
			bf[x] = 1;
		}
	}
}

void dfs() {
	s.push(k);

	while (!s.empty()) {
		int cur = s.top(); s.pop();
		if (df[cur]) continue;
		cout << cur << " ";

		df[cur] = 1;

		for (int i = vc[cur].size()-1; i >= 0; i--) {
			int x = vc[cur][i];
			if (df[x]) continue;
			s.push(x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	while (m--) {
		cin >> u >> v;
		vc[u].push_back(v);
		vc[v].push_back(u);
	}

	for (int i = 1; i < n + 1; i++)
		sort(vc[i].begin(), vc[i].end());

	dfs();
	cout << "\n";
	bfs();

	return 0;
}
