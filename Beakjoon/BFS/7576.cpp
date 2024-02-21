#include <istream>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <tuple>

using namespace std;

#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int box[1002][1002];
int flag[1002][1002];
int mx = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int x, y;
	cin >> x >> y;

	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			cin >> box[i][j];

	queue<pair<int, int>> q;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (box[i][j] == 1)
				q.push({ i, j });
			if (box[i][j] == 0)
				flag[i][j] = -1;
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || ny < 0 || nx > y - 1 || ny > x - 1) continue;
			if (flag[nx][ny] > -1) continue;

			flag[nx][ny] = flag[cur.X][cur.Y] + 1;
			q.push({ nx, ny});
		}
	}

	for(int i = 0; i < y; i++)
		for (int j = 0; j < x; j++) {
			if (flag[i][j] == -1) {
				cout << "-1";
				return 0;
			}
			mx = max(mx, flag[i][j]);
		}
	cout << mx;
}
