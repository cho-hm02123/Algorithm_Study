/* [HSAT 7회 정기 코딩 인증평가 기출] 자동차 테스트
* 
* 문제: 자동차의 연비가 높을수록 연료 소비가 적고, 더 많은 거리를 주행 가능
*	n대의 자동차를 새로 만들었지만 여건상 3대의 자동차에 대해서만 테스트가 가능
*	n개의 실제 연비가 주어졌을 때 q개의 질의에 대해 임의로 3대의 자동차를 골라 테스트해 중앙값이 m_j가 나오는 서로 다른 경우의 수를 구하여라
* 
* 입력: n, q
*	n개의 자동차 연비 (서로 다르며 long long형)
*	q개의 테스트 값 m_j
* 
* 출력: 중앙값이 m_j 가 나오는 경우의 수 "\n"
* 
* 풀이: 그냥 find를 하면 시간초과남 따라서 이분탐색 사용
*	또한 연비가 longlong 형인 것을 주의
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int n, q;
vector <ll> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		ll a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	while (q--) {
		ll m;
		cin >> m;

		int st = 0; 
		int en = n - 1;

		while (st != en) {
			int mid = (st + en+1) / 2;
			if (v[mid] < m)
				st = mid;
			else if (v[mid] == m) {
				cout << mid * (n - 1 - mid) << "\n";
				break;
			}
			else
				en = mid - 1;
		}

		if (st == en)
			cout << "0\n";
	}

	return 0;
}