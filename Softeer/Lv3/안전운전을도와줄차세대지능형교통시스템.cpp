/* https://softeer.ai/practice/6274 [HSAT 1회 정기 코딩 인증평가 기출] 안전운전을 도와줄 차세대 지능형 교통시스템
* 
* 1h 43m 34s
* 
* 문제: 교통 인프라와 실시간 통신을 하는 자율주행 차가 가로 세로 N개의 교차로로 구성된 도로를 지날 때
*	교차로간 연결된 선을 도로, 도로의 교차점을 교차로
*	도로 한 칸 이동 시 1T가 걸림
* 
*	교차로의 신호등은 12가지 상태 중 4가지를 가지고 무한 반복함
*		신호 1: 오) 좌직우  /  신호 2: 위) 좌직우  /  신호 3: 왼) 좌직우  /  신호 4: 하) 좌직우
*		신호 5: 오) 좌직    /  신호 6: 위) 좌직	   /  신호 7: 왼) 좌직    /  신호 8: 하) 좌직
*		신호 9: 오) 직우    /  신호 10: 위) 직우   /  신호 11: 왼) 직우   /  신호 12: 하) 직우
* 
*	자율주행 자동차가 멈추지 않고 시간 T 이내에 갈 수 있는 교차로의 수 (신호가 맞지 않으면 그 교차로에 갈 수 없음)
*	
*  입력: N, 시간 T
*	N^2개의 줄에 각 교차로의 신호 집합 (신호는 항상 4개, 순서는 x축 부터)
* 
* 출력: 이동 경로에 있는 모든 교차로의 개수 출력 (한번 갔던 교차로는 중복해서 세지 않음)
* 
* 풀이: 차량 진행 방향인 dir 추가해야함
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX 10000

struct numt {
	int num, dir, t;
};

int n, t, ans;
int goway[13][3] = {
	{4, 4, 4},
	{1, 0, 3},
	{2, 1, 0},
	{1, 2, 3},
	{2, 3, 0},
	{1, 0, 4},
	{2, 1, 4},
	{3, 2, 4},
	{0, 3, 4},
	{3, 0, 4},
	{0, 1, 4},
	{1, 2, 4},
	{2, 3, 4}
};
int dx[5] = { 0, -1, 0, 1, 0 }; //  0, 1, 2, 3
int dy[5] = { 1, 0, -1, 0, 0 }; // 오, 상, 좌, 하
int arr[MAX + 2][4];
bool flag[MAX + 2];

void findway() {
	stack <numt> q;
	q.push({ 0, 1, 0 });

	while (!q.empty()) {
		numt cur = q.top(); q.pop();
		if (cur.t > t) continue;
		int light = arr[cur.num][cur.t % 4];
		if (!flag[cur.num]){
			flag[cur.num] = 1;
			ans++;
		}

		if (goway[light][1] != cur.dir) continue;

		for (int i = 0; i < 3; i++) {
			if (goway[light][i] == 4) continue;

			int x = cur.num / n + dx[goway[light][i]];
			int y = cur.num % n + dy[goway[light][i]];
			int nnum = x * n + y;

			if (x < 0 || y < 0 || x > n-1 || y > n-1) continue;
			q.push({ nnum, goway[light][i], cur.t + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> t;
	int k = pow(n, 2);
	for (int i = 0; i < k; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[i][j];

	findway();

	cout << ans;

	return 0;
}