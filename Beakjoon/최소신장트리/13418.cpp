/* https://www.acmicpc.net/problem/13418
* 
* 문제: 건물간 연결된 길이 오르막길, 내리막길 두 종류 중 하나
*	건물에 번호 붙어있고 입구는 0
*	모든 건물을 방문하는데 필요한 최소한의 길을 선택
*	오르만을 k번 오를 때 피로도는 pow(k, 2) 이때 내리막길로 내려갔다가 다시 올라올 때 오르막이 되는 경우는 고려하지 않는다???
*	
* 입력: 건물 개수 N 도로 개수 N
*	M개의 A, B, C > A, B 건물에 연결된 도로 C(0 - 오르막, 1 - 내리막)
* 
* 출력: 최악의 경우 피로도 - 최적의 경우 피로도
* 
* 풀이: m이 하나 작음
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000

struct vcost {
	int cost, v;
};

class cmp1 {	// 최악의
public:
	bool operator()(vcost a, vcost b) {
		if (a.cost == b.cost) return a.v > b.v;
		return a.cost > b.cost;
	}
};	priority_queue<vcost, vector<vcost>, cmp1> pq1;

class cmp2 {	// 최적
public:
	bool operator()(vcost a, vcost b) {
		if (a.cost == b.cost) return a.v > b.v;
		return a.cost < b.cost;
	}
};	priority_queue<vcost, vector<vcost>, cmp2> pq2;

int n, m, mx, mn;
bool flag1[MAX + 2];
bool flag2[MAX + 2];
vector <vcost> v[MAX + 2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	m++;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ c, b });
		v[b].push_back({ c, a });
	}

	flag1[0] = 1;
	flag2[0] = 1;
	for (auto nxt : v[0]) {
		pq1.push(nxt);
		pq2.push(nxt);
	}

	int cnt = 0;
	int num = 0;
	while (cnt < n) {
		vcost cur = pq1.top(); pq1.pop();

		if (flag1[cur.v]) continue;

		flag1[cur.v] = 1;
		if (cur.cost == 0) num++;
		cnt++;

		for (auto nxt : v[cur.v])
			if (!flag1[nxt.v]) pq1.push(nxt);
	}

	mx = pow(num, 2);
	num = cnt = 0;
	while (cnt < n) {
		vcost cur = pq2.top(); pq2.pop();

		if (flag2[cur.v]) continue;

		flag2[cur.v] = 1;
		if (cur.cost == 0) num++;
		cnt++;

		for (auto nxt : v[cur.v])
			if (!flag2[nxt.v]) pq2.push(nxt);
	}
	mn = pow(num, 2);

	cout << mx - mn;

	return 0;
}
