#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int cnt; // n개의 노드에 n-1개 간선, 현재 총 m개 간선, 현재 연결된 덩어리 수 cnt개를 구하면 총 m + cnt - 1개의 간선이 있는 것임 따라서 m + cnt - 1 - (n-1) + cnt - 1
bool flag[100001];
vector <int> v[100001];

void dfs(int cur) {
	if (flag[cur]) return;
	flag[cur] = true;
	for (int nxt : v[cur])
		dfs(nxt);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (flag[i]) continue;
		dfs(i);
		cnt++;
	}

	cout << (m + cnt - 1) + (cnt - 1) - (n - 1);

	return 0;
}
