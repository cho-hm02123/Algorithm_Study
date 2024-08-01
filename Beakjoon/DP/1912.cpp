/* https://www.acmicpc.net/problem/1912
* 
*  21m 00s
* 
* 
* 문제: n개의 정수로 이루어진 임의의 수열 
*	연속된 몇개의 수를 선택해서 구할 수 있는 최대 합
*
* 입력: n, n개의 정수로 이루어진 수열
* 
* 출력: 최댓값
* 
* 풀이: i-1번째 까지 더한 합에 i번째 수열을 더했을 때와 i 번째 수열을 더한 값 중 큰 값을 저장.
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
long long arr[100001];
long long a[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		if (i == 0)
			a[i] = arr[i];
		else
			a[i] = max(a[i - 1] + arr[i], arr[i]);
	}

	cout << *max_element(a, a + n);

	return 0;
}
