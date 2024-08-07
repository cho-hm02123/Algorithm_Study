/* https://www.acmicpc.net/problem/2805
* 
* 26m 28s
* 
* 문제: 절단기 높이 h를 정하면 톱날이 지면으로부터 h 높이까지 올라 감
*	한 줄에 연속한 나무 절단
*	적어도 M 미터의 나무를 집에 가져가기 위해 설정할 수 있는 최대 h
* 
* 입력: 나무 수 N, 원하는 나무 길이 M (합쳐서임)
*	나무의 높이
* 
* 출력: h의 최대 값
* 
* 풀이: parametic_search로
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define LL long long

int n;
LL m;
vector <LL> v;

bool cal(int x) {
	LL sum = 0;
	for (int i = 0; i < n; i++)
		if (v[i] - x > 0) sum += v[i] - x;

	return sum >= m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		LL a;
		cin >> a;
		v.push_back(a);
	}

	LL st = 0;
	LL en = *max_element(v.begin(), v.end());

	while (st < en) {
		LL mid = (st + en + 1) / 2;
		if (cal(mid))
			st = mid;
		else
			en = mid - 1;
	}

	cout << st;

	return 0;
}
