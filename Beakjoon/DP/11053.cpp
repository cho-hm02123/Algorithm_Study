/* https://www.acmicpc.net/problem/11053
* 
*  04m 53s
* 
* 문제: 길이가 N인 수열 A에서 증가하는 수열의 길이가 가장 긴 것
* 
* 입력: 수열 A의 크기 N, 수열의 원소
* 
* 출력: 최대 길이
* 
* 풀이: a[i]에 i번째 원소까지 증가 수열의 최대 길이를 저장
*	i번째 원소보다 작은 i-1 번째 까지의 a중 최대값에 1을 더해서 a[i]에 저장
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

	int ss;
	a[0] = 1;
	for (int i = 1; i < n; i++) {
		ss = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i])
				ss = max(ss, a[j]);
		}
		if (ss == 0)
			a[i] = 1;
		else
			a[i] = ss + 1;
	}

	cout << *max_element(a, a + n);

	return 0;
}
