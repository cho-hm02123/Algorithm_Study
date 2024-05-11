#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n;
int arr[101][101];

bool dfs(int v, int u) {
	bool flag[101] = { 0, };
	stack <int> s;
	s.push(v);

	while (!s.empty()) {
		int cur = s.top(); s.pop();
		if (flag[cur]) continue;
		flag[cur] = 1;

		for (int i = 0; i < n; i++) {
			if (arr[cur][i] == 0) continue;
			if (i == u) return true;
			if (flag[i]) continue;
			s.push(i);
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++) {
		if (i > 0)
			cout << "\n";
		for (int j = 0; j < n; j++)
			cout << dfs(i, j) << " ";
	}

	return 0;
}
