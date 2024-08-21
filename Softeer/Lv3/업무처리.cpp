/* https://softeer.ai/practice/6251 [HSAT 5회 정기 코딩 인증평가 기출] 업무 처리
* 
* 1h 11m 40s 문제 이해하는데 50분 걸림;;
* 
* 문제: 어떤 부서의 업무 조직은 완전 이진트리 모양
*	부서장이 루트이고 부거장 포함 각 직원은 오른쪽과 왼쪽에 부하 직원을 가짐, 부하직원이 없는 직원은 말단 직원
*	모든 말단 직원은 부서장까지 올라가는 거리가 동일
* 
*	업무는 R일 동안 진행
*	처음에 말단 직원들만 K개의 순서가 정해진 업무를 갖고 있음 각 업무엔 번호가 있다
*	각 날짜에 남은 업무가 있는 경우 말단 직원은 하나의 업무를 처리해서 상사에게 올림 
*	단, 홀수번째 날에는 왼쪽 부하 직원이 올린 업무를, 짝수번째 날에는 오른쪽 부하 직원이 올린 업무를 처리
*	부서장이 처리한 일은 완료된 것
*	올린 업무는 다음날 상사가 처리 가능
*	처리가 완료된 업무들의 번호의 합을 계산
* 
* 입력: 조직도의 높이 H(1 이상 10 이하), 말단에 대기하는 업무의 수 K(1 이상 10 이하), 업무가 진행되는 날짜 수 R(1 이상 1000 이하)
*	각각의 말단 직원에 대해 대기하는 업무가 제일 왼쪽 말단 직원부터 순서대로 주어짐
* 
* 출력: 완료된 업무의 번호 합
* 
* 풀이: 이진트리의 x번지 왼쪽 자식이 2x, 오른쪽 자식이 2x+1 일 때 x번지의 부모가 x/2 라는 것을 사용
*	먼저 받은 업무 먼저 처리하기 위해 struct에 큐 만들어줌, 그리고 해당 struct에 [2][MAX]인 배열을 생성해서 날짜가 홀수일 때 나머지, 짝수일 때 나머지를 사용
*	즉, 짝수 날일 때 [0][idx]에 해당하는 업무를 처리하고, 홀수 날일 때 [1][idx]에 해당하는 업무를 처리
*	업무를 넘겨줄 땐 왼쪽 자식이 짝수, 오른쪽 자식이 홀수 이므로 [(idx+1)%2][idx/2]에 해당하는 상사에게 업무를 넘겨줌
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 2048

struct upm {
	queue <int> q;
};

int h, k, r, ans;
upm arr[2][MAX];
upm v[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> h >> k >> r;

	int idx = pow(2, h + 1) - 1;
	int mal = pow(2, h);

	for(int i = mal; i <= idx; i++)
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			v[i].q.push(a);
		}

	for(int day = 1; day <= r; day++) { // 홀에 왼 짝에 오
		int hz = day % 2;
		for (int i = 1; i <= idx; i++) {

			if (i >= mal && i <= idx) { // 말단 직원의 업무 처리
				if (!v[i].q.empty()) {
					arr[(i + 1) % 2][i / 2].q.push(v[i].q.front());
					v[i].q.pop();
				}
			}

			else {	// 직원의 업무 처리
				if (!arr[hz][i].q.empty()) {
					if (i == 1)	// 부서장의 업무 처리
						ans += arr[hz][i].q.front();
					else
						arr[(i + 1) % 2][i / 2].q.push(arr[hz][i].q.front());

					arr[hz][i].q.pop();
				}
			}
		}
	}

	cout << ans;

	return 0;
}