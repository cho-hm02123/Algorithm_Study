#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int M, N, K;
int arr[102];
int arr2[103];
int flag, num;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N >> K;

	for (int i = 0; i < M; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
		cin >> arr2[i];

	for (int i = 0; i < N; i ++ ) {
		if (arr2[i] == arr[flag]) {
			if (flag == M - 1) {
				cout << "secret";
				return 0;
			}
			flag++;
		}
		else {
			flag = 0;
			num ++;
			i = num-1;
		}
	}

	cout << "normal";
	
	return 0;
}
