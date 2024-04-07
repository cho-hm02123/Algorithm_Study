#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define X first
#define Y second

int n, m, k, ex, ey;
int fig[11][11];
vector <pair<int,int>> v;
int cnt, num, sz;

void turn() {
	int cfig[11][11];
	int ccfig[11][11];
	int flag[11][11];
	int ch = -1;
	int mm = 1000;
	int x = -1, y = -1;
	int cx = 11, cy = 11;
	vector <pair<int, int>> cv;

	for (int check = 0; check < v.size(); check++) {
		int a = 0;
		if (abs(v[check].X - ex) >= abs(v[check].Y - ey))
			a = abs(v[check].X - ex) + 1;
		else
			a = abs(v[check].Y - ey) + 1;

		if (a < mm) {
			mm = a;
			if (v[check].X >= ex) {
				if (v[check].X - ex == mm - 1)
					x = ex;
				else {
					if (v[check].X <= mm - 1)
						x = 0;
					else if (v[check].X > mm - 1)
						x = v[check].X - mm + 1;
				}
			}

			if (v[check].X < ex) {
				if (ex - v[check].X == mm - 1)
					x = v[check].X;
				else {
					if (ex <= mm - 1)
						x = 0;
					else if (ex > mm - 1)
						x = ex - mm + 1;
				}
			}

			if (v[check].Y >= ey) {
				if (v[check].Y - ey == mm - 1)
					y = ey;
				else {
					if (v[check].Y <= mm - 1)
						y = 0;
					else if (v[check].Y > mm - 1)
						y = v[check].Y - mm + 1;
				}
			}

			if (v[check].Y < ey) {
				if (ey - v[check].Y == mm - 1)
					y = v[check].Y;
				else {
					if (ey <= mm - 1)
						y = 0;
					else if (ey > mm - 1)
						y = ey - mm + 1;
				}
			}
		}
		
		else if (a == mm) {
			if (v[check].X >= ex) {
				if (v[check].X - ex == mm - 1)
					cx = ex;
				else {
					if (v[check].X <= mm - 1)
						cx = 0;
					else if (v[check].X > mm - 1)
						cx = v[check].X - mm + 1;
				}
			}

			if (v[check].X < ex) {
				if (ex - v[check].X == mm - 1)
					cx = v[check].X;
				else {
					if (ex <= mm - 1)
						cx = 0;
					else if (ex > mm - 1)
						cx = ex - mm + 1;
				}
			}

			if (v[check].Y >= ey) {
				if (v[check].Y - ey == mm - 1)
					cy = ey;
				else {
					if (v[check].Y <= mm - 1)
						cy = 0;
					else if (v[check].Y > mm - 1)
						cy = v[check].Y - mm + 1;
				}
			}

			if (v[check].Y < ey) {
				if (ey - v[check].Y == mm - 1)
					cy = v[check].Y;
				else {
					if (ey <= mm - 1)
						cy = 0;
					else if (ey > mm - 1)
						cy = ey - mm + 1;
				}
			}

			if (x > cx) {
				x = cx;
				y = cy;
			}
			else if (x == cx) {
				if (y >= cy) {
					x = cx;
					y = cy;
				}
			}
		}
	}

	for (int i = x; i < x + mm; i++)
		for (int j = y; j < y + mm; j++) {
			cfig[i - x][j - y] = fig[i][j];
			ccfig[i - x][j - y] = cfig[i - x][j - y];
		}

	for (int i = 0; i < mm; i++)
		for (int j = 0; j < mm; j++)
			cfig[i][j] = ccfig[mm - 1 - j][i];

	for (int h = 0; h < v.size(); h++) {
		int xx = v[h].X;
		int yy = v[h].Y;

		if (x <= xx && xx < x + mm && y <= yy && yy < y + mm)
			cv.push_back({ yy - y + x, mm - xx + x - 1 + y });
		else
			cv.push_back({ xx,yy });
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (x <= i && i < x + mm && y <= j && j < y + mm) {
				fig[i][j] = cfig[i - x][j - y];
				if (fig[i][j] > 0)
					fig[i][j]--;
			}
			if (fig[i][j] == -1) {
				ex = i;
				ey = j;
			}
		}
	v.clear();
	v.resize((int)(cv.size()));
	copy(cv.begin(), cv.end(), v.begin());
	cnt++;
}

void cal() {
	vector <pair<int, int>> cv;

	for (int i = 0; i < v.size(); i++) {
		if (ex == v[i].X) {
			if (ey > v[i].Y) {
				if (fig[ex][v[i].Y + 1] <= 0) {
					num++;
					if (v[i].Y +1 == ey)
						fig[v[i].X][v[i].Y] = 0;
					else {
						fig[v[i].X][v[i].Y] = 0;
						fig[v[i].X][v[i].Y+1] = -2;
						cv.push_back({ v[i].X,v[i].Y + 1 });
					}
				}
				else
					cv.push_back({ v[i].X, v[i].Y });
			}
			else {
				if (fig[ex][v[i].Y - 1] <= 0) {
					num++;
					if (v[i].Y - 1 == ey)
						fig[v[i].X][v[i].Y] = 0;
					else {
						fig[v[i].X][v[i].Y] = 0;
						fig[v[i].X][v[i].Y - 1] = -2;
						cv.push_back({ v[i].X,v[i].Y - 1 });
					}
				}
				else
					cv.push_back({ v[i].X, v[i].Y });
			}
		}

		else if (ey == v[i].Y) {
			if (ex > v[i].X) {
				if (fig[v[i].X + 1][ey] <= 0) {
					num++;
					if (v[i].X + 1 == ex)
						fig[v[i].X][v[i].Y] = 0;
					else {
						fig[v[i].X][v[i].Y] = 0;
						fig[v[i].X + 1][v[i].Y] = -2;
						cv.push_back({ v[i].X + 1,v[i].Y });
					}
				}
				else
					cv.push_back({ v[i].X, v[i].Y });
			}
			else {
				if (fig[v[i].X - 1][ey] <= 0) {
					num++;
					if (v[i].X - 1 == ex)
						fig[v[i].X][v[i].Y] = 0;
					else {
						fig[v[i].X][v[i].Y] = 0;
						fig[v[i].X - 1][v[i].Y] = -2;
						cv.push_back({ v[i].X - 1,v[i].Y });
					}
				}
				else
					cv.push_back({ v[i].X, v[i].Y });
			}
		}

		else if (ex > v[i].X && ey > v[i].Y) {
			if (fig[v[i].X + 1][v[i].Y] <= 0) {
				fig[v[i].X][v[i].Y] = 0;
				fig[v[i].X + 1][v[i].Y] = -2;
				num++;
				cv.push_back({ v[i].X + 1 , v[i].Y });
			}
			else if(fig[v[i].X][v[i].Y+1] <= 0) {
				fig[v[i].X][v[i].Y] = 0;
				fig[v[i].X][v[i].Y+1] = -2;
				num++;
				cv.push_back({ v[i].X , v[i].Y +1});
			}
			else
				cv.push_back({ v[i].X , v[i].Y});
		}

		else if (ex > v[i].X && ey < v[i].Y) {
			if (fig[v[i].X + 1][v[i].Y] <= 0) {
				fig[v[i].X][v[i].Y] = 0;
				fig[v[i].X + 1][v[i].Y] = -2;
				num++;
				cv.push_back({ v[i].X + 1 , v[i].Y });
			}
			else if (fig[v[i].X][v[i].Y - 1] <= 0) {
				fig[v[i].X][v[i].Y] = 0;
				fig[v[i].X][v[i].Y - 1] = -2;
				num++;
				cv.push_back({ v[i].X , v[i].Y - 1 });
			}
			else
				cv.push_back({ v[i].X , v[i].Y });
		}

		else if (ex < v[i].X && ey > v[i].Y) {
			if (fig[v[i].X - 1][v[i].Y] <= 0) {
				fig[v[i].X][v[i].Y] = 0;
				fig[v[i].X - 1][v[i].Y] = -2;
				num++;
				cv.push_back({ v[i].X - 1 , v[i].Y });
			}
			else if (fig[v[i].X][v[i].Y + 1] <= 0) {
				fig[v[i].X][v[i].Y] = 0;
				fig[v[i].X][v[i].Y + 1] = -2;
				num++;
				cv.push_back({ v[i].X , v[i].Y + 1 });
			}
			else
				cv.push_back({ v[i].X , v[i].Y });
		}

		else if (ex < v[i].X && ey < v[i].Y) {
		if (fig[v[i].X - 1][v[i].Y] <= 0) {
			fig[v[i].X][v[i].Y] = 0;
			fig[v[i].X - 1][v[i].Y] = -2;
			num++;
			cv.push_back({ v[i].X - 1 , v[i].Y });
		}
		else if (fig[v[i].X][v[i].Y - 1] <= 0) {
			fig[v[i].X][v[i].Y] = 0;
			fig[v[i].X][v[i].Y - 1] = -2;
			num++;
			cv.push_back({ v[i].X , v[i].Y - 1 });
		}
		else
			cv.push_back({ v[i].X , v[i].Y });
		}
	}

	v.clear();
	v.resize((int)(cv.size()));
	copy(cv.begin(), cv.end(), v.begin());

	if(!v.empty())
		turn();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> k;
	sz = m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> fig[i][j];

	for (int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		fig[a - 1][b - 1] = -2;
		v.push_back({ a-1,b-1 });
	}

	cin >> ex >> ey;
	ex--; ey--;
	fig[ex][ey] = -1;

	while (1) {
		if (v.empty() || cnt == k)
			break;
		cal();
	}

	cout << num << "\n" << ex + 1 << " " << ey + 1;

	return 0;
}
