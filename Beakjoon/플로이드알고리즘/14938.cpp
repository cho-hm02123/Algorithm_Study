#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, r;
int item[101];
int arr[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> r;
	for (int i = 1; i < n + 1; i++)
		cin >> item[i];

	for(int i = 1; i < n+1; i++)
		for (int j = 1; j < n + 1; j++) {
			if (i == j) arr[i][j] = 0;
			else
				arr[i][j] = INF;
		}

	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		arr[a][b] = l;
		arr[b][a] = l;
	}

	for(int k = 1; k < n+1; k++)
		for(int i = 1; i < n+1; i++)
			for (int j = 1; j < n + 1; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}

	int mx = 0;
	for (int i = 1; i < n + 1; i++) {
		int sum = 0;
		for (int j = 1; j < n + 1; j++) {
			if (arr[i][j] <= m)
				sum += item[j];
		}
		mx = max(sum, mx);
	}

	cout << mx;
	return 0;
}
