#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

deque <pair <int, int>>q;
int N;
bool seg1[7], seg2[7], seg3[7], seg4[7], seg5[7];
bool ss[11][7] = { { 1, 1, 1, 1, 1, 1, 0 }, { 0, 0, 0, 0, 1, 1, 0 }, { 1, 0, 1, 1, 0, 1, 1 }, { 1, 0, 0, 1, 1, 1, 1 }, { 0, 1, 0, 0, 1, 1, 1 },
{ 1, 1, 0, 1, 1, 0, 1 }, { 1, 1, 1, 1, 1, 0, 1 }, { 1, 1, 0, 0, 1, 1, 0 }, { 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 0, 1, 1, 1, 1 }, {0, 0, 0, 0, 0, 0, 0} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	
	while (N--) {
		int a, b;
		int num = 0;
		cin >> a >> b;

		for(int j = 0; j <5; j++){
			int an, bn;
			an = a % 10;
			bn = b % 10;
			
			if (an != bn) {
				for (int i = 0; i < 7; i++) {
					if (an == -1) {
						if (ss[10][i] != ss[bn][i])
							num++;
					}
					else if (bn == -1) {
						if (ss[10][i] != ss[an][i])
							num++;
					}
					else {
						if (ss[an][i] != ss[bn][i])
							num++;
					}
				}
			}

			a = a / 10;
			b = b / 10;

			if (a == 0)
				a = -1;
			if (b == 0)
				b = -1;
		}
		cout << num << "\n";
	}
	return 0;
}
