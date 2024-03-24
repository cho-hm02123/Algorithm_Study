#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second
int T;
queue <pair <int, int>> q;
pair<int, int> n;
int m = 1001;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	while (T--) {
		cin >> n.X >> n.Y;
		if (n.Y <= m) {
			if (q.empty())
				q.push({ n.X, n.Y });
			else {
				q.pop();
				q.push({ n.X, n.Y });
			}
			m = n.Y;
		}
	}
	cout << q.front().X << " " << q.front().Y;

	return 0;
}
