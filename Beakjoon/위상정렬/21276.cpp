/* https://www.acmicpc.net/problem/21276 계보 복원가 호석
* 
* 
* 문제: 석호촌에 N명의 사람
*	각 가문은 한 명의 시조를 루트로 하는 트리 형태
*	이를 기반으로 몇 개의 가문이 존재했는지
* 
* 입력: 석호촌에 사는 사람 수 N, 살고 있는 사람의 이름 (모든 이름은 길이 1 이상 6이하의 알파벳 소문자)
*	기억하는 정보의 개수 M, M개의 X Y 꼴의 계보 - X의 조상 중에 Y가 있다
*	
* 출력: 첫번쨰 줄 - 가문의 개수 K
*	두번째 줄 - 각 가문의 시조의 이름을 공백으로 구분하여 사전 순으로 출력
*	세번째 줄 - 사전순대로 이름과 자식의 수, 자식의 이름을 공백으로 구분해서 사전순으로
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int n, m, cnt;
int indegree[1001];
string name[1001];
map <string, int> nametoi;
vector <int> v[1001];
vector <int> gamoon[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> name[i];
	sort(name + 1, name + n + 1);
	for (int i = 1; i <= n; i++)
		nametoi[name[i]] = i;

	cin >> m;
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		v[nametoi[b]].push_back(nametoi[a]);
		indegree[nametoi[a]]++;
	}

	vector <int> js;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i])
			js.push_back(i);
	}

	cout << js.size() << "\n";
	for (int nxt : js)
		cout << name[nxt] << " ";

	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());

		for (int nxt : v[i])
			if (indegree[nxt] - indegree[i] == 1)
				gamoon[i].push_back(nxt);
	}

	for (int i = 1; i <= n; i++) {
		cout << "\n" << name[i] << " " << gamoon[i].size() << " ";
		if (!gamoon[i].size()) continue;
		for (int nxt : gamoon[i])
			cout << name[nxt] << " ";
	}

	return 0;
}
