#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

#define X first
#define Y second

int N = 0, num = 0, b = 0;
char map[26][26];
int flag[26][26];
int dx[5] = { 0, 1, 0, -1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };
list <int> l;
deque <pair <int, int>> q;
pair <int, int> p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == '1') {
				q.push_back({ i, j });
			}
		}
	q.push_back({ N, N });

	while (!q.empty()) {
		pair <int, int> cur = q.front(); q.pop_front();
		if (flag[cur.X][cur.Y] == 0) {
			l.push_back(b);
			num++;
			b = 0;
			flag[cur.X][cur.Y] = 1;
		}
		
		for (int i = 0; i < 5; i++) {
			int x = cur.X + dx[i];
			int y = cur.Y + dy[i];

			if (x < 0 || y < 0 || x > N - 1 || y > N - 1 || flag[x][y] == 1) continue;
			if (map[x][y] == '1') {
				b++; 
				flag[x][y] = 1;
				q.push_front({ x,y });
			}
		}
	}

	l.sort();
	cout << num-1 << "\n";
	l.pop_front();

	while (!l.empty()) {
		cout << l.front() + 1 << "\n";
		l.pop_front();
	}
	return 0;
}
