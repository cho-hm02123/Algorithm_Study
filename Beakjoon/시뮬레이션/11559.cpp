/*
뿌요를 밑으로 내릴 때 아래와 같이 i <= q.front().X인 상황을 고려해 줘야 함
안그러면 뿌요를 정상적으로 내릴 수 없음

......
......
......
......
......
G.....
......
G.....
......
G.....
......
GB....
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int cnt;
char arr[13][7];
bool check;
vector <pair<int, int>> v;

void down() {
	cnt++;
	for (int j = 0; j < 6; j++) {
		queue <pair<int, int>> q;
		for (int i = 11; i > -1; i--) {
			if (arr[i][j] != '.')
				q.push({ i,j });
		}
		if (!q.empty()) {
			for (int i = 11; i > -1; i--) {
				if (q.empty()) break;

				if (arr[i][j] == '.' && q.front().X < i) {
					arr[i][j] = arr[q.front().X][q.front().Y];
					arr[q.front().X][q.front().Y] = '.';
					q.pop();
				}
				else if (i <= q.front().X)
					q.pop();
			}
			
		}
	}
}

void del() {
	check = 1;
	for (int i = 0; i < v.size(); i++)
		arr[v[i].X][v[i].Y] = '.';
}

void domi() {
	bool flag[12][7] = { 0, };
	queue <pair<int, int>> q;
	check = 0;

	for(int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] != '.') {
				if (flag[i][j]) continue;

				v.clear();
				v.push_back({ i,j });
				q.push({ i,j });
				flag[i][j] = 1;

				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					
					for (int d = 0; d < 4; d++) {
						int x = cur.X + dx[d];
						int y = cur.Y + dy[d];

						if (x < 0 || y < 0 || x > 11 || y > 5 || flag[x][y]) continue;
						if (arr[x][y] == arr[i][j]) {
							q.push({ x,y });
							flag[x][y] = 1;
							v.push_back({ x,y });
						}
					}
				}

				if (v.size() > 3)
					del();
			}
		}

	if (check) {
		down();
		domi();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> arr[i][j];

	domi();
	cout << cnt;

	return 0;
}
