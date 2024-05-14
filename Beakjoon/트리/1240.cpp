#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n, m;
int len[1001][1001];
vector <int> v[1001];

int dfs(int cur, int tar) {
	bool flag[1001] = { 0, };
	stack <pair<int, int>> s;
	int sum = 0;
	s.push({ cur, sum});
	while (!s.empty()) {
		pair <int, int> x = s.top(); s.pop();
		if (flag[x.first]) continue;
		flag[x.first] = 1;
		for (int i = 0; i < v[x.first].size(); i++) {
			sum = x.second + len[x.first][v[x.first][i]];
			if (tar == v[x.first][i]) return sum;
			s.push({ v[x.first][i], sum });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(b);
		v[b].push_back(a);
		len[a][b] = c;
		len[b][a] = c;
	}

	for (int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		cout << dfs(a,b) << "\n";
	}

	return 0;
}
