#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <tuple>

using namespace std;

#define X first
#define Y second

struct Santa {
	int id, state;

	bool operator <(const Santa &b) const {
		return id > b.id;
	}
};

int n, m, p, c, d, rx, ry;
int dxr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dyr[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dxs[4] = { -1, 0, 1, 0 };
int dys[4] = { 0, 1, 0, -1 };
int ip[32];
int score[32];
int gi[32];
priority_queue <Santa> pq;
pair <int, int> point[32];
map <int, int> id_to_i;
int fig[51][51];
char hor = 'r';
char hos = 's';

void figset() {
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
			fig[i][j] = 0;
	for (int i = 0; i < p; i++)
		fig[point[i].X][point[i].Y] = ip[i];
	fig[rx][ry] = 33;
}

int cc() {
	int minlen = 6000;
	int ii = 31;
	for (int i = 0; i < p; i++) {
		if (point[i].X == 0) continue;
		int len = (rx - point[i].X) * (rx - point[i].X) + (ry - point[i].Y) * (ry - point[i].Y);
		if (len < minlen) {
			ii = i;
			minlen = len;
		}
		else if (len == minlen) {
			if (point[i].X > point[ii].X)
				ii = i;
			else if (point[i].X == point[ii].X)
				if (point[i].Y > point[ii].Y)
					ii = i;
		}
	}
	return ii;
} // 루돌푸가 돌진할 산타 찾

void ho(int x, int y, int u, int h, char ch) {
	if (ch == 'r') {
		int dx = x + h*dxr[u];
		int dy = y + h*dyr[u];

		if (dx < 1 || dy < 1 || dx > n || dy > n) {
			point[id_to_i[fig[x][y]]] = make_pair(0, 0);
			return;
		}
		if (fig[dx][dy] == 0) {
			point[id_to_i[fig[x][y]]] = make_pair(dx, dy);
			return;
		}
		if (fig[dx][dy] > 0) {
			ho(dx, dy, u, 1, ch);
			point[id_to_i[fig[x][y]]] = make_pair(dx, dy);
			return;
		}
	}
	else if (ch == 's') {
		int dx = x - h * dxs[u];
		int dy = y - h * dys[u];

		if (dx < 1 || dy < 1 || dx > n || dy > n) {
			point[id_to_i[fig[x][y]]] = make_pair(0, 0);
			fig[x][y] = 0;
			return;
		}
		if (fig[dx][dy] == 0) {
			point[id_to_i[fig[x][y]]] = make_pair(dx, dy);
			fig[dx][dy] = fig[x][y];
			fig[x][y] = 0;
			return;
		}
		if (fig[dx][dy] > 0 && fig[dx][dy] != fig[x][y]) {
			ho(dx, dy, u, 1, ch);
			point[id_to_i[fig[x][y]]] = make_pair(dx, dy);
			fig[dx][dy] = fig[x][y];
			fig[x][y] = 0;
			return;
		}
	}
}

void sanmove() {
	int ii = 0;
	for (int i = 0; i < p; i++) {
		if (point[i].X == 0) continue;
		if (gi[i] > 0) {
			gi[i]--;
			continue;
		}
		Santa new_s;
		new_s.id = ip[i];
		new_s.state = gi[i];

		pq.push(new_s);
	}

	while (!pq.empty()) {
		Santa cur_s = pq.top(); pq.pop();
		int u = id_to_i[cur_s.id];
		int sx = point[u].X, sy = point[u].Y;
		if (point[u].X == 0) continue;

		int minlen = (point[u].X - rx) * (point[u].X - rx) + (point[u].Y - ry) * (point[u].Y - ry);
		for (int i = 0; i < 4; i++) {
			int dx = point[u].X + dxs[i];
			int dy = point[u].Y + dys[i];

			if (dx < 1 || dy < 1 || dx > n || dy > n || (fig[dx][dy] > 0 && fig[dx][dy] < 31)) continue;
			int len = (dx - rx) * (dx - rx) + (dy - ry) * (dy - ry);

			if (len < minlen) {
				minlen = len;
				sx = dx;
				sy = dy;
				ii = i;
			}
		}

		if (sx == point[u].X && sy == point[u].Y) continue;

		if (fig[sx][sy] == 0) {
			fig[point[u].X][point[u].Y] = 0;
			point[u].X = sx;
			point[u].Y = sy;
			fig[sx][sy] = ip[u];
			continue;
		}
		else if (fig[sx][sy] == 33) {
			gi[u] = 1;
			score[u] += d;
			ho(point[u].X, point[u].Y, ii, d-1, hos);
		}
	}

	for (int i = 0; i < p; i++) {
		if (point[i].X == 0) continue;
		score[i]++;
	}
	figset();
}

void romove() {
	int ii = cc();
	int u = 0;
	int minlen = (rx - point[ii].X) * (rx - point[ii].X) + (ry - point[ii].Y) * (ry - point[ii].Y);
	int sx = 0, sy = 0;
	if (ii == 31) {
		m = 0;
		return;
	}
	else {
		for (int i = 0; i < 8; i++) {
			int dx = rx + dxr[i];
			int dy = ry + dyr[i];

			if (dx < 1 || dy < 1 || dx > n || dy > n) continue;
			int len = (dx - point[ii].X) * (dx - point[ii].X) + (dy - point[ii].Y) * (dy - point[ii].Y);
			if (len < minlen) {
				minlen = len;
				sx = dx;
				sy = dy;
				u = i;
			}
		}
	}
	fig[rx][ry] = 0;
	rx = sx;
	ry = sy;
	if (fig[rx][ry] == 0)
		fig[rx][ry] = 33;
	else if (fig[rx][ry] > 0) {
		score[id_to_i[fig[rx][ry]]] += c;
		gi[id_to_i[fig[rx][ry]]]=2;
		ho(rx, ry, u, c, hor);
	}
	figset();
	sanmove();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> p >> c >> d;

	cin >> rx >> ry;
	fig[rx][ry] = 33;

	for (int i = 0; i < p; i++) {
		int idx, a, b;
		cin >> idx >> a >> b;
		fig[a][b] = idx;
		ip[i] = idx;
		id_to_i[idx] = i;
		point[i] = make_pair(a, b);
	}

	while (m--)
		romove();

	for (int i = 0; i < p; i++) {
		Santa new_s;
		new_s.id = ip[i];
		new_s.state = gi[i];

		pq.push(new_s);
	}

	for (int i = 0; i < p; i++) {
		cout << score[id_to_i[pq.top().id]]<<" ";
		pq.pop();
	}

	return 0;
}
