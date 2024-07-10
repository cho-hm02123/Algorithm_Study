/*
  1. q에 빙산 좌표 넣어줌
  2. 빙산 주변에 물 칸 개수 찾고 빙산 녹임
  3. 빙산 안녹은 것만 q에 다시 넣어줌
  4. q 가장 앞 좌표를 qq에 넣어주고 해당 빙산이랑 붙어있는 빙산 개수를 찾음
  5. q 사이즈와 4에서 찾은 수가 다르면 빙산이 쪼개진것
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, m;
int arr[301][301];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue <pair <int, int>> q;

int bfs() {
	int year = 0;

	while (1) {
		int cp[301][301] = { 0, };
		copy(&arr[0][0], &arr[0][0] + 301*301, &cp[0][0]);
		
		int sz = q.size();

		while (sz--) {
			pair <int, int> cur = q.front(); q.pop();

			int c0 = 0;
			for (int i = 0; i < 4; i++) {
				int x = cur.X + dx[i];
				int y = cur.Y + dy[i];

				if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || cp[x][y] != 0) continue;
				c0++;
			}
			arr[cur.X][cur.Y] -= c0;
			if (arr[cur.X][cur.Y] > 0) q.push({ cur.X, cur.Y });
			else arr[cur.X][cur.Y] = 0;
		}
		year++;

		sz = q.size();
		
		if (sz == 0) return 0;

		int check = 1;
		bool flag[301][301] = { 0, };
		queue <pair <int, int>> qq;
		qq.push({ q.front().X, q.front().Y });
		flag[q.front().X][q.front().Y] = 1;

		while (!qq.empty()) {
			pair <int, int> cur = qq.front(); qq.pop();

			for (int i = 0; i < 4; i++) {
				int x = cur.X + dx[i];
				int y = cur.Y + dy[i];

				if (x < 0 || x > n - 1 || y < 0 || y >m - 1 || flag[x][y] == 1 || arr[x][y] == 0) continue;
				flag[x][y] = 1;
				check++;
				qq.push({ x, y });
			}
		}

		if (sz != check) return year;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0)
				q.push({i,j});
		}

	int rst = bfs();
	cout << rst;

	return 0;
} 
