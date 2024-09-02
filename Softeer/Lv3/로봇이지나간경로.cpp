/* https://softeer.ai/practice/6275 [HSAT 1ȸ ���� �ڵ� ������ ����] �κ��� ������ ���
* 
* 1h 34m 32s
* 
* ����: H�� W���� 2���� ����(1���� ����), ��(��) ��(��) ��(��) ��(��) �� �� ������ �ٶ� �� ����
*	�κ��� �̵� ���� ���
*		L: �κ��� �������� 90�� ȸ��
*		R: �κ��� ���������� 90�� ȸ��
*		A: �κ��� �ٶ󺸴� �������� ��ĭ ���� > �κ��� ���� ������ ������ ���� �Ұ�
* 
*	�κ��� ���� ĭ�� �ι� �̻� �湮���� �ʵ��� �κ��� �湮�� ��� ĭ(����� ����)�� ������ ǥ��
*	�ش� ǥ�ø� ���� �Ʒ� ������ ����� �ִ� ���α׷��� ����
*		1. ó�� �κ��� � ĭ��, � �������� �־� �ϴ���
*		2. ���� �κ��� � ������ � ������ �Է��ؾ� �ϴ���
*	�̶� ����� �Է��� �ּ�ȭ (ó�� �κ��� ��� ��� �������� �δ����� ���� �޶���)
* 
*	���� ����
*		5 <= H, W <= 25
*		A�� �̻��� ����� ���� �κ��� �湮 ĭ ���� �ּ� 3�� �̻�
* 
* �Է�: H, W
*	���� ���� (�湮������ #, �ƴϸ� .)
* 
* ���: �� ���� ���� a, b�� ������ �ϳ� ���̿� �ΰ� ��� (ó�� �κ� ��ġ)
*	�κ��� �ٶ󺸴� ���� ( ��: > / ��: < / ��: v / ��: ^)
*	�κ��� ������ �ϴ� ��ɾ ���� ���� ���
* 
* Ǯ��: ������ 4���� �� �ϳ��� #�� ���� ����� �ĺ�
*	����� �ĺ� ������ �� ��� ã�� �ѹ� �鸰 ���� �鸮�� �ȵǹǷ� .���� �ٲ��ֱ�
*	�� Ǯ�̰� ������ ������ �ߺ� �湮�� �ȵǹǷ� ���� ��ġ�� ��Ȳ�� ���� �� ����
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct xyd {
	int x, y, dir;
	string s;
};

const int MAX = 25;
int h, w;
int mm = 0x3f3f3f3f;
int dx[4] = { 0, 1, 0, -1 };	// �� �� �� ��
int dy[4] = { 1, 0, -1, 0 };
int direc[3] = { 0, 1, -1 };	// �״��, R, L
char arr[MAX + 2][MAX + 2];
xyd ans;
vector <xyd> v;

bool judmap(int x, int y) {
	if (x < 1 || y < 1 || x > h || y > w) return true;
	return false;
}

void stcheck(){
	string a;
	for(int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			int cnt = 0;
			int vec = -1;
			if (arr[i][j] == '.') continue;
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];

				if (judmap(x, y)) continue;
				if (arr[x][y] == '#') {
					cnt++;
					vec = k;
				}
			}
			if (cnt == 1)
				v.push_back({ i, j, vec, a});
		}
}

xyd findrst(int id) {
	xyd thisrst = v[id];

	char cp[MAX + 2][MAX + 2];
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cp[i][j] = arr[i][j];

	queue <xyd> q;
	q.push(v[id]);

	while (!q.empty()) {
		xyd cur = q.front(); q.pop();
		string sum = cur.s;

		for (int i = 0; i < 3; i++) {
			int vec = cur.dir + direc[i];

			if (vec < 0)
				vec = 3;
			else if (vec > 3)
				vec = 0;

			int xx = cur.x + dx[vec];
			int yy = cur.y + dy[vec];
			int x = cur.x + 2 * dx[vec];
			int y = cur.y + 2 * dy[vec];

			if (judmap(x, y) || judmap(xx, yy)) continue;
			if (cp[x][y] == '#' && cp[xx][yy] == '#') {
				if (i == 1)
					sum += string(1, 'R');
				else if (i == 2)
					sum += string(1, 'L');

				sum += string(1, 'A');

				cp[cur.x][cur.y] = '.';
				cp[xx][yy] = '.';
				q.push({ x, y, vec, sum });
			}
		}
		if (q.empty())
			thisrst.s = sum;
	}

	return thisrst;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> h >> w;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> arr[i][j];

	stcheck();
	for (int i = 0; i < v.size(); i++) {
		xyd bi = findrst(i);
		if (bi.s.size() != 0 && bi.s.size() < mm) {
			mm = bi.s.size();
			ans = bi;
		}
	}

	cout << ans.x << " " << ans.y << "\n";
	if (ans.dir == 0)
		cout << ">\n";
	else if (ans.dir == 1)
		cout << "v\n";
	else if (ans.dir == 2)
		cout << "<\n";
	else
		cout << "^\n";
	cout << ans.s;

	return 0;
}