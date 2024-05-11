/*
  기본적으로 최대힙 > top에 최대값 pop하면 최대값 빠짐
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int n;
priority_queue <int, vector<int>, greater<int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 0) {
			if (q.empty())
				cout << "0\n";
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else
			q.push(a);
	}

	return 0;
}
