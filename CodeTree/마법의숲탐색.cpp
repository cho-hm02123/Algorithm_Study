#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define X first
#define Y second

int R, C, k, d, cnt, m;
int fig[72][72]; // 우주선 위치에 우주선 번호 저장
int ex[1003]; // 우주선 번호 인덱스에 출구 인덱스 저장
vector<pair<int, int>> v; // 중심좌표 저장할거임
int score; // 점수 저장
int dxe[4] = { -1, 0, 1, 0 };
int dye[4] = { 0, 1, 0, -1 };  // 출구 위치 계산할거 0-위, 1-오, 2-아, 3-왼
pair <int, int> p; // 여기 처음 우주선 위치 받을거임

void save() {
	bool flag[1003] = { 0, };
	int x = p.X;
	int y = p.Y;
	int idx = fig[x][y]; // 우주선 번호
	int z = ex[idx]; // 우주선 출구
	m = x + 1; // 점수
	flag[idx] = 1;

	queue <pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		idx = fig[cur.X][cur.Y];
		z = ex[idx];
		int xe = cur.X + dxe[z];
		int ye = cur.Y + dye[z]; // 우주선 출구 좌표
		for (int i = 0; i < 4; i++) {
			int dx = xe + dxe[i];
			int dy = ye + dye[i];
			int didx = fig[dx][dy];

			if (dx > R || dy > C || dx < 1 || dy < 1 || didx == 0 || flag[didx] == 1) continue;
			int xx = v[didx].X;
			int yy = v[didx].Y; // 갈 우주선 중앙 좌표
			int mm = xx + 1;
			if (mm > m)
				m = mm;

			q.push({ xx, yy });
			flag[didx] = 1;
		}
	}
	score += m;
}

void gor() {
	int x = p.X;
	int y = p.Y;

	if (y == C - 1) {
		cnt = 0;
		return;
	}
	if (x == -1) {
		if (fig[x + 2][y + 1] == 0) {
			p = make_pair(x + 1, y + 1);
			if (d == 3)
				d = 0;
			else
				d++;
			cnt = 3;
		}
		else
			cnt = 0;
	}
	else if (x == 0) {
		if (fig[x + 1][y + 1] == 0 && fig[x + 1][y + 2] == 0 && fig[x + 2][y + 1] == 0) {
			p = make_pair(x + 1, y + 1);
			if (d == 3)
				d = 0;
			else
				d++;
			cnt = 3;
		}
		else
			cnt = 0;
	}
	else {
		if (fig[x - 1][y + 1] == 0 && fig[x][y + 2] == 0 && fig[x + 1][y + 1] == 0 && fig[x + 1][y + 2] == 0 && fig[x + 2][y + 1] == 0) {
			p = make_pair(x + 1, y + 1);
			if (d == 3)
				d = 0;
			else
				d++;
			cnt = 3;
		}
		else
			cnt = 0;
	}
}// 우주선 오른쪽 이동 cnt = 1

void gol() {
	int x = p.X;
	int y = p.Y;
	if (y == 2) {
		cnt = 1;
		return;
	}
	if (x == -1) {
		if (fig[x + 2][y - 1] == 0) {
			p = make_pair(x + 1, y - 1);
			if (d == 0)
				d = 3;
			else
				d--;
			cnt = 3;
		}
		else
			cnt = 1;
	}
	else if (x == 0) {
		if (fig[x + 1][y - 1] == 0 && fig[x + 1][y - 2] == 0 && fig[x + 2][y - 1] == 0) {
			p = make_pair(x + 1, y - 1);
			if (d == 0)
				d = 3;
			else
				d--;
			cnt = 3;
		}
		else
			cnt = 1;
	}
	else {
		if (fig[x - 1][y - 1] == 0 && fig[x][y - 2] == 0 && fig[x + 1][y - 1] == 0 && fig[x + 1][y - 2] == 0 && fig[x + 2][y - 1] == 0) {
			p = make_pair(x + 1, y - 1);
			if (d == 0)
				d = 3;
			else
				d--;
			cnt = 3;
		}
		else
			cnt = 1;
	}
}// 우주선 왼쪽이동 cnt = 2

void god() {
	int x = p.X;
	int y = p.Y;
	if (x == R - 1)
		cnt = 0;
	else if (fig[x + 2][y] == 0 && fig[x + 1][y - 1] == 0 && fig[x + 1][y + 1] == 0)
		p = make_pair(x + 1, y);
	else
		cnt = 2;
} //우주선 아래이동 cnt = 3

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> C >> k;
	v.push_back({ 0,0 });
	for (int i = 1; i < k + 1; i++) {
		int c;
		cnt = 3;
		cin >> c >> d;
		p = make_pair(-1, c);

		while (1) {
			if (cnt == 3)
				god();
			if (cnt == 2)
				gol();
			if (cnt == 1)
				gor();
			if (cnt == 0)
				break;
		}
		v.push_back({ p.X,p.Y });
		if (p.X < 2) {
			for (int h = 0; h < R + 1; h++)
				for (int j = 0; j < C + 1; j++)
					fig[h][j] = 0;
		}
		else {
			ex[i] = d;
			fig[p.X][p.Y] = i;
			for (int j = 0; j < 4; j++) {
				int x = p.X + dxe[j];
				int y = p.Y + dye[j];
				fig[x][y] = i;
			}
			save();
		}
	}
	cout << score;

	return 0;
}
