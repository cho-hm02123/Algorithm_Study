/* 마법사 상어와 복제  https://www.acmicpc.net/problem/23290
* 
* 문제: 4 x 4 격자, 가장 왼쪽 위는 (1, 1)
*	격자에 물고기가 M 마리, 각 물고기는 격자의 한 칸에 들어가 있으며 이동 방향을 가짐
*	이동방향: 상하좌우대각선 (8가지)
*	마법사 상어도 격자에 있음, 둘 이상의 물고기가 같은 칸에 있을 수도 있다. 마법사 상어와 일반 물고기가 같이 있을 수 있음
*	마법 연습은 순차적으로 이루어짐
*		1. 상어가 모든 물고기에 복제 마법 (이는 5번에서 발현 됨)
*		2. 모든 물고기가 한칸 이동. 상어가 있는칸, 물고기 냄새가 있는 칸, 격자를 벗어난 칸에는 이동 불가
*			각 물고기는 자신이 가지고 있는 이동 방향이 이동 가능한 칸을 향할 때 까지 45도 반시계 회전
*			이동 가능한 칸이 없으면 이동 안함. 그 외는 해당 칸으로 이동
*		3. 상어가 연속해서 3칸 이동.
*			상어는 현재 칸에서 상하좌우로 인접한 칸으로 이동 가능 (연속해서 이동하는 칸 중 범위를 벗어나는 칸이 있으면 해당 방법은 불가능)
*			이동 도중 물고기가 있으면 그 칸에 있는 물고기는 모두 삭제되고 냄새를 남김
*			이동 방법이 여려개면 물고기가 많은 방법으로 이동, 이게 여러가지면 사전 순으로 가장 앞서는 방법
*		4. 두 번 전 연습에서 생긴 물고기의 냄새는 격자에서 사라짐
*		5. 1에서 복제한 마법이 완료, 모든 복제된 물고기는 1에서의 위치와 방향을 그대로 가짐
* 
*	격자에 있는 물고기의 위치, 방향 정보, 상어의 위치, 연습횟수 S가 주어질 때 격자에 있는 물고기의 수
* 
* 입력: 물고기의 수 M, 연습 횟수 S, 물고기의 정보 f_x, f_y, d, 상어의 위치 (s_x, s_y)
* 
* 출력: s번 연습을 마친 후 물고기의 수
* 
* 풀이: 상어 시작점은 먹지 않음 ex) 시작점 > 첫 번째 이동 칸 > 두 번째 이동 칸 > 세 번째 이동 칸
*	나머지 사항은 아래 주석
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second
#define LL long long

int m, s, sx, sy;
int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dsx[4] = { -1, 0, 1, 0 };
int dsy[4] = { 0, -1, 0, 1 };
LL arr[5][5][9];
int smell[5][5];

bool JudeFish(int x, int y) {
	if (x < 1 || y < 1 || x > 4 || y > 4 || smell[x][y] > 0 || (x == sx && y == sy)) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> s;
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		arr[x][y][d]++;
		arr[x][y][0]++;
	}
	cin >> sx >> sy;

	while (s--) {
		LL cp[5][5][9] = {0,};

		// 복제 마법 및 물고기 이동
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				for (int k = 1; k <= 8; k++) {
					if (arr[i][j][k] == 0) continue;
					int x = i, y = j, vec = k + 1;
					bool flag = 0;

					for (int d = 0; d <= 7; d++) {
						vec --;
						if (vec == 0) vec = 8;
						if (JudeFish(x + dx[vec], y + dy[vec])) continue;
						x += dx[vec];
						y += dy[vec];
						break;
					}
					if (x == i && y == j) vec = k;		// 여기서 예외처리를 안해줘서 틀림 (위에서 vec = k + 1 로 선언했으므로 물고기가 이동하지 않을 때 방향을 k로 유지시켜줘야 함)
					cp[x][y][vec] += arr[i][j][k];
					cp[x][y][0] += arr[i][j][k];
				}

		// 상어의 이동
		LL maxsum = -1;		// 먹은 물고기 수가 0인 경우가 있을 수 있으니 최소는 -1로 잡아야 함
		int soon[3] = { 0, };
		for (int i = 0; i < 4; i++) {
			LL sum1 = 0;
			int x = sx + dsx[i];
			int y = sy + dsy[i];
			if (x < 1 || y < 1 || x > 4 || y > 4) continue;
			sum1 += cp[x][y][0];

			for (int j = 0; j < 4; j++) {
				LL sum2 = sum1;
				int xx = x + dsx[j];
				int yy = y + dsy[j];
				if (xx < 1 || yy < 1 || xx > 4 || yy > 4) continue;
				sum2 += cp[xx][yy][0];

				for (int k = 0; k < 4; k++) {
					LL sum3 = sum2;			// sum과 좌표를 무식하게 i 루프에 누적하면 값이 달라지므로 for문 마다 초기화
					int xxx = xx + dsx[k];
					int yyy = yy + dsy[k];
					if (xxx < 1 || yyy < 1 || xxx > 4 || yyy > 4) continue;
					if (abs(j - k) != 2) sum3 += cp[xxx][yyy][0];		// 시작점 물고기를 먹지 않으므로 돌아왔을 때 물고기 수 카운트 안하는건 마지막만

					if (sum3 > maxsum) {
						soon[0] = i;
						soon[1] = j;
						soon[2] = k;
						maxsum = sum3;
					}
				}
			}
		}
		queue <pair<int, int>> q;
		for (int i = 0; i < 3; i++) {
			sx += dsx[soon[i]];
			sy += dsy[soon[i]];

			if (cp[sx][sy][0] > 0) {
				for (int j = 0; j <= 8; j++) cp[sx][sy][j] = 0;
				q.push({ sx, sy });
			}
		}

		// 두 번 전 연습에서 생긴 물고기 냄새가 격자에서 사라짐 및 냄새 업데이트
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				if (smell[i][j] > 0) smell[i][j]--;
		while (!q.empty()) {
			smell[q.front().X][q.front().Y] = 2;
			q.pop();
		}

		// 복제 마법 완료
		for(int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++) {
				if (cp[i][j][0] == 0) continue;
				for (int k = 0; k <= 8; k++)
					 arr[i][j][k] += cp[i][j][k];
			}
	}

	LL sum = 0;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			sum += arr[i][j][0];

	cout << "\n"<<sum;

	return 0;
}
