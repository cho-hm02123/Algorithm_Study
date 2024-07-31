/* https://www.acmicpc.net/problem/2910
* 
*  21m 55s
* 
* 문제: 숫자 n개로 이루어진 수열 / 숫자 <= C
*	숫자가 등장하는 빈도순으로 정렬
* 
* 입력: N, C
*	수열
* 
* 풀이: map을 써서 먼저 나온 수인지 판단할 수 있도록 함
*	나온적 없는 수면 해당 수를 key로 나온 순번인 i를 매칭 
*	-> 나왔던 수면 map[key]을 인덱스로 하는 arr의 크기를 1 증가
*	-> 값 다 받고 우선순위큐를 사용해 정렬
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int n, c;
int arr[1000];
map <int, int> m; //idx, 값

class cmp {
public:
	bool operator() (int a, int b) {
		if (arr[m[a]] == arr[m[b]]) return m[a] > m[b];
		return arr[m[a]] < arr[m[b]];
	}
}; priority_queue <int, vector<int>, cmp> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue <int> q;

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (m.find(a) == m.end())
			m.insert(make_pair(a, i));

		arr[m[a]]++;
		q.push(a);
	}

	while (!q.empty()) {
		pq.push(q.front());
		q.pop();
	}

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

	return 0;
}
