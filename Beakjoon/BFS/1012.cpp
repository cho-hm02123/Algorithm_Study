#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

#define X first
#define Y second

int t, m, n, k;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		int num = 0;
		int arr[51][51] = { 0, };
		bool flag[51][51] = { 0, };
		stack <pair <int, int>> s;

		cin >> m >> n >> k;

		while (k--) {
			int a, b;
			cin >> a >> b;
			arr[a][b] = 1;
		}

		for(int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (flag[i][j] || arr[i][j] == 0) continue;

				s.push({ i,j });
				num++;

				while (!s.empty()) {
					pair <int, int> cur = s.top(); s.pop();
					if (flag[cur.X][cur.Y]) continue;
					flag[cur.X][cur.Y] = 1;

					for (int h = 0; h < 4; h++) {
						int x = cur.X + dx[h];
						int y = cur.Y + dy[h];

						if (x < 0 || y < 0 || x > m - 1 || y > n - 1 || flag[x][y] || arr[x][y] == 0) continue;
						s.push({ x,y });
					}
				}
			}
		cout << num << "\n";
	}

	return 0;
}
