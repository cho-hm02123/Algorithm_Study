/* https://www.acmicpc.net/problem/20057 마법사 상어와 토네이도 
* 
*  1h 44m 01s 
*  아 잘 풀어놓고 while문 조건 이상하게 해서 디버깅 오래걸렸네
* 
* 문제: NxN 격자, 위치는 (r, c)이고 r = x, c = y, A[r][c]는 (r,c)에 있는 모래의 양
*	토네이토를 시전하면 격자의 중앙부터 토네이도 이동이 시작 -> 토네이도는 한 번에 한 칸 움직임
* 
*	이동
*		토네이도가 한 칸 이동할 때 모래의 양은 일정한 비율로 흩날림
*			ex) 토네이도가 (3,4) -> (3,3)으로 이동하면 (3,3)에 있던 모든 모래가 (3,2)로 이동
*			이때 칸에 적힌 비율만큼 모래가 해당 칸으로 이동(소수점은 버림) 즉, (3,2)에는 흩날리지 않고 남은 모래만 이동한다.
*			모래가 이미 있는 칸으로 이동하면 모래의 양은 더해짐
*		토네이도는 (1,1)에 도달하면 소멸
* 
* 
*	이동 방향
*		이동 방향이 달라지면 설명 모양을 해당 방향으로 회전하면 된다는게 무슨 말이니....
* 
*	모래는 격자 밖으로 나갈 수 있으며 이때 격자 밖으로 나간 모래 양 구하기
* 
* 입력: 격자 크기 N, 격자의 모래 양
* 
* 출력: 격자 밖으로 나간 모래의 양
* 
* 풀이: 토네이토가 계속 돌게 하는 것과 흩날리는 퍼센트 불러오는게 관건
*	계속 돌게 하는건 flag를 이용해 해결 방향을 바꾸려면 방향을 바꾸고 이동하는 곳이 방문하지 않은 곳이어야 한다.
*	퍼센트는 그냥 방향별로 배열에 때려 넣고 가져다가 씀
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct tornado {
	int x, y, d;
};

int n; // 3 <= N <=499
int ans; // 밖으로 나간 모래
int A[501][501];
bool flag[501][501];
int dx[4] = { 0, 1, 0, -1 }; // 좌 하 우 상
int dy[4] = { -1, 0, 1, 0 };
int sand_x[4][9] = { {-1, 1, -2, 2, -1, 1, -1, 1, 0},
		     {-1, -1, 0, 0, 0, 0, 1, 1, 2},
		     {-1, 1, -2, 2, -1, 1, -1, 1, 0},
		     {1, 1, 0, 0, 0, 0, -1, -1, -2} };

int sand_y[4][9] = { {1, 1, 0, 0, 0, 0, -1, -1, -2},
		     {-1, 1, -2, 2, -1, 1, -1, 1, 0},
		     {-1, -1, 0, 0, 0, 0, 1, 1, 2},
		     {-1, 1, -2, 2, -1, 1, -1, 1, 0} };

int sand[9] = { 1, 1, 2, 2, 7, 7, 10, 10, 5 };
tornado cur;

void MoveTornado() {
	int x = cur.x + dx[cur.d];
	int y = cur.y + dy[cur.d];
	int msand = A[x][y];		// 토네이도가 간 칸의 모래 양
	A[x][y] = 0;

	int ssum = 0;	// 흩날린 모래 양
	for (int i = 0; i < 9; i++) {
		int wins = msand * sand[i] / 100;
		ssum += wins;
		int nx = x + sand_x[cur.d][i];
		int ny = y + sand_y[cur.d][i];

		if (nx < 1 || ny < 1 || nx > n || ny > n) ans += wins;
		else A[nx][ny] += wins;
	}

	msand -= ssum;
	int nx = x + dx[cur.d];
	int ny = y + dy[cur.d];
	if (nx < 1 || ny < 1 || nx > n || ny > n) ans += msand;
	else A[nx][ny] += msand;
	
	cur.x = x;
	cur.y = y;
	flag[cur.x][cur.y] = 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	
	cur.x = n / 2 + 1;
	cur.y = cur.x;
	cur.d = 0;
	flag[cur.x][cur.y] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> A[i][j];

	while (cur.x != 1 || cur.y != 1) {
		MoveTornado();
		int next_d = (cur.d + 1) % 4;
		if (flag[cur.x + dx[next_d]][cur.y + dy[next_d]]) continue; // 방향 아직 바꿀 때 안됐으면
		else
			cur.d = next_d;
	}

	cout << ans;
	return 0;
}
