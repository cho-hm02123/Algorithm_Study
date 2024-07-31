/* https://www.acmicpc.net/problem/5648
* 
*  19m 06s
* 
* 문제: 모든 원소가 양의 정수
*		원소를 거꾸로 뒤집고 오름차순으로 정렬
*		원소 뒤집었을 때 0 앞에 있는 경우 삭제해야 함
* 
* 입력: n, 원소 (n <= 10^6, 원소 < 10^12)
* 
* 출력 : 원소 하나 "\n"
* 
* 풀이: 10씩 나눠서 나머지 저장한 후 뒤에서부터 10씩 곱하기
*		정렬은 sort로
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector <long long> v;
	for (int j = 0; j < n; j++) {
		int arr[13] = { 0, };
		long long a;
		long long num = 0;

		cin >> a;

		int cnt = 0;
		while (a) {
			int k = a % 10;
			a /= 10;
			if (cnt == 0 && k == 0) continue;
			arr[cnt] = k;
			cnt++;
		}

		a = 0;
		for (int i = 0; i < cnt; i++)
			a += arr[i] * pow(10, cnt - i-1);
		v.push_back(a);
	}

	sort(v.begin(), v.begin()+n);
	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}


	return 0;
}
