#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[1001];
int m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	vector <int> v;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v.push_back(arr[i] + arr[j]);

	sort(v.begin(), v.end());

	for(int i= n-1; i > -1; i--)
		for (int j = 0; j < n; j++) {
			if (binary_search(v.begin(), v.end(), arr[i] - arr[j])) {
				cout << arr[i];
				return 0;
			}
		}

	return 0;
}
