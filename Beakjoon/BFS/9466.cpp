#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int t, n;
int v[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;
		int num = n;
		int vis[100001] = { 0, };

		for (int i = 1; i < n + 1; i++)
			cin >> v[i];

		for (int i = 1; i < n + 1; i++) {
			if (vis[i] != 0) continue;

			int k = i;

			while (1) {
				vis[k] = i;
				k = v[k];

				if (vis[k] == i) {
					while (vis[k] != -1) {
						vis[k] = -1;
						k = v[k];
					}
					break;
				}

				else if (vis[k] != 0) break;
			}
		}

		for (int i = 1; i < n + 1; i++)
			if (vis[i] == -1) num--;

		cout << num << "\n";
	}

	return 0;
}
