#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int n, m;
int ind[1001];
vector <int> v[1001];
queue <int> res;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int k;
		queue <int> t;
		cin >> k;
		for (int i = 0; i < k; i++) {
			int a;
			cin >> a;
			t.push(a);
			if (i == 0) continue;
			int b = t.front(); t.pop();
			v[b].push_back(a);
			ind[a]++;
		 }
	}
	queue <int> q;
	for (int i = 1; i < n + 1; i++) {
		if (ind[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		res.push(cur);
		for (int i = 0; i < v[cur].size(); i++) {
			ind[v[cur][i]]--;
			if (ind[v[cur][i]] == 0)
				q.push(v[cur][i]);
		}
	}

	if (res.size() == n) {
		while (!res.empty()) {
			cout << res.front() << "\n";
			res.pop();
		}
	}
	else
		cout << 0;

	return 0;
}
