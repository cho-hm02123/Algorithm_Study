#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define X first
#define Y second

int s, g, k, ss, sg, cnt, num;
bool book[45][45];
int st[11][11];
vector <pair<int, int>> v;

void turn() {
	int cst[11][11];
	cnt++;
	v.clear();

	for (int i = 0; i < ss; i++)
		for (int j = 0; j < sg; j++)
			cst[i][j] = st[i][j];


	for (int i = 0; i < sg; i++)
		for (int j = 0; j < ss; j++) {
			st[i][j] = cst[ss - j - 1][i];
			if (st[i][j] == 1)
				v.push_back({ i,j });
		}
	swap(ss, sg);
}

bool check() {
	while (1) {
		for (int i = 0; i < s; i++)
			for (int j = 0; j < g; j++) {
				int n = 0;
				for (int h = 0; h < v.size(); h++) {
					if (i + v[h].X > s - 1 || j + v[h].Y > g - 1) break;
					if (book[i + v[h].X][j + v[h].Y] == 0) n++;
					else
						break;
				}
				if (n == v.size()) {
					for (int h = 0; h < v.size(); h++)
						book[i + v[h].X][j + v[h].Y] = 1;
					return true;
				}
			}
		if (cnt < 3) turn();
		else if (cnt == 3)
			return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> s >> g >> k;
	for (int i = 0; i < k; i++) {
		cnt = 0;
		v.clear();
		
		cin >> ss >> sg;

		for (int j = 0; j < ss; j++)
			for (int h = 0; h < sg; h++) {
				cin >> st[j][h];
				if (st[j][h] == 1)
					v.push_back({ j,h });
			}
		check();
	}

	for (int i = 0; i < s; i++) 
		for (int j = 0; j < g; j++)
			if (book[i][j] == 1) num++;

	cout << num;

	return 0;
}
