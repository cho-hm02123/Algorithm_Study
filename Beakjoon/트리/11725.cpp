#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[100001];
vector <int> v[100001];

void dfs(int cur) {
	for (int i = 0; i < v[cur].size(); i++) {
		if (arr[cur] == v[cur][i]) continue; // 부모가 자식이 될 수 없으므로 건너 뜀
		arr[v[cur][i]] = cur;
		dfs(v[cur][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	for (int i = 2; i < n + 1; i++)
		cout << arr[i] << "\n";

	return 0;
}
