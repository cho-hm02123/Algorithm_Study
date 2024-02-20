#include <istream>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <tuple>

using namespace std;

#define X first
#define Y second
#define Z third

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char map[102][102];
bool flag[102][102] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int x, y;
	cin >> x >> y;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cin >> map[i][j];

	queue<tuple<int, int, int>> q;

	q.push({ 0,0,1 });
	flag[0][0] = 1;

	while (!q.empty()) {
		tuple<int, int, int> cur = q.front(); q.pop();

		for (int c = 0; c < 4; c++) {
			int nx = get<0>(cur) + dx[c];
			int ny = get<1>(cur) + dy[c];

			if (nx < 0 || nx > x-1 || ny < 0 || ny > y-1) continue;
			if (flag[nx][ny] == 1 || map[nx][ny] == '0') continue;

			q.push({ nx, ny, get<2>(cur) + 1 });
			flag[nx][ny] = 1;
		}
		if (get<0>(cur) == x-1 && get<1>(cur) == y-1) {
			cout << get<2>(cur) << "\n";
		}
	}
	

	return 0;
}
