#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

#define X first
#define Y second

int N, M;
vector <string> s;
int t[52][52];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string sss;
 		cin >> sss;
		s.push_back(sss);
	}

	sort(s.begin(), s.end());

	for (int i = 0; i < M; i++) {
		string ss;
		int start, end;

		cin >> ss >> start >> end;

		for (int j = 0; j < N; j++) {
			if (ss == s.at(j)) {
				for (int k = start; k < end; k++)
					t[j][k] = 1;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		cout << "Room " << s.at(i) << ":\n";
		int flag = 0;
		queue <int> q;
		for (int j = 9; j < 19; j++) {
			if (t[i][j] == 0) {
				if (flag == 1) continue;
				else {
					if (j == 9)
						q.push(j);
					else if (j == 18) continue;
					else
						q.push(j);
					flag = 1;
				}
			}
			else {
				if (flag == 1 && t[i][j] == 1) {
					q.push(j);
					flag = 0;
				}
			}
		}
		if (q.size() % 2 == 1 && !q.empty())
			q.push(18);
		if (q.empty())
			cout << "Not available\n";
		else {
			cout << q.size() / 2 << " available:\n";
			while (!q.empty()) {
				if (q.front() < 10)
					cout << "0" << q.front() << "-";
				else
					cout << q.front() << "-";

				q.pop();

				if (q.front() < 10)
					cout << "0" << q.front() << "\n";
				else
					cout << q.front() << "\n";
				q.pop();
			}
		}
		if (i == N - 1) continue;
		else
			cout << "-----\n";
	}
	return 0;
}
