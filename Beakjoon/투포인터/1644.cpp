/* https://www.acmicpc.net/problem/1644 소수의 연속 합
* 
*  45m 18s
* 
* 문제: 하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수 존재
*	자연수가 주어졌을 때 연속된 소수의 합으로 나타낼 수 있는 경우의 수
* 
* 입력: 자연수 N
* 
* 출력: 경우의 수
* 
* 풀이: 에라토스테네스의 체 사용해서 n이하 소수 찾아주고 투포인터로 탐색
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n, cnt;
int arr[4000001];
vector <int> v;

void fd() {
	for (int i = 2; i <= n; i++)
		arr[i] = i;

	for (int i = 2; i*i <= n; i++) {
		if (arr[i] == 0) continue;

		for (int j = 2*i; j <= n; j += i)
			arr[j] = 0;
	}

	for (int i = 2; i <= n; i++)
		if (arr[i] != 0) v.push_back(arr[i]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	fd(); // n이하 소수 찾기

	int en = 0;
	int sum = 0;

	for (int st = 0; st < v.size(); st++) {
		while (en < v.size() && sum < n) {
			sum += v[en];
			en++;
		}
		if (sum == n) cnt++;

		sum -= v[st];
	}

	cout << cnt;

	return 0;
}
