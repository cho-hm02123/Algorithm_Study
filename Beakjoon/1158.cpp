#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue <int> q;
	int i = 0;
	int N, K;
	cin >> N;
	cin >> K;
	int j = K;

	cout << "<";

	while (N--) {
		q.push(++i);
	}

	while (!q.empty()) {
		while (K-- > 1) {
			q.push(q.front());
			q.pop();
		}

		K = j;

		if (q.size() == 1) {
			cout << q.front() << ">";
			q.pop();
		}
		else if (1 < q.size() < i) {
			cout << q.front() << ", ";
			q.pop();
		}
		else if (q.size() == i) {
			cout << q.front() << ", ";
			q.pop();
		}
	}

	return 0;
}

