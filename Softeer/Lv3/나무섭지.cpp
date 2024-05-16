#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;
int n, m;
int fig[1001][1001] = { 0, };
bool flag[1001][1001];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector <pair<int, int>> v;
pair <int, int> nam;
pair <int, int> ex;

string cal() {
	int mm = n * m;
	for (int i = 0; i < v.size(); i++)
		mm = min(mm, abs(v[i].X - ex.X) + abs(v[i].Y - ex.Y));

	queue <pair<int, int>> q;
	q.push({ nam.X, nam.Y });
	flag[nam.X][nam.Y] = 1;

	while (!q.empty()) {
		pair <int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int x = cur.X + dx[i];
			int y = cur.Y + dy[i];

			if (x < 1 || y < 1 || x > n || y > m || flag[x][y]) continue;
			fig[x][y] = fig[cur.X][cur.Y] + 1;
			q.push({ x,y });
			flag[x][y] = 1;
		}
	}

	if (fig[ex.X][ex.Y] == 0) {
		if (ex.X == nam.X && ex.Y == nam.Y)
			return "Yes";
		else
			return "No";
	}
	if (fig[ex.X][ex.Y] < mm)
		return "Yes";
	else
		return "No";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		int cnt = 0;
		string s;
		cin >> s;
		for (auto c : s) {
			cnt++;
			if (c == '.') continue;
			if (c == 'G')
				v.push_back({ i,cnt });
			else if (c == 'N')
				nam = make_pair(i, cnt);
			else if (c == 'D')
				ex = make_pair(i, cnt);
			else if (c == '#')
				flag[i][cnt] = 1;
		}
	}
	cout << cal();

	return 0;
}
