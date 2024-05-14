#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m;
int ind[32001];
vector <int> v[32001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		ind[b]++;
	}

	queue <int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << " ";
		for (int j = 0; j < v[cur].size(); j++) {
			ind[v[cur][j]]--;
			if (ind[v[cur][j]] == 0) q.push(v[cur][j]);
		}
	}

	return 0;
}
