/* https://www.acmicpc.net/problem/21944 문제 추천 시스템 Version 2
* 
* 49m 20s
* 
* 문제: recommend G x 
*		x가 1인 경우  문제 리스트에서 분류가 G인 문제 중 가장 어려운 문제 번호를 출력 -> 여러개라면 문제 번호가 가장 큰것 출력
*		x가 -1인 경우 알고리즘 분류가 G인 문제 중 가장 쉬운 문제 번호를 출력 -> 여러개라면 번호가 가장 작은 것 출력
* 
*	recommend2 x
*		x가 1인 경우 문제 리스트에서 알고리즘 분류와 상관 없이 가장 어려운 문제 번호 출력 -> 여러개라면 문제 번호가 가장 큰 것 출력
*		x가 -1인 경우 문제 리스트에서 분류와 상관 없이 가장 쉬운 문제 번호 출력 -> 여러개면 문제 번호가 가장 작은 것 출력
* 
*	recommend3 x L
*		x가 1인 경우 문제 리스트에서 알고리즘 분류 상관 없이 난이도 L보다 크거나 같은 문제 중 가장 쉬운 문제 번호 출력 -> 문제가 여러개라면 번호가 가장 작은 것 출력
*		x가 -1인 경우 분류 상관 없이 난이도 L보다 작은 문제 중 가장 어려운 문제 출력 -> 여러개라면 번호가 가장 큰 것 출력
*		만약 조건을 만족하는 문제가 없다면 -1 출력
* 
*	add  P L G
*		문제 리스트에 난이도가 L이고 분류가 G인 문제 번호 P를 추가
* 
*	solved P
*		문제 리스트에서 문제 번호 P를 제거
* 
* 입력: 문제의 개수 N, N가지 문제 번호 P, 난이도 L, 분류 G
*	명령문의 개수 M, M개의 명령문
* 
* 출력: recommend, recommend2, recommend3가 주어질 때 마다 문제 번호 출력 "\n"
* 
* 풀이: 문제 번호를 인덱스로 분류와 레벨을 저장하는 배열
*	분류, 레벨을 인덱스로 문제 번호를 오름차순으로 저장하는 이진검색트리 
*	분류와 상관 없이 레벨을 인덱스로 문제 번호를 오름차순으로 저장하는 이진검색트리를 생성
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

#define X first
#define Y second

int n, p, l, g, m;
pair <int, int> grouplevel[100001]; // x:분류, y:레벨
set <int> s[101][101];	// 분류, 레벨
set <int> level[101];	// 분류와 상관 없이 가장 어려운 것

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> l >> g;
		grouplevel[p]={ g,l };
		s[g][l].insert(p);
		level[l].insert(p);
	}

	cin >> m;
	while(m--){
		string com;
		cin >> com;

		if (com == "recommend") {
			int x;
			cin >> g >> x;
			if (x == 1) {
				for (int j = 100; j >= 1; j--) {
					if (s[g][j].empty()) continue;

					cout << *prev(s[g][j].end()) << "\n";
					break;
				}
			}

			else {
				for (int j = 1; j < 101; j++) {
					if (s[g][j].empty()) continue;

					cout << *s[g][j].begin() << "\n";
					break;
				}
			}
		}

		else if (com == "recommend2") {
			int x;
			cin >> x;
			if (x == 1) {
				for (int j = 100; j >= 1; j--) {
					if (level[j].empty()) continue;

					cout << *prev(level[j].end()) << "\n";
					break;
				}
			}

			else {
				for (int j = 1; j < 101; j++) {
					if (level[j].empty()) continue;

					cout << *level[j].begin() << "\n";
					break;
				}
			}
		}

		else if (com == "recommend3") {
			int x;
			int ans = -1;
			cin >> x >> l;
			if (x == 1) {
				for (int j = l; j < 101; j++) {
					if (level[j].empty()) continue;

					ans = *level[j].begin();
					break;
				}
			}

			else {
				for (int j = l - 1; j >= 1; j--) {
					if (level[j].empty()) continue;

					ans = *prev(level[j].end());
					break;
				}
			}

			cout << ans << "\n";
		}

		else if (com == "add") {
			cin >> p >> l >> g;
			grouplevel[p] = { g,l };
			s[g][l].insert(p);
			level[l].insert(p);
		}

		else {
			cin >> p;
			g = grouplevel[p].X;
			l = grouplevel[p].Y;

			s[g][l].erase(p);
			level[l].erase(p);
		}
	}

	return 0;
}
