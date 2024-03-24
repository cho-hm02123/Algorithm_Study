#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int map[3][3];
int cost[6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}

	if ((map[0][0] == map[0][1] && map[0][1] == map[0][2]) || (map[1][0] == map[1][1] && map[1][1] == map[1][2]) 
		|| (map[2][0] == map[2][1] && map[2][1] == map[2][2]) || (map[0][0] == map[1][0] && map[1][0] == map[2][0])
		|| (map[0][1] == map[1][1] && map[1][1] == map[2][1]) || (map[0][2] == map[1][2] && map[1][2] == map[2][2])) {
		cout << "0";
		return 0;
	}

	cost[0] = map[0][0] + map[0][1] + map[0][2];
	cost[1] = map[1][0] + map[1][1] + map[1][2];
	cost[2] = map[2][0] + map[2][1] + map[2][2];
	cost[3] = map[0][0] + map[1][0] + map[2][0];
	cost[4] = map[0][1] + map[1][1] + map[2][1];
	cost[5] = map[0][2] + map[1][2] + map[2][2];

	for (int i = 0; i < 6; i++) {
		if (cost[i] == 4 || cost[i] == 7 || cost[i] == 8 || (cost[i] == 5 && (map[2][0] == 2 || map[2][1] == 2 || map[2][2] == 2))) {
			cout << "1";
			return 0;
		}
		else if (cost[i] == 5 || cost[i] == 6) {
			cout << "2";
			return 0;
		}
	}
}

//조합이 1,1,2(4) 이면 1 / 1,1,3(5) 이면 2 / 1,2,2(5) 이면 1 / 1,2,3(6) 이면 2 / 2,2,3(7) 이면 1 / 2,3,3(8) 이면 1
