/* https://www.acmicpc.net/problem/1700
* 
* 1h 13m 30s
* 
* 문제: 멀티탭 구 수와 전자제품 사용 순서가 주어졌을 때 플러그를 최소로 뽑는 최소 횟수
* 
* 입력: 멀티탭 구멍 수 N, 전기 용품 총 사용 횟수 K, 전기 용품 이름이 사용 순서대로
* 
* 출력: 하나씩 플러그를 빼는 최소 횟수
* 
* 풀이: 순서대로 콘센트 꽃음
*	1. 콘센트에 이미 꽃혀있으면 넘어감
*	2. 만약 콘센트 자리 남고 안꽃혀있으면 콘센트에 그냥 꽃음
*	3. 콘센트 꽉 찼는데 안꽃혀 있으면 뒤에 꽃혀야 할 애들 중 뽑을 애 우선순위 정하기
*		3-1. 뒤에 안꽃힐 애가 콘센트에 있으면 걔 뽑기
*		3-2. 그런 애가 많으면 젤 앞에 꽃힌거 뽑기
*		3-3. 뒤에 다 나오면 젤 늦게 꽃을 애 뽑기*	
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

int n, k, cnt;
vector <int> arr;
vector <int> pg;

class cmp {
public:
	bool operator()(pair<int, int> a, pair<int, int> b) { // 나오는 순번, 콘센트 인덱스
		if (a.X == b.X) return a.Y > b.Y;

		return a.X < b.X;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	for (int i = 0; i < k; i++) {
		if (find(pg.begin(), pg.end(), arr[i]) != pg.end()) continue; //있을 때
		if (pg.size() < n)
			pg.push_back(arr[i]);

		else {
			priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> pq;
			bool flag[101] = { 0, };

			for (int j = i + 1; j < k; j++) {
				if (find(pg.begin(), pg.end(), arr[j]) != pg.end()) {
					if (!flag[arr[j]]) {
						int a = find(pg.begin(), pg.end(), arr[j]) - pg.begin();
						pq.push({ j, a });
						flag[arr[j]] = 1;
					}
				}
			}

			for (int i = 0; i < pg.size(); i++) {
				if (!flag[pg[i]])
					pq.push({ k, i });
			}

			pg[pq.top().Y] = arr[i];

			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
