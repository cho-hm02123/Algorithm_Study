/*
  mid 를 (st+en)/2로 두면 무한루프레 빠질 수 있음
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int k,n;
int arr[10001];

bool cal(long long m) {
	long long cur = 0;
	for (int i = 0; i < k; i++)
		cur += arr[i] / m;
	return cur >= n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	sort(arr, arr + k);
	long long st = 1;
	long long en = 0x7fffffff;

	while (st < en) {
		long long mid = (st + en + 1) / 2;
		if (cal(mid)) st = mid;
		else en = mid - 1;
	}
	cout << st;
	return 0;
}
