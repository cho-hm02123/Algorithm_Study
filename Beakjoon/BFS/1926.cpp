#include <istream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[502][502] = { 0, };
bool flag[502][502] = { 0, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int x, y;
	cin >> x >> y;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cin >> board[i][j];

	queue<pair<int, int>> q;
	int num = 0;
	int mx = 0;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (flag[i][j] == 1 || board[i][j] == 0) continue;

			num++;
			q.push({ i,j });
			int area = 1;
			flag[i][j] = 1;

			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();

				for (int c = 0; c < 4; c++) {
					int nx = cur.X + dx[c];
					int ny = cur.Y + dy[c];

					if (board[nx][ny] == 0 || flag[nx][ny] == 1) continue;
					q.push({ nx,ny });
					area++;
					flag[nx][ny] = 1;
					
				}
			}
			mx = max(area, mx);
		}
	}
	cout << num << "\n" << mx;
	return 0;
}
