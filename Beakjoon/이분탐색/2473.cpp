/* https://www.acmicpc.net/problem/2473 세 용액
* 
* 31m 49s
* 
* 문제: 산성 용액: 1 ~ 10^9, 알칼리 용액: -1 ~ -10^9
*	세가지 용액을 혼합해서 0에 가까운 용액
* 
* 입력: 용액 수 N, 용액 특성 값
* 
* 출력: 0에 가장 가까운 용액 특성 오름차순
* 
* 풀이: lower_bound 로 값 찾아도 그 외에 값이 더 있을 수 있음 lower_bound는 초과하는 첫 인덱스만 알려주기 때문
*	따라서 +- 2 까지 더 검사
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long a[5001];
vector <long long> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	long long a1 = v[0];
	long long a2 = v[1];
	long long a3 = v[2];
	long long sum = abs(a1 + a2 + a3);

	for(int i = 0; i < n-1; i++)
		for (int j = i+1; j < n; j++) {
			long long a = v[i] + v[j];

			int k = lower_bound(v.begin() + j + 1, v.end(), -a) - v.begin();
			if (k > n) continue;

			for (int h = k - 2; h <= k + 2; h++) {
				if (h <= j || h >= n) continue;
				long long al = v[h];

				if (abs(a + al) < sum) {
					sum = abs(a + al);
					a1 = v[i];
					a2 = v[j];
					a3 = al;
				}
				if (sum == 0) {
					cout << a1 << " " << a2 << " " << a3;
					return 0;
				}
			}
		}

	cout << a1 << " " << a2 << " " << a3;
	return 0;
}
