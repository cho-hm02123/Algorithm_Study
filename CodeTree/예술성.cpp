#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

int n, sum;
int fig[30][30];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue <pair<int, int>> q;

void turn() {
	int cfig[30][30];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cfig[i][j] = fig[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == n / 2)
				fig[i][j] = cfig[j][n / 2];
			else if (j == n / 2)
				fig[i][j] = cfig[n / 2][n - 1 - i];
			else if (i < n / 2 && j < n / 2)
				fig[i][j] = cfig[n / 2 - 1 - j][i];
			else if (i < n / 2 && j > n / 2)
				fig[i][j] = cfig[n - 1 - j][i + 1 + n / 2];
			else if (i > n / 2 && j < n / 2)
				fig[i][j] = cfig[n - 1 - j][i - n / 2 - 1];
			else
				fig[i][j] = cfig[n + n / 2 - j][i];
		}
}

void cal() {
	int flag[30][30] = { 0, };
	int in[900][900] = { 0, };
	int gab[900] = { 0, };
	int can[900] = { 0, };
	int num;
	int cnt = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (!(flag[i][j])) {
				q.push({ i,j });
				gab[cnt] = fig[i][j];
				flag[i][j] = cnt;
				num = 1;
			}

			while (!q.empty()) {
				pair <int, int> cur = q.front(); q.pop();
				for (int h = 0; h < 4; h++) {
					int x = dx[h] + cur.X;
					int y = dy[h] + cur.Y;

					if (x < 0 || y < 0 || x > n - 1 || y > n - 1) continue;
					if (flag[x][y] == 0 && fig[cur.X][cur.Y] == fig[x][y]) {
						q.push({ x,y });
						flag[x][y] = cnt;
						num++;
					}
					else if (flag[x][y] != 0)
						in[flag[x][y]][cnt]++;
				}

			}
			can[cnt] = num;
			cnt++;
		}

	for (int a = 1; a < cnt; a++)
		for (int b = 1; b < cnt; b++) {
			if (a >= b) continue;
			sum += (can[a] + can[b]) * gab[a] * gab[b] * in[a][b];
		}

	turn();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> fig[i][j];

	for (int i = 0; i < 4; i++)
		cal();

	cout << sum;

	return 0;
}
