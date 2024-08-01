/* https://www.acmicpc.net/problem/11055
* 
* 12m 05s
* 
* 
* 문제: 무열 A가 주어졌을 때 수열의 증가하는 부분 수열 중 합이 가장 큰 것
* 
* 입력: A수열의 크기 N, 수열 원소
* 
* 출력: 합이 가장 큰 증가하는 부분 수열의 합
* 
* 풀이: i-1번째 원소까지의 증가하는 수열의 합 중 최대와 i번째 원소를 더해 a[i]에 저장
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int a[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	a[0] = arr[0];

	int ss;
	for (int i = 1; i < n; i++) {
		ss = 0;
		for (int j = i-1; j >= 0; j--) {
			if (arr[j] < arr[i])
				ss = max(ss, a[j]);
		}
		if (ss == 0)
			a[i] = arr[i];
		else
			a[i] = ss + arr[i];
	}

	cout << *max_element(a, a + n);

	return 0;
}
