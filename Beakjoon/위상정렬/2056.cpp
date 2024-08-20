/* https://www.acmicpc.net/problem/2056 작업
* 
* 
* 문제: 작업 N개, 작업마다 걸리는 시간이 정수로 주어짐
*	선수 작업이 존재, K번 작업의 선수 작업은 부조건 K보다 작음
*	모든 작업을 완료하기 위해 필요한 최소 시간 > 선행 관계가 아닌 작업은 동시 수행 가능
* 
* 입력: N, N개의 작업이 1번 부터 N번 까지 (걸리는 시간, 선행 관계에 있는 작업의 개수, 선행관계의 작업 범호)
* 
* 출력: 모든 작업을 완료하기 위한 최소 시간
* 
* 풀이: 선수 작업이 없는 작업의 끝나는 시간에 해당 작업의 인덱스를 저장
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

int n, ans;
int indegree[10001];
int tm[10001];
vector <int> v[10001];
vector <int> vt[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> tm[i] >> num;
		if (!num) vt[tm[i]].push_back(i);

		while (num--) {
			int a;
			cin >> a;
			v[a].push_back(i);
			indegree[i]++;
		}
	}

	for (int i = 0; i <= 1000000; i++) {
		for (int nxt : vt[i]) {
			ans = i;
			for (int nnxt : v[nxt]) {
				indegree[nnxt]--;
				if (!indegree[nnxt])
					vt[i + tm[nnxt]].push_back(nnxt);
			}
		}
	}

	cout << ans;

	return 0;
}
