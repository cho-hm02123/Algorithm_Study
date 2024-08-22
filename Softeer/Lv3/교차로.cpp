/* https://softeer.ai/practice/6256 [HSAT 3회 정기 코딩 인증평가 기출] 교차로
* 
*  2h01m41s		시간초과 미친문제 + 문제 이해 힘들었으ㅁ
* 
* 문제: 교차로에서는 직진만 가능
*	자동차끼리 충돌을 방지할 수 있도록 차가 적질히 멈춰있되, 너무 오래 멈춰있지 않게
*	교차로의 맨 앞 차량은 자신 기준 오른쪽 교차로에 차가 있으면 1초 동안 출발하지 않음
*	만약 4대의 차선에 모두 차가 있으면 어떠한 차량도 지나갈 수 없음
*	N대의 차량이 A, B, C, D 위치에 진입할 예정일 때, i번째 차량은 t_i초에 w_i 위치에 진입하여 해당 차선의 맨 뒤 줄에 있는다. (혼선 방지를 위해 같은 시각에 각 위치에 진입할 수 있는 차량은 최대 한대
*	매 초마다 차량이 진입한 직후, 각 위치의 맨 앞 차는 오른쪽에 차가 있는지 확인 후 차량이 없으면 교차로 통과
*	각 치량이 교차로를 통과하는 시각이 언제인지 계산
* 
* 입력: N(2 이상 200,000이하)
*	N개의 줄 중 i번째 줄에 t_i와 w_i
* 
* 출력: N개의 장수를 출력 i번 차량이 통과하면 통과하는 시각, 통과하지 못한다면 -1
* 
* 풀이: 많은 배열이 필요 없음
*	1. 각 교차로에 차량 번호와 시간을 교차로 별 큐에 저장
*	2. 시작 시간을 0으로
*	3. 시간을 1씩 증가시키면 시간 초과가 나므로 timeshift 함수를 제작
*		3-1. 현재 교차로 큐 front 차량의 시간 최소값이 현 시간보다 크면 현재 시간을 해당 시간으로 바꿈 (현재 시간이 교차로 시각 최소보다 작다는건 교차로에 차가 한대도 없다는 것)
*	4. 교차로에 대기하고 있는 차량이 움직일 수 있는지 판단하는 함수 제작
*		4-1. 현재 교차로에 대기 차량이 있고 오른쪽 교차로에 대기차량이 없으면 flag를 true로
*		4-2. 대기 차량이 없다는 건 해당 교차로 큐가 비어 있거나 큐 front의 시간이 현재 시간보다 크다 (큐 front의 시간이 현재 시각보다 크면 아직 대기하러 안온 상태 즉, 비었다)
*	5. 차량을 이동시키는 함수 제작
*		5-1. 4를 토대로 차량을 움직임 (flag가 1이면 이동할 수 있음)
*		5-2. 만약 움직일 수 있는 차가 없으면 교착상태 이므로 종료 (3에서 시간을 계속 업데이트 해주므로 큐에 차가 들어있지만 도로에 대기 차량이 없는 상황은 발생하지 않음)
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 200000
#define MAX_T 0x7fffffff

struct tn {
	int n, t;
};

int n, cur;
int rst[MAX + 2];
queue <tn> q[4]; // 교차로 번호 A = 3, B = 2, ... char - 'A'

int timeshift() {
	int time_a, time_b, time_c, time_d;
	if (!q[0].empty()) time_d = q[0].front().t; else time_d = MAX_T;
	if (!q[1].empty()) time_c = q[1].front().t; else time_c = MAX_T;
	if (!q[2].empty()) time_b = q[2].front().t; else time_b = MAX_T;
	if (!q[3].empty()) time_a = q[3].front().t; else time_a = MAX_T;

	int new_time = min({ time_a, time_b, time_c, time_d });
	if (new_time < cur) return cur;
	return new_time;
}

void judgego(bool state[]) {
	for (int i = 0; i < 4; i++) {
		if (!q[i].empty() && q[i].front().t <= cur) {
			if (q[(i + 1) % 4].empty())
				state[i] = true;
			else if (q[(i + 1) % 4].front().t > cur)
				state[i] = true;
		}
	}
}

bool gocar(bool state[]) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (state[i]) {
			rst[q[i].front().n] = cur;
			q[i].pop();
		}
		else
			cnt++;
	}
	if (cnt == 4) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		char b;
		cin >> a >> b;
		int c = b - 'A';
		q[3-c].push({i, a});
	}

	fill(rst, rst + n, -1);

	while (!q[0].empty() || !q[1].empty() || !q[2].empty() || !q[3].empty()) {
		bool state[4] = { false, false, false, false };
		cur = timeshift();	// 시간 이동(안그럼 시간초과)
		judgego(state);		// 도로에 차가 갈 수 있는지 판단
		if (gocar(state))	// 도로가 교차로를 지나게 함과 동시에 교착상태면 반복문 탈출
			break;
		cur++;
	}

	for (int i = 0; i < n; i++)
		cout << rst[i] << "\n";

	return 0;
}