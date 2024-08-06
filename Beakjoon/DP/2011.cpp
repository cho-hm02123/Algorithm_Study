/* https://www.acmicpc.net/problem/2011
* 
* 21m 31s
* 
* 문제: 암호가 주어졌을 때 나올 수 있는 해석의 경우의 수
* 
* 입력: 5000자리 이하 숫자 암호
* 
* 출력: 해석 가지 수 % 1000000 단, 해석할 수 없는 경우 0 출력
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define mod 1000000

string s;
int a[5001];
int b[5001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	int sz = s.length();
	for (int i = 1; i <= sz; i++) a[i] = s[i - 1] - '0';

	b[0] = 1;
	for (int i = 1; i <= sz; i++) {
		if (a[i] > 0) b[i] = b[i - 1] % mod;
		int sum = a[i-1]*10 + a[i];
		if (sum >= 10 && sum <= 26) b[i] = (b[i] + b[i - 2]) % mod;
	}

	cout << b[sz];

	return 0;
}
