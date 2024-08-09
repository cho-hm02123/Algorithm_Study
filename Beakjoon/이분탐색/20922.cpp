/* https://www.acmicpc.net/problem/20922 겹치는 건 싫어
* 
* 17m 44s
* 
* 문제: 같은 원소가 K개 이하로 들어있는 최장 연속 수열의 길이 구하기
* 
* 입력: 수열 길이 N, 중복 원소 최대 개수 K, 수열 원소
* 
* 출력: 조건을 만족하는 가장 긴 수열의 길이
* 
* 풀이: 원소 종류 하나당 같은 개수가 k개임
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, k;
int arr[200001];
int flag[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int en = 0;
	int cnt = 0;
	int mm = 0;
	flag[arr[0]] = 1;
	for (int st = 0; st < n; st++) {
		while (en < n-1 && flag[arr[en+1]] < k) {
			en++;
			flag[arr[en]]++;
		}

		mm = max(mm, en - st+1);
		flag[arr[st]]--;
	}

	cout << mm;

	return 0;
}
