/* https://www.acmicpc.net/problem/16398
* 
* 문제: 제국의 중심 행성은 T, N개의 행성 간에 플로우를 설치
*	모든 행성을 연결하면서 관리 비용을 최소로
*	N개의 행성은 정수 1 ~ N으로 표시, 행성 i, 행성 j 사이의 플로우 관리 비용은 C_ij
* 
* 입력: N, 플로우 관리 비용 NxN
* 
* 출력: 최소 비용
* 
* 풀이: 최소신장트리
*	우선순위 큐를 통해 비용이 작은거 순으로
*	flag를 통해 트리구조 유지
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define MAX 1000

struct vcost {
	int v, cost;
};

class cmp {
public:
	bool operator() (vcost a, vcost b) {
		if (a.cost == b.cost)
			return a.v > b.v;
		return a.cost > b.cost;
	}
};	priority_queue <vcost, vector<vcost>, cmp> pq;

int n;
long long ans;
vector <vcost> v[MAX + 2];
bool flag[MAX + 2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++) {
			vcost a;
			a.v = j;
			cin >> a.cost;
			v[i].push_back(a);
		}

	flag[1] = 1;
	for (auto nxt : v[1])
		pq.push(nxt);

	int cnt = 0;
	while (cnt < n - 1) {
		vcost a;
		a = pq.top(); pq.pop();
		if (flag[a.v]) continue;
		flag[a.v] = 1;
		ans += a.cost;
		cnt++;

		for (auto nxt : v[a.v])
			if (!flag[nxt.v]) pq.push(nxt);
	}

	cout << ans;

	return 0;
}
