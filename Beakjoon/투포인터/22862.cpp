/* https://www.acmicpc.net/problem/22862 가장 긴 짝수 연속한 부분 수열 (large)
* 
* 25m 44s
* 
* 문제: 길이가 N인 수열 S 1이상의 정수로 이루어짐
*	S에서 원하는 위치의 수를 골라 최대 K번 삭제할 수 있음
*	짝수로 이루어진 연속한 부분 수열 중 가장 긴 길이
* 
* 입력: 수열 길이 N, 최대 횟수 K, 수열 원소
* 
* 출력: 짝수로 이루어진 연속한 부분 수열 중 가장 긴 것
* 
* 풀이: cnt += arr[en] % 2
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, k, cnt, mm;
int arr[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int en = 0;
	cnt += arr[0] % 2;

	for (int st = 0; st < n; st++) {
		while (en < n-1 && cnt + arr[en+1]%2 <= k) {
			en++;
			cnt += arr[en] % 2;
		}

		mm = max(mm, en - st - cnt + 1);
		cnt -= arr[st] % 2;
	}

	cout << mm;

	return 0;
}
