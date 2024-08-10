/* https://www.acmicpc.net/problem/9375 패션왕 신해빈
* 
*  20m 07s
* 
* 문제: 가진 의상으로 옷이 안겹치게 얼마나 입을 수 있는지
* 
* 입력: TC, 가진 의상 수 n
*	n개의 의상 이름 및 종류
* 
* 출력: 경우의 수
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

int tc, n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> tc;
	while (tc--) {
		int cnt = 1;
		unordered_map <string, int> um;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string nm, tp;
			cin >> nm >> tp;
			um[tp]++;
		}

		for (auto a : um)
			cnt *= (a.second + 1); // 조합해서 입기 + 단독 입기

		cout << cnt - 1 << "\n";
	}

	return 0;
}
