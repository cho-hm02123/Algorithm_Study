#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int vn, en, st;
int rst[20001];
vector <pair <int, int>> v[20001]; // 거리, 정점

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> vn >> en >> st;
	for (int i = 1; i < vn + 1; i++)
		rst[i] = INF;
	rst[st] = 0;
	for (int i = 0; i < en; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({ w,b });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,st });
	while (!pq.empty()) {
		int u, w;
		tie(w, u) = pq.top(); pq.pop();

		if (w != rst[u]) continue;
		for (auto c : v[u]) {
			if (rst[c.Y] <= w + c.X) continue;
			rst[c.Y] = w + c.X;
			pq.push({ rst[c.Y], c.Y });
		}
	}

	for (int i = 1; i < vn + 1; i++) {
		if (rst[i] == INF)
			cout << "INF" << "\n";
		else
			cout << rst[i] << "\n";
	}

	return 0;
}
