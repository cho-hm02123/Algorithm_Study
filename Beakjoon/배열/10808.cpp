/*
문제 : 알파벳 문자열을 받아 각 알파벳이 몇개씩 있는지 출력
입력 : 소문자 100개 이하의 문자열

풀이 : 
 알파벳이 모두 저장되어있는 배열 생성, 문자열을 char로 저장할 배열 생성, 개수 저장 배열 생성
입력받은 문자열을 strcpy를 이용하여 char형으로 변환하여 배열에 저장 -> #include <cstring> (visual studio에서는 strcpy_s로 해야했지만 백준에선 _s를 하면 에러남)
.length()를 이용하여 string 길이 파악
*/

#include <iostream>
#include <istream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string S;
	char c[100] = {0, };
	char a[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	int check[26] = { 0, };

	cin >> S;

	strcpy(c, S.c_str());

	for (int i = 0; i < S.length(); i++) {
		for (int j = 0; j < 26; j++) {
			if (c[i] == a[j]) {
				check[j]++;
				break;
			}
		}
	}

	for (int j = 0; j < 26; j++)
		cout << check[j] << " ";

	return 0;
}
