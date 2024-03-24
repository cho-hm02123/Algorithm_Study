#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

queue <int> q;

int N;
int m = 1000000;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	while (N--) {
		int n;
		cin >> n;
		if (q.empty())
			q.push(n);
		else {
			q.push(n);
			if (n - q.front() == m)
				cnt++;
			else if (n - q.front() < m) {
				cnt = 1;
				m = n - q.front();
			}
			q.pop();
		}
	}

	cout << cnt;

	return 0;
}
