/* https://www.acmicpc.net/problem/9084
* 
* 33m 25s
* 
* 문제: 1원, 5원, 10원, 50원, 100원, 500원으로 주어진 금액을 만드는 모든 방법을 세는 프로그램
* 
* 입력: TC
*	동전의 가지 수 N
*	N가지 동전의 각 금액
*	만들어야 할 금액 M
* 
* 출력: M을 만드는 모든 방법의 수
* 
* 풀이: 동전 종류 추가될 때마다 추가된 동전 금액부터 경우의 수가 증가함을 이용
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int tc, n, m;
int d[21];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> tc;
	while (tc--) {
		int num[10001] = { 0, };

		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> d[i];

		cin >> m;

		num[0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = d[i]; j <= m; j++)
				num[j] += num[j - d[i]];

		cout << num[m] << "\n";
	}

	return 0;
}
