/* https://www.acmicpc.net/problem/2457
* 
* 
* 문제: 총 N개의 꽃 모두 같은 해에 피어서 같은 해에 진다.
*	하나의 꽃은 피는 날과 지는 날이 정해져 있음
*	4,6,9,11월은 30일 1,3,5,7,8,10,12월은 31일 2월은 28일
*	
*	1. 3월 1일 부터 11월 30일까지 매월 꽃이 한가지 이상 피어있도록 한다.
*	2. 정원에 심을 꽃의 수를 최소로 한다.
* 
*	N개의 꽃중 위 두 조건을 만족하도록 선택한 꽃의 최소 개수
* 
* 입력: N, 각각 피는 날짜와 지는 날짜
* 
* 출력: 선택한 꽃의 최소 개수 없다면 0
* 
* 풀이: 현재 시점을 포함하면서 지는 날이 가장 늦은 꽃을 선택
*	주의 -> 11/30 까지 피어있어야 하므로 11/30이후 즉 적어도 12/01에 지는 꽃을 골라야 함
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

int n;
vector <pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int st = 301;
	int en = 1201;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int ss = a * 100 + b;
		int se = c * 100 + d;

		v.push_back({ ss, se});
	}

	int t = st;
	int cnt = 0;

	while (t < en) {
		int sv = t;
		for (int i = 0; i < n; i++) {
			if (v[i].X <= t && v[i].Y > sv)
				sv = v[i].Y;
		}
		if (sv == t) {
			cout << 0;
			return 0;
		}
		cnt++;
		t = sv;
	}

	cout << cnt;

	return 0;
}
