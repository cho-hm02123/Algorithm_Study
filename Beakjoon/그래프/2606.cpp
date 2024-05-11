#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int n, m, num;
bool flag[101];
vector <int> v[101];
stack <int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	s.push(1);
	while (!s.empty()) {
		int cur = s.top(); s.pop();
		if (flag[cur]) continue;

		flag[cur] = 1;
		num++;
		for (int i = 0; i < v[cur].size(); i++) {
			int x = v[cur][i];
			if (flag[x]) continue;
			s.push(x);
		}
	}

	cout << num-1;

	return 0;
}
