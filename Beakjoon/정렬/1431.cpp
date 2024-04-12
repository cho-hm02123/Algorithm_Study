/*
  #include <cctype> 에 isdigit을 사용하면 문자열에서 숫자인것만 찾을 수 있음
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int n;
string s;
vector <string> v;

bool cmp(string &a, string &b) {
	int anum = a.size(), bnum = b.size();

	if (anum != bnum) return anum < bnum;

	int asum = 0, bsum = 0;
	for (int i = 0; i < anum; i++) {
		if (isdigit(a[i]))
			asum += (a[i] - '0');
	}
	for (int i = 0; i < bnum; i++) {
		if (isdigit(b[i]))
			bsum += (b[i] - '0');
	}
	if (asum != bsum) return asum < bsum;

	return a < b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	while (n--) {
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}
