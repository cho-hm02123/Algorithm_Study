#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;

int n,m,mm,k;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < n; i++) {
		k++;
		mm = arr[i] * k;
		m = max(m, mm);
	}
	cout << m;
	return 0;
}
