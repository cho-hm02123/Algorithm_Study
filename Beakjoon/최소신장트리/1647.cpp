/* https://www.acmicpc.net/problem/1647
* 
* 문제: N개의 집, 집을 연결하는 M개의 길 길은 방향 없음
*	길을 유지하는데 유지비 들어감
*	마을을 둘로 나누고싶음 이때 분리된 마을 안에 임의의 두 집 사이엔 경로가 존재해야 함
*	분리된 두 마을 사이엔 길이 필요 없음
* 
* 입력: 집의 개수 n, 길의 개수 m
*	m개의 정보 A, B, C > A번 집 B번 집 유지비 C
* 
* 출력: 남은 길의 유지비 합의 최솟 값
* 
* 풀이: 최소신장 트리 근데 가장 큰 유지 비용을 뺀
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000000

struct vcost {
	int cost, v;
};

class cmp {
public:
	bool operator()(vcost a, vcost b) {
		if (a.cost == b.cost)
			return a.v > b.v;
		return a.cost > b.cost;
	}
};	priority_queue <vcost, vector <vcost>, cmp> pq;

int n, m, mm;
long long ans;
bool flag[MAX + 2];
vector <vcost> v[MAX + 2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	while (m--) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ cost, b });
		v[b].push_back({ cost, a });
	}

	flag[1] = 1;
	for (auto nxt : v[1])
		pq.push(nxt);

	int cnt = 0;
	while (cnt < n - 1) {
		vcost cur = pq.top(); pq.pop();
		if (flag[cur.v]) continue;

		flag[cur.v] = 1;
		ans += cur.cost;
		mm = max(cur.cost, mm);
		cnt++;

		for (auto nxt : v[cur.v])
			if (!flag[nxt.v]) pq.push(nxt);
	}

	cout << ans - mm;

	return 0;
}
