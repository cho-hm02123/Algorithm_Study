/* https://www.acmicpc.net/problem/1351 무한 수열
* 
*  18m 23s
* 
* 문제: 무한수열 A는 다음과 같다.
*	A_0 = 1
*	A_i = A_i/P + A_i/Q
*	N,P,Q가 주어질 때 A_N을 구해라
* 
* 입력: N, P, Q
* 
* 출력: A_N
* 
* 풀이: 백트래킹 사용 이때 u[k]에 값이 있으면 반환 없으면 다시 백트래킹으로 넘어감
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define ll long long

ll n, p, q;
unordered_map<ll, ll> um;

ll bt(ll k) {
	if (k == 0) return 1;
	if (um[k]) return um[k]; // 값이 있으면

	um[k] = bt(k / p) + bt(k / q);
	return um[k];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> p >> q;

	cout << bt(n);

	return 0;
}
