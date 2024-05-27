#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int num = 0;
	cin >> n >> m;

	deque <int> q;
	for (int i = 1; i < n + 1; i++)
		q.push_back(i);

	while (m--) {
		int a;
		cin >> a;
		
		while (q.front() != a) {
			int id = find(q.begin(), q.end(), a) - q.begin();
			if (2*id >= q.size()) {
				int cur = q.back();
				q.pop_back();
				q.push_front(cur);
			}
			else {
				int cur = q.front();
				q.pop_front();
				q.push_back(cur);
			}
			num++;
		}
		q.pop_front();
	}

	cout << num;

	
	return 0;
}
