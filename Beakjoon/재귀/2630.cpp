#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int arr[130][130];
int num[2];

int fin(int sx, int ex, int sy, int ey) {
	int a = arr[sx][sy];
	int x = ex - sx + 1;
	int y = ey - sy + 1;

	for(int i = sx; i < ex+1; i++)
		for (int j = sy; j < ey + 1; j++) {
			if (arr[i][j] != a) {
				fin(sx, sx - 1 + x / 2, sy, sy - 1 + y / 2);
				fin(sx, sx - 1 + x / 2, sy + y / 2, ey);

				fin(sx + x / 2, ex, sy, sy - 1 + y / 2);
				fin(sx + x / 2, ex, sy + y / 2, ey);
				return 0;
			}
		}
	num[a]++;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
			cin >> arr[i][j];

	fin(1, n, 1, n);

	cout << num[0] << "\n" << num[1];

	return 0; 
}
