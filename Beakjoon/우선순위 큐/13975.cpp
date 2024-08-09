/* https://www.acmicpc.net/problem/13975 파일 합치기 3
* 
*  13m 39s
* 
* 문제: 두 개의 파일을 합칠 때 필요한 비용은 두 파일의 크기의 합
*	하나의 파일로 만들 때 필요한 비용을 계산
*	이때 최소 비용을 출력
* 
* 입력: TC, 파일 수 n, 크기 n개
* 
* 출력: 최소 비용(\n)
* 
* 풀이: 그냥 작은 순으로 정렬해서 더해주면 됨
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

class cmp {
public:
	bool operator() (ll a, ll b) {
		return a > b;
	}
}; 

int tc, n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> tc;

	while (tc--) {
		priority_queue<ll, vector<ll>, cmp> pq;
		ll sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			pq.push(x);
		}

		while (pq.size() != 1) {
			ll num1 = pq.top(); pq.pop();
			ll num2 = pq.top(); pq.pop();
			sum += num1 + num2;
			pq.push(num1 + num2);
		}
		cout << sum << "\n";
	}

	return 0;
}
