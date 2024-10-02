/* https://www.acmicpc.net/problem/30892 상어 키우기
* 
* 문제: N마리의 상어, 상어는 서로 같거나 다른 크기의 몸집 A_i
*	자기보다 작은 상어는 전부 먹을 수 있음, 이때 상어의 크기는 잡어먹힌 상어의 크기만큼 커짐
*	크기가 T인 아기 상어가 N마리의 상어 크기 정보를 알고있음
*	최대 K 마리까지 적절한 순서로 잡아먹고 몸집을 최대로 키울 예정
*	최대 K 마리를 적절한 순서로 잡아먹을 때 몸이 최대 얼마나 커질 수 있는지
* 
* 입력: 상어의 마리 수 N, 먹을 수 있는 상어의 최대 마리 수 K, 최초 크기 T
*	N 마리의 상어의 크기 A_i
* 
* 출력: K 마리의 상어를 적절한 순서로 잡아먹었을 때 몸집의 최대
* 
* 풀이: 오름차순 정렬 후 t보다 작은 상어는 stack에 크거나 같은 상어는 queue에 입력
*	stack에 있는 상어 먹고 현재 t보다 작은 queue에 있는 상어를 stack에 입력 이를 k번 반복
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define ll long long
#define MAX 200000

int n, k;
ll t;
vector <int> v;
stack <int> s;
queue <int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> t;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (t <= v[i])
			q.push(v[i]);
		else
			s.push(v[i]);
	}

	while (k--) {
		if (s.empty()) break;
		else {
			t += s.top();
			s.pop();
			while (!q.empty()) {
				if (q.front() < t) {
					s.push(q.front());
					q.pop();
				}
				else
					break;
			}
		}
	}

	cout << t;
	return 0;
}
