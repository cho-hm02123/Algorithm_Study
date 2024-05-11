#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

int n;
int score[51];
vector <int> v[51];

void dfs(int a) {
	queue <pair<int, int>> q;
	int num = 0;
	bool flag[51] = { 0, };

	q.push({ a,num });
	flag[a] = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < v[cur.X].size(); i++) {
			if (flag[v[cur.X][i]]) continue;
			num = cur.Y + 1;
			q.push({ v[cur.X][i], num });
			flag[v[cur.X][i]] = 1;
		}
	}
	if (num > score[a])
		score[a] = num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1)
			break;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i < n + 1; i++) {
		if (v[i].size() == n - 1) score[i] = 1;
		dfs(i);
	}

	int mm = n;
	vector<int>vv;
	for (int i = 1; i < n + 1; i++) {
		if (score[i] < mm) {
			vv.clear();
			vv.push_back(i);
			mm = score[i];
		}
		else if (score[i] == mm)
			vv.push_back(i);
	}

	cout << mm << " " << vv.size() << "\n";
	sort(vv.begin(), vv.end(), greater<>());
	while (!vv.empty()) {
		cout << vv.back() << " ";
		vv.pop_back();
	}

	return 0;
}
