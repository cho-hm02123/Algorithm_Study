 /* https://softeer.ai/practice/6255 [HSAT 3회 정기 코딩 인증평가 기출] 플레이페어 암호
 * 
 *  1h 52m 58s	아 문자 남을 때 무조건 X 추가인거 모르고 시간 개많이 씀;;
 * 
 * 문제: 플레이페어 암호란 알파벳으로 아루어진 어떤 문자열을 암호화하는 방법
 *	알파벳으로 이루어진 문자열인 키가 필요
 *	한번에 두 글자 단위로 암호화를 진핸
 *	5x5 크기의 표를 사용하므로 알파벳 i. j를 동일 한 것으로 생각(문제에 j가 주어지지 않음)
 *	
 *		1. 주어진 키를 5x5 크기의 표로 변환
 *		2. 키를 한 글자씩 보면서 왼쪽 위칸 부터 한줄씩 채움 (만약 이전에 봤던 알파벳이 한번 더 등장하면 무시하고 다음 글자 봄)
 *		3. 키를 다 보고 칸이 남는다면 아직 등장하지 않은 알파벳을 순서대로 채움
 *		4. 암호화 하려는 메세지를 두 글자 씩 나눔 (만약 LL(다음은 OW)과 같이 같은 글자로 이루어진 쌍이라면 LX LO이고 만약 XX라면 X 대신 Q)
 *			4-1. 만약 알파벳 쌍이 남으면 뒤에 X를 붙임
 *		5. 4에서 나눈 쌍을 암호화
 *			5-1. 만약 두 글자가 표에서 같은 x에 존재하면 오른쪽으로 한칸 이동한 칸에 적힌 글자로 암호화(만약 y가 5라면 y는 1이 됨)
 *			5-2. 위의 경우를 만족하지 않으면서 두 글자가 같은 y에 존재하면 아래로 한칸 이동한 칸에 적힌 글자로 암호화 (만약 x가 5면 x는 1이 됨)
 *			5-3. 위의 경우를 만족하지 않고 두 글자가 서로 다른 x, y에 존재 한다면 두 글자가 위치하는 칸의 y가 교환됨
 * 
 * 입력: J를 제외한 알파벳 대문자로 이루어진 메세지
 *	J를 제외한 알파벳 대문자로 이루어진 키
 * 
 * 출력: 암호화된 결과
 * 
 * 풀이: 알파벳 하나씩 적어서 배열 만들기 귀찮아 flag[27]을 선언하고, 대문자 알파벳 char - '@'는 int 변환시 10진수 (A = 1, B = 2...)인 것을 활용해 flag[ky[i]-'@']를 체크
 *	5x5에 문자를 입력할 때 map을 이용해 문자와 x,y 좌표를 대응시켜줌
 *	또한 문자를 격자에 입력할 때 cnt / 5, cnt % 5를 이용하여 x,y를 찾아 줌
 *	string(1, a) + 'a'를 이용하여 문자열을 만들어 이를 큐에 저장
 *	큐에 저장된 문자열을 꺼내 문자로 나눠 map을 이용해 x,y 좌표를 찾음
 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

struct xy {
	int x, y;
};

string mess, ky;
char arr[6][6];
bool flag[27];
map <char, xy> m;
queue <string> q;

void encryption() {
	while (!q.empty()) {
		string cur = q.front(); q.pop();
		int x1 = m[cur[0]].x;
		int y1 = m[cur[0]].y;
		int x2 = m[cur[1]].x;
		int y2 = m[cur[1]].y;

		if (x1 == x2) {
			y1++;
			y2++;
			y1 %= 5;
			y2 %= 5;
		}
		else if (y1 == y2) {
			x1++;
			x2++;
			x1 %= 5;
			x2 %= 5;
		}
		else
			swap(y1, y2);

		string rst = string(1, arr[x1][y1]) + arr[x2][y2];
		cout << rst;
	}
}

void divimess() {
	for (int i = 0; i < mess.length(); i++) {
		string a;
		if (i == mess.length() - 1)
			a = string(1, mess[i]) + 'X';


		else if (i < mess.length() - 1){
			if (mess[i] == mess[i + 1]) {
				if (mess[i] != 'X') a = string(1, mess[i]) + 'X';
				else a = string(1, mess[i]) + 'Q';
			}

			else {
				a = string(1, mess[i]) + mess[i + 1];
				i++;
			}
		}
		q.push(a);
	}
}

void fillgraph() {
	int cnt = 0;

	for (int i = 0; i < ky.length(); i++) {
		xy sv;
		sv.x = cnt / 5;
		sv.y = cnt % 5;
		int a = ky[i] - '@';
		if (flag[a]) continue;
		arr[sv.x][sv.y] = ky[i];
		flag[a] = 1;
		m[ky[i]] = sv;
		cnt++;
	}

	for (int i = 1; i <= 26; i++) {
		xy sv;
		sv.x = cnt / 5;
		sv.y = cnt % 5;
		if (flag[i]) continue;
		arr[sv.x][sv.y] = 64 + i;
		flag[i] = 1;
		m[arr[sv.x][sv.y]] = sv;
		cnt++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	flag[10] = 1; // 'J' - '@' == 10

	cin >> mess >> ky;

	fillgraph();
	divimess();
	encryption();

	return 0;
}
