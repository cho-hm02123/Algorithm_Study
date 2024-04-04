/*
  하 개어려움
  1. 백트래킹으로 누가 먼저 수확할지 경우의 수 다 구하기
  2. 경로 저장법 구현함 -> DFS로 탐색하면서 Tuple에 시간 저장도 같이 하고 vs에 경로 저장함
*/


#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
#define X first
#define Y second

int n, m;
int sumf;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int map[25][25];
int pri[5];
int arr[5];
bool flag[5];
vector <pair <int, int>> v_in;
vector <pair <int, int>> v_out;
deque <tuple <int, int, int>> q;

int sav() {
	bool check[25][25] = { 0, };
	for (int i = 0; i < m; i++) {
		int mm = 0;
		vector <pair<int, int>> v;
		v.clear();
		vector <pair<int, int>> vs;
		q.push_back({ v_out[i].X,v_out[i].Y,0 });

		while (!q.empty()) {
			tuple <int, int, int> cur = q.front(); q.pop_front();
			if (v.size() == get<2>(cur))
				v.push_back({ get<0>(cur), get<1>(cur) });
			else {
				while (!(v.size() == get<2>(cur)))
					v.pop_back();
				v.push_back({ get<0>(cur), get<1>(cur) });
			}
			if (get<2>(cur) == 3) {
				bool flag[25][25] = { 0, };
				int sum = 0;
				for (int j = 0; j < 4; j++) {
					if (flag[v[j].X][v[j].Y] == 1 || check[v[j].X][v[j].Y] == 1);
					else
						sum = sum + map[v[j].X][v[j].Y];
					flag[v[j].X][v[j].Y] = 1;
				}
				if (sum > mm) {
					mm = sum;
					vs.clear();
					vs.resize((int)(v.size()));
					copy(v.begin(), v.end(), vs.begin());
				}
			}

			for (int j = 0; j < 4; j++) {
				int x = dx[j] + get<0>(cur);
				int y = dy[j] + get<1>(cur);

				if (x < 1 || y < 1 || x > n || y > n || get<2>(cur) == 3) continue;
				q.push_front({ x,y,get<2>(cur) + 1 });
			}
		}
		pri[i] = mm;
		for (int j = 0; j < 4; j++)
			check[vs[j].X][vs[j].Y] = 1;
	}
	int sum = 0;
	for (int i = 0; i < m; i++)
		sum += pri[i];
	sumf = max(sumf, sum);

	return 0;
}

void cal(int k) {
	if (k == m) {
		v_out.clear();
		for (int i = 0; i < m; i++) 			
			v_out.push_back({ v_in[arr[i]].X, v_in[arr[i]].Y });
		sav();
		return;
	}

	for (int i = 0; i < m; i++) {
		if (!flag[i]) {
			arr[k] = i;
			flag[i] = 1;
			cal(k + 1);
			flag[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
			cin >> map[i][j];

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v_in.push_back({ a, b });
	}

	cal(0);

	cout << sumf;

	return 0;
}
