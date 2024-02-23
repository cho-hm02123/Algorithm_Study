#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int flag_f[1000][1000] = { 0, };
int flag_h[1000][1000] = { 0, };
char map[1000][1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int x, y;
	cin >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cin >> map[i][j];

	queue<pair<int, int>> f;
	queue < pair<int, int>> h;
	for(int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
		{
			if (map[i][j] == '#') 
			{
				flag_f[i][j] = -1;
				flag_h[i][j] = -1;
			}
			if (map[i][j] == 'F') 
			{
				flag_f[i][j]++;
				f.push({ i, j});
			}
			if (map[i][j] == 'J') 
			{
				if (i == 0 || j == 0 || i == x - 1 || j == y - 1) {
					cout << "1";
					return 0;
				}
				else {
					flag_h[i][j]++;
					h.push({ i,j });
				}
			}
		}

	while (!f.empty()) 
	{
		pair<int, int> cur_f = f.front(); f.pop();

		for (int i = 0; i < 4; i++) 
		{
			int nx = cur_f.X + dx[i];
			int ny = cur_f.Y + dy[i];

			if (nx < 0 || ny < 0 || nx > x - 1 || ny > y - 1) continue;
			if (flag_f[nx][ny] != 0) continue;

			flag_f[nx][ny] = flag_f[cur_f.X][cur_f.Y] + 1;
			f.push({ nx, ny });
		}
	}
	


	while (!h.empty())
	{
		pair<int, int> cur_h = h.front(); h.pop();
		
		for (int i = 0; i < 4; i++) 
		{
			int nx = cur_h.X + dx[i];
			int ny = cur_h.Y + dy[i];

			if (nx < 0 || ny < 0 || nx > x - 1 || ny > y - 1) continue;
			if (flag_h[nx][ny] != 0) continue;
			if (flag_f[nx][ny] > 0 && flag_f[nx][ny] <= flag_h[cur_h.X][cur_h.Y] + 1) continue;

			flag_h[nx][ny] = flag_h[cur_h.X][cur_h.Y] + 1;
			h.push({ nx, ny });
			if (nx == 0 || ny == 0 || nx == x - 1 || ny == y - 1) 
			{
				cout << flag_h[nx][ny];
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE";
	return 0;
}
