#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;

#define X first
#define Y second

int W, N;
list <pair <int, int>> l;

int cal() {
	int f = 0;
	if (W <= l.back().Y)
		return l.back().X * W;

	while (1) {
		if (W > l.back().Y) {
			f += l.back().Y * l.back().X;
			W = W - l.back().Y;
			l.pop_back();
		 }
		else if (W <= l.back().Y) {
			f += l.back().X * W;
			break;
		}
	}
	return f;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> W >> N;
	int a = N;
	while (N--) {
		int w, p;
		cin >> w >> p;
		l.push_back({ p, w });
	}
	l.sort();

	cout << cal();
	
	return 0;
}
