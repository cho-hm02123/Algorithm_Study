/*
문제 : 입력이 1 ~ 8 순서면 'ascending', 8 ~ 1 순서면 'descending', 둘 다 아니면 'mixed' 출력
입력 : 1 ~ 8 자연수 8개

풀이 : 
 ascending인 경우 vector 생성, descending인 경우 vector 생성
두 배열을 '=='으로 비교하기 위해 vector 사용
*/

#include <istream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> a = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> d = { 8, 7, 6, 5, 4, 3, 2, 1 };
	vector<int> in(8);

	for (int i = 0; i < 8; i++) 
		cin >> in[i];

	if (in == a) 
		cout << "ascending";
		
	else if (in == d) 
		cout << "descending";
		
	else
		cout << "mixed";
		

	return 0;
}
