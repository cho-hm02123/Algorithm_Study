/* https://www.acmicpc.net/problem/19237 어른상어
* 
* 1h 40m 34s
* 
* 문제: 상어에 1이상 M 이하 번호 붙어있음 (번호는 서로 다르다)
*	1번 상어가 가장 강력 상어 다 쫓아낼 수 있음
*	NxX에 상어가 한 마리씩 들어있음
*	상어는 맨 처음 자기 위치에 냄새를 뿌리고, 이후 상하좌우 움직이며 냄새 뿌림 이때 냄새는 상어가 K번 이동하면 사라짐
* 
*	이동
*		1. 인접한 칸 중 아무 냄새가 없는 칸의 방향
*		2. 1이 없으면 자신의 냄새가 있는 칸
*		3. 여러개면 우선순위 따름 (우선순위는 상어마다 혹은 같은 상어라도 바라보는 방향에 따라 다름) -> 우선순위 입략으로 주어지나봄
*		
*	모든 상어가 이동한 후 한 칸에 상어 여러마리 있으면 가장 번호가 작은 상어만 남기고 모두 사라짐
*	이때 1번 상어만 격자에 남을 떄 까지 걸린 시간
* 
* 입력: N, M(상어개수), K(냄새 사라지는거)
*	격자 모습 주어짐 0은 빈칸 0이 아닌 수는 해당 번호 상어가 있음
*	상어 방향이 번호 순으로 1-위 2-아래 3-왼 4-오
*	상어 별 우선순위 4줄 씩 첫줄: 위 방향일 때 둘줄: 아래 셋줄: 왼 넷줄: 오른
* 
* 출력: 1번 상어만 남게 될 때 까지 걸린 시간 만약 1000초 넘어도 안되면 -1 출력
* 
* 풀이: struct에 상어 좌표, 방향, 우선순위 만들어주고 해당 struct로 상어 마리수 만큼 배열 인덱스 할당
*	방출 상어는 x,y 좌표를 0,0으로 해서 걸러줌
*	arr의 X에 냄새 넣은 상어 번호, Y에 냄새 남은 유지 시간 저장
*	냄새 싸기 -> 이동 -> 방출 -> 냄새 시간 줄이기 순으로 돌아가도록 작성
*	방출은 어차피 큐에 번호 작은 순으로 들어가니까 sha배열 맵 만들어서 이전에 해당 좌표에 상어가 들렸으면 늦게 들린 상어 없어지게 함
*	
*	주의 : 1000초 초과 즉 1000초 까진 괜찮고 1001초부터 -1 출력이므로 while문이 1001초일 때 멈추고 -1 리턴해야 함
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

struct sh {
	int x, y, d, pri[5][4];
};

int n, m, k, t;
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };
sh a[401];
pair <int, int> arr[21][21];

bool check(int x, int y) {
	if (x < 1 || y < 1 || x > n || y > n) return false;		// 여기 return false로 안써주고 false로 써줘서 찾는데 오래걸림 후... 바본가
	return true;
}

int cal() {
	while (t != 1001) {
		queue <int> q;
		for (int i = 1; i <= m; i++) {
			if (a[i].x == 0 && a[i].y == 0) continue;
			arr[a[i].x][a[i].y].Y = k;
			arr[a[i].x][a[i].y].X = i;
			q.push(i);
		}

		if (q.size() == 1)
			return t;

		bool sha[21][21] = { 0, };

		while (!q.empty()) {
			int num = q.front(); q.pop();
			int x = a[num].x;
			int y = a[num].y;
			int d = a[num].d;

			for (int i = 0; i < 4; i++) {
				int xx = x + dx[a[num].pri[d][i]];
				int yy = y + dy[a[num].pri[d][i]];

				if (check(xx, yy) && arr[xx][yy].Y == 0) {
					a[num].x = xx;
					a[num].y = yy;
					a[num].d = a[num].pri[d][i];
					break;
				}
			}

			if (a[num].x == x && a[num].y == y) {
				for (int i = 0; i < 4; i++) {
					int xx = x + dx[a[num].pri[d][i]];
					int yy = y + dy[a[num].pri[d][i]];

					if (check(xx, yy) && arr[xx][yy].X == num) {
						a[num].x = xx;
						a[num].y = yy;
						a[num].d = a[num].pri[d][i];
						break;
					}
				}
			}

			if (sha[a[num].x][a[num].y]) {
				a[num].x = 0;
				a[num].y = 0;
			}
			else
				sha[a[num].x][a[num].y] = 1;
		}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (arr[i][j].Y != 0) {
					arr[i][j].Y--;
					if (arr[i][j].Y == 0)
						arr[i][j].X = 0;
				}
			}

		t++;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int p;
			cin >> p;
			if (p != 0) {
				a[p].x = i;
				a[p].y = j;
			}
		}

	for (int i = 1; i <= m; i++)
		cin >> a[i].d;

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= 4; j++)
			for (int h = 0; h < 4; h++)
				cin >> a[i].pri[j][h];

	cout << cal();

	return 0;
}
