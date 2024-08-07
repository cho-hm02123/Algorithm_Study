/* https://www.acmicpc.net/problem/1822
* 
* 09m 09s
* 
* 문제: 몇 개의 자연수로 이루어진 두 집합 A, B
*	A 집합에는 속하면서 B 집합에는 속하지 않는 모든 원소를 구해라
* 
* 입력: A 집합 원소 개수, B집합 원소 개수
*	A 집합의 원소
*	B 집합의 원소 (ll 써야 함)
* 
* 출력: A 집합에 속하면서 B 집합에 속하지 않는 원소의 개수
*	해당 원소를 증가하는 순으로
*	만약 그런게 없으면 0 출력 후 종료
* 
* 풀이: va, vb 오름차순 정렬 후 binary_search 이용해서 vb에 va의 원소가 있나 확인
*	만약 없다면 v에 해당 원소를 저장
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define LL long long

int na, nb;
vector <LL> va;
vector <LL> vb;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> na >> nb;
	for (int i = 0; i < na; i++) {
		int a;
		cin >> a;
		va.push_back(a);
	}

	for (int i = 0; i < nb; i++) {
		int a;
		cin >> a;
		vb.push_back(a);
	}
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	vector <LL> v;
	for (int i = 0; i < na; i++) {
		if (!binary_search(vb.begin(), vb.end(), va[i]))
			v.push_back(va[i]);
	}

	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}
