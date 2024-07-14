#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int num[3];
int arr[2200][2200];

int fin(int sx, int ex, int sy, int ey) {
	int k = 0;
	int f = (ex - sx+1)*(ex-sx+1);
	int a = arr[sx][sy];
	for (int i = sx; i < ex+1; i++) {
		for (int j = sy; j < ey+1; j++) {
			if (a != arr[i][j]) {
				fin(sx,								sx - 1 + (ex - sx + 1)/3,		sy,								sy - 1 + (ey - sy + 1) / 3);
				fin(sx,								sx - 1 + (ex - sx + 1)/3,		sy + (ey - sy + 1) / 3,			sy - 1 + (ey - sy + 1) * 2 / 3);
				fin(sx,								sx - 1 + (ex - sx + 1)/3,		sy + (ey - sy + 1) * 2 / 3,		ey);

				fin(sx + (ex - sx + 1) / 3,			sx - 1 + (ex - sx + 1) *2 / 3,	sy,								sy - 1 + (ey - sy + 1) / 3);
				fin(sx + (ex - sx + 1) / 3,			sx - 1 + (ex - sx + 1) * 2 / 3, sy + (ey - sy + 1) / 3,			sy - 1 + (ey - sy + 1) * 2 / 3);
				fin(sx + (ex - sx + 1) / 3,			sx - 1+ (ex - sx + 1) * 2 / 3, sy + (ey - sy + 1) * 2 / 3,		ey);

				fin(sx + (ex - sx + 1) * 2 / 3,		ex,							sy,								sy - 1 + (ey - sy + 1) / 3);
				fin(sx + (ex - sx + 1) * 2 / 3,		ex,							sy + (ey - sy + 1) / 3,			sy - 1 + (ey - sy + 1) * 2 / 3);
				fin(sx + (ex - sx + 1) * 2 / 3,		ex,							sy + (ey - sy + 1) * 2 / 3,		ey);
				return 0;
			}
			else
				k++;
		}
	}

	if (f == k)
		num[a + 1]++;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i < n+1; i++)
		for (int j = 1; j < n+1; j++)
			cin >> arr[i][j];

	fin(1, n, 1, n);

	for (int i = 0; i < 3; i++)
		cout << num[i] << "\n";

	return 0; 
}
