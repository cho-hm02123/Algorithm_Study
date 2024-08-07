/* https://www.acmicpc.net/problem/2170
* 
* 08m 52s
* 
* 문제: 선을 그을 때 자의 한 점에서 다른 한 점까지 이떄 이미 잇는 선에 겹쳐서 그려도 됨
*	그려진 선 길이의 총 합 선이 여러번 그어진 곳은 한번만 계산
* 
* 입력: 선을 그을 횟수 n
*	두 점의 위치(long long)
* 
* 출력: 그은 선의 총 길이 
* 
* 풀이: 오름차순 정렬
*	-> 0번 인덱스 y 좌표를 현재 시점으로 설정 후 총 길이에 y-x 더함
*	-> 1번 인덱스 부터 n-1번 인덱스까지 돌리면서 y가 현재 시점보다 큰지 비교
*	-> y가 현재 위치보다 클 때 x가 현재보다 크거나 같으면 y-x를 총합에 더해주고
*	-> x가 현재보다 작으면 y-현재를 총합에 더해줌
*	-> 현재 시점을 y로 변경
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second
#define ll long long
int n;
ll sum;
vector <pair<ll, ll>> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end());
	int cur = v[0].Y;
	sum += v[0].Y - v[0].X;

	for (int i = 1; i < n; i++) {
		if (v[i].Y > cur) {
			if (v[i].X >= cur)
				sum += v[i].Y - v[i].X;
			else
				sum += v[i].Y - cur;

			cur = v[i].Y;
		}
	}

	cout << sum;

	return 0;
}
