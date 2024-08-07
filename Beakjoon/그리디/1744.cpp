/* https://www.acmicpc.net/problem/1744
* 
* 49m 35s
* 
* 문제: 길이가 N인 수열
*	수열의 두 수를 묶음 이때 어떤 위치의 수든 상관 없지만 자기자신과 묶는건 안됨
*	수열의 합을 수할 때 묶은 수는 서로 곱해서 더암
*	묶는건 한번 이하로
*	수열 합이 최대가 되도록
* 
* 입력: n, 수열
* 
* 출력: 최대 합
* 
* 풀이: 오름차순으로 설정 이때 음수는 절댓값이 큰 순서로
*	idx가 n-1 부터 검사 이때 수가 0이면 그냥 넘어가고 zn을 1 증가시킴 -> 음수가 홀수개라 양수로 못만드는 애가 하나 생기면 걔랑 곱해서 0으로 만들어줌
*	-> 이럴 바에 그냥 cmp에서 설정해주면 되긴 함
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long sum;
vector <int> v;

bool cmp(int a, int b) {
	if (a < 0 && b < 0) return abs(a) < abs(b);
	if (a < b) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end(), cmp);

	int zn = 0;

	for (int i = n-1; i >= 0; i--) {
		if (i > 0) {
			if (v[i] < 0 && v[i - 1] < 0) {
				sum += v[i] * v[i - 1];
				i = i - 1;
			}

			else if (v[i] == 0)
				zn++;

			else if (v[i] > 1 && v[i - 1] > 1) {
				sum += v[i] * v[i - 1];
				i = i - 1;
			}
			else
				sum += v[i];
		}
		else if (i == 0) {
			if (v[i] < 0 && zn > 0) continue;
			else
				sum += v[i];
		}
	}

	cout << sum;

	return 0;
}
