/* https://www.acmicpc.net/problem/9461 청소년상어 
* 
* 2h 12m 06s
*
* 문제: 4x4 크기 공간 x는 행, y는 열.
*	한 칸에 물고기 한 마리씩, 물고기는 번호와 방향을 가짐
*	번호는 1이상 16이하 자연수, 번호 중복은 없음
*	방향은 상하좌우대각선 8가지
*	상어는 (0,0)에 있는 물고기를 먹고 해당 위치로 가서 시작
*	상어의 방향은 (0,0)에 있던 물고기의 방향과 동일
*
*	이후 물고기가 이동
*		물고기는 번호가 작은 애 부도 이동 1칸씩 이동할 수 있음
*		빈칸인거나 다른 물고기가 있는 칸 이동 가능
*		상어가 있거나 맵 범위 넘으면 이동 못함
*		이동할 수 있는 칸이 나올 때 까지 45도 반 시계로 회전
*		다른 물고기가 있는 칸으로 이동하면 자리를 바꿈
*
*	물고기의 이동이 끝나면 상어가 이동
*		방향에 있는 칸으로 이동 가능, 한번에 여러칸 갈 수 있음
*		물고기가 있는 칸으로 가면 물고기를 먹고, 해당 물고기의 방향을 가짐
*		이동하는 중에 있는 칸의 물고기는 안먹음
*		물고기가 없는 칸으로는 이동할 수 없음
*		이동할 수 없으면 종료
*
*	상어 이동 후엔 물고기가 이동하며 위를 반복
*	상어가 먹을 수 있는 물고기 번호의 합의 최대
*
* 입력: 물고기 정보 a(물고기 번호), b(방향) (1: 상, 2: 좌상, 3: 좌, 4: 좌하, 5: 하, 6: 우하, 7: 우, 8: 우상)
*
* 출력: 상어가 먹을 수 있는 물고기 번호 합의 최대
* 
* 풀이: struct fi 생성 여기 x, y, 방향을 담을 수 있게
*	fi f[18]에 인덱스 번호와 물고기 번호 맞춰서 좌표 및 방향 저장, 이때 상어는 17번
*	arr에 상어 번호 저장 -> 맵임
*	모든 경우를 봐야 하므로 백트래킹 써야 함 따라서 전역으로 저장한건 건들지 않고 계속 지역으로 복사해서 계산해야 함
*	상어가 물고기 먹는 부분을 백트래킹으로 이때 최대 3가지 물고기를 먹는 경우 중 최대를 골라야 하므로 3번 도는 for문 안에서 max 검사
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct fi {
	int x, y, d;
};

int arr[4][4];
int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int sum;
fi f[18];

bool check(int x, int y) {
	if (x < 0 || x > 3 || y < 0 || y > 3) return true;
	return false;
}

int gofi(int board[4][4], fi cf[18]) {

	for (int i = 1; i <= 16; i++) {
		if (cf[i].d == 0) continue;

		while (1) {
			int x = cf[i].x + dx[cf[i].d];
			int y = cf[i].y + dy[cf[i].d];

			if (check(x, y) || x == cf[17].x && y == cf[17].y) {
				cf[i].d++;
				if (cf[i].d > 8)
					cf[i].d = 1;
				continue;
			}

			if (board[x][y] == 0) {
				board[x][y] = board[cf[i].x][cf[i].y];
				board[cf[i].x][cf[i].y] = 0;
				cf[i].x = x;
				cf[i].y = y;
				break;
			}
			else {
				int a = board[x][y];
				board[x][y] = board[cf[i].x][cf[i].y];
				cf[a].x = cf[i].x;
				cf[a].y = cf[i].y;
				board[cf[i].x][cf[i].y] = a;
				cf[i].x = x;
				cf[i].y = y;
				break;
			}
		}
	}

	int x = cf[17].x;
	int y = cf[17].y;
	int mm = 0;
	for (int i = 0; i < 3; i++) {
		x += dx[cf[17].d];
		y += dy[cf[17].d];

		if (check(x, y) || !board[x][y])
			continue;
		fi ccf[18];
		int cboard[4][4];

		copy(&cf[0], &cf[0] + 18, &ccf[0]);
		copy(&board[0][0], &board[0][0] + 16, &cboard[0][0]);

		int k = board[x][y];
		ccf[17].x = x;
		ccf[17].y = y;
		ccf[17].d = cf[board[x][y]].d;
		ccf[board[x][y]].d = 0;
		cboard[x][y] = 0;

		mm = max(mm, k + gofi(cboard, ccf));
	}
	return mm;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			if (i == 0 && j == 0) {
				f[17].x = i;
				f[17].y = j;
				f[17].d = b;
				sum = a;
				continue;
			}
			arr[i][j] = a;
			f[a].x = i;
			f[a].y = j;
			f[a].d = b;
		}

	cout << sum + gofi(arr, f);

	return 0;
}
