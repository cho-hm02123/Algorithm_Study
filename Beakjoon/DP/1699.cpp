/* https://www.acmicpc.net/problem/1699
* 
* 26m 26s
* 
* 문제: 자연수 N은 자신보다 작거나 같은 제곱수의 합으로 나타낼 수 있음
*	이때 나타낼 수 있는 최소 개수
* 
* 입력: N
* 
* 출력: 제곱으로 나타낼 수 있는 최소 개수
* 
* 풀이: n자체가 제곱인 수 기점으로 바뀜
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		arr[i] = i;
		for (int j = 1; j * j <= i; j++)
			arr[i] = min(arr[i], arr[i - j * j] + 1);
	}

	cout << arr[n];

	return 0;
}
