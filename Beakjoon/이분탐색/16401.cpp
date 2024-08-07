/* https://www.acmicpc.net/problem/16401
* 
* 15m 44s
* 
* 문제: M명의 조카에게 N개의 막대 과자를 동일 길이로 줄 수 있는 과자의 최대 길이
*	과자를 자를 순 있고 합칠 순 없음
* 
* 입력: 초카 수 M, 과자 수 N, N개의 과자 길이
* 
* 출력: 조카 1명에게줄 수 있는 과자 최대 길이
*	못주면 0 출력
* 
* 풀이: 이분탐색인데 parametic_search임
*	길이에 따라 개수가 정해지므로
*	가장 짧은 길이를 0, 긴 길이를 막대과자 중 최고 길이로 해서
*	길이를 이분탐색으로 정하고 개수가 맞는지 확인
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define LL long long

int m, n;
LL mm;
vector <LL> v;

bool cal(LL x) {
	LL cnt = 0;
	if (x == 0)
		return true;
	for (int i = 0; i < n; i++)
		if (v[i] / x) cnt += v[i] / x;

	if (cnt >= m) {
		mm = max(mm, x);	// 잘 풀어놓고 여기서 길이가 아니라 개수를 비교하고 있었네
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		LL a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());
		
	LL st = 0;
	LL en = v[n-1];

	while (st < en) {
		LL mid = (en + st + 1) / 2;

		if (!cal(mid)) // 개수 안될 때 즉 너무 길 때
			en = mid - 1;

		else
			st = mid;
	}

	cout << mm;

	return 0;
}
