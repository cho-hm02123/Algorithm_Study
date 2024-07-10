/*
1. 섬의 외곽 좌표 구하기
2. 섬들 외곽좌표 차 가장 작은거 구하기
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

int n;
int arr[101][101];
bool flag[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector <pair <int, int>> v[10000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	int k = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0 || flag[i][j] == 1) continue;

			queue <pair<int, int>> q;
			q.push({ i,j });
			flag[i][j] = 1;

			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();

				int check = 0;
				for (int h = 0; h < 4; h++) {
					int x = cur.X + dx[h];
					int y = cur.Y + dy[h];

					if (x < 0 || y < 0 || x > n - 1 || y > n - 1 || flag[x][y]) continue;
					if (arr[x][y] == 0 && check == 0) {
						v[k].push_back({ cur.X,cur.Y });
						check = 1;
					}
					else if (arr[x][y] == 1) {
						q.push({ x,y });
						flag[x][y] = 1;
					}
				}
			}
			k++;
		}

	int mm = 0x7fffffff;
	for(int i = 0; i < k+1; i++)
		for (int j = i+1; j < k + 1; j++) {
			for (int ii = 0; ii < v[i].size(); ii++)
				for (int jj = 0; jj < v[j].size(); jj++)
					mm = min(mm, abs(v[i][ii].X - v[j][jj].X) + abs(v[i][ii].Y - v[j][jj].Y));
		}

	cout << mm-1;

	return 0;
}
