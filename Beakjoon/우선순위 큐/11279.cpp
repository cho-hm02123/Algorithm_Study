/* https://www.acmicpc.net/problem/11279 최대 힙
* 
*  07m 02s
* 
* 문제: 배열에 자연수 x를 넣음
*	배열에서 가장 큰 값을 출력 후 그 밧을 지움
* 
* 입력: 연산 개수 N, 정보 x -> 만약 x가 자연수이면 x를 배열에 넣고, 0이면 가장 큰 값을 출력 후 해당 값을 삭제
* 
* 출력: 0입력 횟수만큼 출력 (\n) 만약 비어있으면 0출력
* 
* 풀이: 그냥 우선순위 큐 쓰면 됨
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include<queue>
using namespace std;

class cmp {
public:
	bool operator() (int a, int b) {
		return a < b;
	}
}; priority_queue<int, vector<int>, cmp> pq;

int n, x;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;

		if (x == 0) {
			if (pq.empty())
				cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(x);
	}

	return 0;
}
