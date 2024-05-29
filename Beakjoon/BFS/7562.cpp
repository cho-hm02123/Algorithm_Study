#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int t, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		int arr[301][301] = { 0, };
		queue <pair <int, int>> q;
		cin >> n;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				arr[i][j] = INF;

		int a, b;
		cin >> a >> b;
		q.push({ a,b });
		arr[a][b] = 1;
		cin >> a >> b;

		while (!q.empty()) {
			pair <int, int> cur = q.front(); q.pop();
			for (int i = 0; i < 8; i++) {
				int x = cur.X + dx[i];
				int y = cur.Y + dy[i];

				if (x < 0 || y < 0 || x > n-1 || y > n-1) continue;
				if (arr[x][y] > arr[cur.X][cur.Y] + 1) {
					arr[x][y] = arr[cur.X][cur.Y] + 1;
					if (x == a && y == b) continue;
					q.push({ x,y });
				}
			}
		}
		cout << arr[a][b] - 1 << "\n";
	}

	return 0;
}
