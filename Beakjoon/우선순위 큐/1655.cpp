/* https://www.acmicpc.net/problem/1655 가운데를 말해요
* 
* 
* 문제: 숫자 하나 말하면 지금까지 말한 수 중 가운데 값을 말해야 함
*	만약 짝수개면 두 수 중 작은거
* 
* 입력: 외치는 정수의 개수 N, 외치는 수 n개
* 
* 출력: ㅜ줄에 걸쳐 하나씩 (\n)
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int n;
priority_queue<int> Maxtop;
priority_queue <int, vector<int>, greater<>> Mintop;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		
		if (Maxtop.size() <= Mintop.size())
			Maxtop.push(a);
		else
			Mintop.push(a);

		if (!Mintop.empty() && Mintop.top() < Maxtop.top()) {
			Mintop.push(Maxtop.top());
			Maxtop.pop();
			Maxtop.push(Mintop.top());
			Mintop.pop();
		}

		cout << Maxtop.top() << "\n";
	}

	return 0;
}
