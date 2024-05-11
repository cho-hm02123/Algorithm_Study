#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, u, v, num;
bool flag[1001];
vector <int> vc[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	while (m--) {
		cin >> u >> v;
		vc[u].push_back(v);
		vc[v].push_back(u);
	}

	for (int i = 1; i < n + 1; i++) {
		if (flag[i]) continue;
		
		queue <int> q;
		q.push(i);
		flag[i] = 1;
		num++;

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int a = 0; a < vc[cur].size(); a++) {
				if (flag[vc[cur][a]]) continue;
				q.push(vc[cur][a]);
				flag[vc[cur][a]] = 1;
			}
		}
	}
	cout << num;
	return 0;
}
