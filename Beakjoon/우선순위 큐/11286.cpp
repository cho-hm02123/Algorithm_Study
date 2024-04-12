#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
int n;

class cmp {
public:
	bool operator() (int a, int b) {
		if (abs(a) != abs(b)) return abs(a) > abs(b);
		return a > 0 && b < 0;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	priority_queue<int, vector<int>, cmp> pq;

	cin >> n;

	while (n--) {
		int x;
		cin >> x;

		if (x == 0) {
			if (pq.empty())
				cout << "0 \n";
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
