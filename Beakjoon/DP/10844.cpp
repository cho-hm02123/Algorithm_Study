/* https://www.acmicpc.net/problem/10844
* 
* 29m 10s
* 
* 문제: 인접한 모든 수의 차가 1인 수는 계단수
*	N이 주어졌을 때 길이가 N인 계단수가 몇개 있는지
*	0으로 시작하는 수는 계단수 아님
* 
* 입력: N
* 
* 출력: 정답을 10^9로 나눈 나머지
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define X 1000000000

int n;
long long a[101][10];
long long sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i < 10; i++)
		a[1][i] = 1;

	for(int i = 2; i < n+1; i++)
		for (int j = 0; j < 10; j++) {
			if (j != 0) a[i][j] += a[i - 1][j - 1];
			if (j != 9) a[i][j] += a[i - 1][j + 1];

			a[i][j] %= X;
		}

	for (int i = 0; i < 10; i++)
		sum += a[n][i];

	cout << sum % X;
	return 0;
}
