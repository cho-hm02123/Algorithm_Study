/* https://www.acmicpc.net/problem/14502
* 
* 42m 43s
* 
* 문제: 연구소 크기 : N x M, 빈칸, 벽으로 이루어져 있음
*		일부 칸엔 바이러스가 존재, 바이러스는 상하좌우 인접한 '빈'칸으로 퍼져나갈 수 있음.
*		새로 세울 수 있는 벽은 3개, 꼭 3개 다 세워야 함
*		빈칸: 0 / 벽: 1/ 바이러스: 2
*		벽을 3개 세운 뒤 바이러스가 퍼질 수 없는 곳이 안전 영역
*		안전영역의 크기를 최대로 해야 함
* 
* 입력: 세로 N, 가로 M (8이하)
*		지도 모양
* 
* 출력: 안전 구역 최대 크기
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

int n, m, cnt;
int mm = -1;
int arr[9][9];
int num[3];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector <pair<int, int>> v;

void finds() {
	int rst = 0;
	int car[9][9];
	copy(&arr[0][0], &arr[0][0]+81, &car[0][0]);

	for (int i = 0; i < 3; i++)
		car[v[num[i]].X][v[num[i]].Y] = 1;

	bool flag[9][9] = { 0, };

	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (flag[i][j] || car[i][j] != 2) continue;

			queue <pair<int, int>> q;
			q.push({ i,j });
			flag[i][j] = 1;

			while (!q.empty()) {
				pair <int, int> cur = q.front(); q.pop();

				for (int h = 0; h < 4; h++) {
					int x = cur.X + dx[h];
					int y = cur.Y + dy[h];

					if (x < 0 || y < 0 || x > n - 1 || y > m - 1) continue;
					if (car[x][y] != 0 || flag[x][y]) continue;
					
					flag[x][y] = 1;
					car[x][y] = 2;
					q.push({ x,y });
					rst++;
				}
			}
		}

	mm = max(mm, cnt-rst);
}

void bc(int k) {
	if (k == 3) {
		finds();
		return;
	}

	int st = 0;
	if (k != 0)
		st = num[k - 1];
	for (int i = st; i < v.size(); i++) {
		if (k !=0 && num[k - 1] >= i) continue;
		num[k] = i;
		bc(k + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				v.push_back({ i,j });
				cnt++;
			}
		}

	cnt -= 3;
	bc(0);

	cout << mm;

	return 0;
}
