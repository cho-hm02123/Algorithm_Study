/* https://www.acmicpc.net/problem/1766 문제집
* 
* 
* 문제: 1번 부터 N번 까지 총 N개의 문제
*	세 가지 조건을 따라 풀 문제 순서를 정함
*		1. N개의 문제는 모두 풀어야 함
*		2. 먼저 푸는 것이 좋은 문제는 반드시 먼저 풀어야 함
*		3. 가능하면 쉬운 문제부터 (문제 번호가 작을 수록 쉬움)
* 
* 입력: 문제 수 N, 먼저 푸는 것이 좋은 문제에 대한 정보의 수 M
*	M개의 줄에 걸쳐 두 정수의 순서쌍 A,B가 빈칸을 사이에 두고 주어짐 (A번 문제를 B 보다 먼저 풀어야 함)
* 
* 출력: 풀어야 하는 문제를 순서대로 출력
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int indegree[32001];
vector <int> v[32001];
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}
	
	for (int i = 1; i <= n; i++)
		if (!indegree[i]) q.push(i);

	while (!q.empty()) {
		int cur = q.top(); q.pop();
		cout << cur << " ";

		for (int nxt : v[cur]) {
			indegree[nxt]--;
			if (!indegree[nxt])
				q.push(nxt);
		}
	}

	return 0;
}
