/*
  예외처리 if (en == n) break; 주의
  min값 토기 설정 주의
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int mm = 0x7fffffff;
	int en = 0;

	for (int st = 0; st < n; st++) {
		while (en < n && arr[en] - arr[st] < m) en++;
		if (en == n) break;
		mm = min(mm, arr[en] - arr[st]);
	}

	cout << mm;

	return 0;
}
