/*
* 총 톱니가 8개 달린 톱니바퀴 4개가 일렬로 나열
* 톱니는 N / S 극 중 하나
* 톱니바퀴에 번호가 메겨져 있음 가장 왼쪽부터 1번
* 톱니바퀴를 총 k번 회전시킬 때(시계 / 반시계) 옆 톱니바퀴의 톱니 극성이 다르면 다른 방향으로, 같으면 회전하지 않음
* 
* 입력 : 1번 톱니바퀴 상태
*		 2번 톱니바퀴 상태
*		 3번 ""
*		 4번 ""				-> 12시 방향부터 시계방향 순서대로 주어짐
*		 N극은 0 / S극은 1
*		 회전 수 k
*		 k 줄에 걸쳐 회전시킬 방법이 주어짐 (회전시킬 톱니 번호 / 1 : 시계 , -1 : 반시계)
* 
* 출력 : K번 회전한 후 점수를 계산하여 점수 출력
*			-> 1번 톱니바퀴의 12시 방향이 N극이면 0, S극이면 1점
*			-> 2번 ""										 2점
*			-> 3번 ""										 4점
*			-> 4번 ""										 8점
* 
* 풀이 : 닿는 톱니 : 3번 / 7번
*		 해당 톱니 양옆 조사 후 한번에 돌려야 함
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int k;
char arr[5][9];
int dx[2] = { -1, 1 };
int sc[5] = { 0, 1, 2, 4, 8 };
double score;

void rot(int num, int vec) {
	if (vec == 1) { // 시계방향 회전
		char temp = arr[num][8];
		for (int i = 8; i > 1; i--) {
			arr[num][i] = arr[num][i - 1];
		}
		arr[num][1] = temp;
	}
	else { // 반시계 방향 회전
		char temp = arr[num][1];
		for (int i = 1; i < 8; i++) {
			arr[num][i] = arr[num][i + 1];
		}
		arr[num][8] = temp;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i < 5; i++)
		for (int j = 1; j < 9; j++)
			cin >> arr[i][j];
	cin >> k;

	while (k--) {
		int num, vec;
		cin >> num >> vec;

		bool flag[5] = { 0, };
		
		queue <pair<int, int>> q;
		queue <pair<int, int>> qq;
		q.push({ num, vec });
		qq.push({ num,vec });
		flag[num] = 1;

		while (!q.empty()) {
			pair <int, int> cur = q.front(); q.pop();

			for (int i = 0; i < 2; i++) {
				int x = cur.X + dx[i];

				if (x < 1 || x > 4 || flag[x]) continue;

				if (i == 0) {
					if (arr[cur.X][7] != arr[x][3]) {
						q.push({ x, cur.Y * -1 });
						qq.push({ x, cur.Y * -1 });
						flag[x] = 1;
					}
				}
				else {
					if (arr[cur.X][3] != arr[x][7]) {
						q.push({ x, cur.Y * -1 });
						qq.push({ x, cur.Y * -1 });
						flag[x] = 1;
					}
				}
			}
		}

		while (!qq.empty()) {
			pair<int, int> cur = qq.front(); qq.pop();
			rot(cur.X, cur.Y);
		}
	}

	for (int i = 1; i < 5; i++) {
		if (arr[i][1] == '1')
			score += sc[i];
	}

	cout << score;

	return 0;
}
