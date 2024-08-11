/* https://www.acmicpc.net/problem/21939 문제 추천 시스템 Version 1
* 
* 31m 38s
* 
* 문제: recommend x 
*		x가 1인 경우 추천 문제 리스트에서 가장 어려운 문제 번호를 출력 -> 만약 여러개면 문제 번호가 큰걸로 출력
*		x가 -1인 경우 가장 쉬운 문제 출력 -> 여러개면 문제 번호가 작은 걸로 출력
*	add P L 
*		난이도가 L인 문제 번호 P를 추가 (추천 문제 리스트에 없는 문제 번호 P만 입력으로 주어짐????? 이전에 추천 문제 리스트에 있던 문제 번호가 다른 난이도로 들어올 수 있음)
*	soved P
*		추천 문제 리스트에 문제 번호 P를 제거 (추천 문제 리스트에 있는 문제 번호 P반 입력으로 주어짐)
* 
* 입력: 문제 리스트의 문제 개수 N, N개의 문제 번호 P와 난이도 L
*	입력될 명령문의 개수 M
* 
* 출력: recommend 명령이 들어올 때마다 문제 번호를 하나씩 출력
* 
* 풀이: 지우는거 때문에 우선순위큐는 좀...
*	레벨별, 문제 별로 정렬을 해야하므로 배열 set 선언, 인덱스는 레벨로, 이때 문제를 지워야 하는 상황도 있으니 따로 배열에 문제 난이도 저장
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

int n, p, l, m, x;	// p: 문제 번호, l: 난이도
int level[100001];	//문제 난이도 저장
set <int> mm[101]; // 난이도 별 문제 저장

int main() {
	ios_base::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> l;
		level[p] = l;
		mm[l].insert(p);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (s == "recommend") {
			cin >> x;
			if (x == 1) {
				for (int j = 100; j >= 1; j--) {
					if (mm[j].empty()) continue;
					cout << *prev(mm[j].end()) << "\n";
					break;
				}
			}
			else {
				for (int j = 1; j <= 100; j++) {
					if (mm[j].empty()) continue;
					cout << *mm[j].begin() << "\n";
					break;
				}
			}
		}

		else if (s == "add") {
			cin >> p >> l;
			level[p] = l;
			mm[l].insert(p);
		}

		else {
			cin >> p;
			l = level[p];
			mm[l].erase(p);
		}
	}

	return 0;
}
