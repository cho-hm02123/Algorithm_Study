#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int arr[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++) {
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = INF;
		}

	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		arr[a][b] = min(arr[a][b], cost);
	}

	for (int k = 1; k < n + 1; k++)
		for (int i = 1; i < n + 1; i++)
			for (int j = 1; j < n + 1; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (arr[i][j] == INF) cout << "0 ";
			else
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
