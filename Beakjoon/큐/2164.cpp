#include <istream>
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	int j = 0;
	int i = 1;
	queue<int> q;
	
	cin >> N;
	int a = N;
	while (N--) {
		q.push(i);
		i++;
	}
	
	while(q.size()!=1) {
		if (j % 2 == 0) {
			q.pop();
			j++;
		}
		else {
			q.push(q.front());
			q.pop();
			j++;
		}
	}

	cout << q.back();

	return 0;
}
