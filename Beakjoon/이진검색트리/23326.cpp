/* https://www.acmicpc.net/problem/23326 홍익 투어리스트
* 
* 34m 47s
* 
* 문제: N개의 구역이 원형으로 배치
*	1번 구역에서 시계방향으로 각각 2,....N번 구역이 존재 N번에서 한번 더 가면 1번 구역
*	1번 구역에서 시작
*	
*	쿼리
*		1. i: i번 구역이 명소가 아니었으면 명소로 지정되고 명소였으면 지정이 풀림
*		2. x: 시계방향으로 x만큼 이동
*		3. 명소에 도달하기 위해 시계방향으로 최소 몇칸 이동해야하는지 출력
*			3-1. 명소가 존재하지 않으면 -1 출력
* 
* 입력: 구역의 개수 N, 쿼리의 수 Q, N의 수열 A가 주어짐. i번째 구역이 명소면 A_i = 1; 아니면 A_i = 0
*	Q개의 쿼리가 주어짐 3번 쿼리는 하나 이상 존재
* 
* 출력: 3번 쿼리가 주어질 때 마다 해당 쿼리의 값 출력
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long

int n, q, ff;
set <int> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll dohyun = 1;

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> ff;
		if (ff) s.insert(i);
	}

	for (int i = 0; i < q; i++) {
		int a;
		cin >> a;

		if (a == 1) {
			int k;
			cin >> k;
			if (s.find(k) != s.end())
				s.erase(k);
			else
				s.insert(k);
		}

		else if (a == 2) {
			long long x;
			cin >> x;
			dohyun = (dohyun + x - 1) % n + 1;
		}

		else {
			if (s.empty())
				cout << "-1\n";

			else {
				auto it = s.lower_bound(dohyun);
				if (it != s.end())
					cout << *it - dohyun << "\n";	// dohyun의 좌표와 같거나 초과하는 최초의 iterator를 반환하므로 *it - dohyun
				else
					cout << n - dohyun + *s.begin() << "\n";	// 그런게 없으면 시계방향 기준 나보다 큰 좌표의 명소가 없는 것 이므로 n - dohyun 즉, 1까지 가는 칸수 + 명소의 가장 최소 점
			}
		}
	}

	return 0;
}
