/* https://www.acmicpc.net/problem/2110 공유기 설치
* 
* 
* 문제: 집 N개가 수직선 위에 있음, 각 집의 x 좌표가 있고 좌표가 같은 경우는 없음
*	공유기 C개를 설치할 때 가장 인접한 공유기 사이의 거리를 최대로
*	한 집엔 공유기 한대만 설치 가능
* 
* 입력: N, C, 집 좌표
* 
* 출력: 두 공유기 사이의 최대 거리
* 
* 풀이: parametic search로 0 ~ 입력 최대 값 까지의 수를 이분탐색 mid를 통해 정한 뒤 lower_bound를 이용해서 가능성을 판단
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int n, c;
ll a[200001];

int cal(ll k) {
	int cnt = 0;
	int idx = 0;

	while (idx != n) {
		idx = lower_bound(a + idx, a + n, a[idx]+k) - a;
		cnt++;
	}
	return cnt >= c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	ll st = 0;
	ll en = a[n - 1];

	while (st < en) {
		ll mid = (st + en+1) / 2;

		if (cal(mid)) st = mid;
		else
			en = mid - 1;
	}

	cout << st;

	return 0;
}
