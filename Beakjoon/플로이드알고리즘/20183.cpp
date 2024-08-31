/* https://www.acmicpc.net/problem/20183 골목 대장 호석 - 효율성 2
* 
* 문제: N개의 교차로, M개의 골목(양방향)
*	모든 골목을 지날 때 마다 수금, 요금은 골목마다 다름
*	한 골목에서 내야하는 최대 요금의 최솟값을 계산
*	가진 돈으로 목표 지점을 갈 수 없다면 -1 출력
* 
* 입력: N, M, 시작 교차로 A, 도팍 교차로 B, 가진 돈 C
*	M개의 u, v, cost
* 
* 출력: A에서 B까지 C원 이하로 가는 경로들 중 지나는 골목의 요금의 최댓값의 최솟값 갈 수 없으면 -1 출력
* 
* 풀이: 노드가 100,000으로 매우 커 전체 탐색하면 시간초과 따라서 이분탐색 해야 함
*	수치심은 골목에서 지불하는 비용와 비례 
*	1. 이때 수치심을 줄이고 싶으면 -> 각 골목에서 내는 돈이 최소가 되고 싶다면 지불하는 금액의 총 합이 커지고
*	2. 지불하는 금액의 총 합이 적어지면 반대로 골목에서의 수치심이 커짐
*	
*	문제에서는 한 골목에서 내야하는 최대 요금의 최솟값 즉 경로중 가장 큰 값이 최소인게 얼마인지 궁금
*	이분탐색의 st = 1(골목 비용의 최소가 1이므로) en은 주어진 골목 비용중 최대로 설정
*	만약 목적지까지의 전체 비용을 지불할 수 없으면 2번에 따라 골목에서의 수치심을 키워야 함 따라서 st = mid+1로 mid를 증가
*	전체 비용을 지불할 수 있으면 1번에 따라 골목에서 수치심이 줄어도 됨 따라서 mid를 줄이기 위해 en = mid로 설정
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

typedef long long ll;
const int MAX = 100000;
const ll INF = 0x7f7f7f7f7f7f;
int n, m, a, b;
ll c, en, st = 1;
ll d[MAX + 2];
vector <pair<ll, int>> arr[MAX + 2];	// first - cost, second - node

bool cal(ll bi) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	fill(d + 1, d + n + 1, INF);

	d[a] = 0;
	pq.push({ 0, a });
	
	while (!pq.empty()) {
		pair<ll, int> cur = pq.top(); pq.pop();

		if (cur.X != d[cur.Y]) continue;

		for (auto nxt : arr[cur.Y]) {
			if (nxt.X > bi) continue;
			nxt.X += cur.X;
			if (d[nxt.Y] <= nxt.X) continue;
			d[nxt.Y] = nxt.X;
			pq.push(nxt);
		}
	}

	if (d[b] > c) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> a >> b >> c;

	while (m--) {
		int u, v;
		ll cost;
		cin >> u >> v >> cost;
		arr[u].push_back({ cost, v });
		arr[v].push_back({ cost, u });
		en = max(en, cost);
	}

	while (st < en) {
		ll mid = (st + en) / 2;
		if (cal(mid)) en = mid;	// 총 가진 금액이 충분하면 한번에 지불하는 가격의 최소가 적어도 됨
		else st = mid+1;	// 총 가진 금액이 부족하면 한번에 지불하는 가격의 최소가 커져야 됨
	}

	if (cal(st)) cout << st;
	else cout << "-1";

	return 0;
}
