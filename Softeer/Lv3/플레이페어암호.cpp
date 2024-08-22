 /* https://softeer.ai/practice/6255 [HSAT 3ȸ ���� �ڵ� ������ ����] �÷������ ��ȣ
 * 
 *  1h 52m 58s	�� ���� ���� �� ������ X �߰��ΰ� �𸣰� �ð� ������ ��;;
 * 
 * ����: �÷������ ��ȣ�� ���ĺ����� �Ʒ���� � ���ڿ��� ��ȣȭ�ϴ� ���
 *	���ĺ����� �̷���� ���ڿ��� Ű�� �ʿ�
 *	�ѹ��� �� ���� ������ ��ȣȭ�� ����
 *	5x5 ũ���� ǥ�� ����ϹǷ� ���ĺ� i. j�� ���� �� ������ ����(������ j�� �־����� ����)
 *	
 *		1. �־��� Ű�� 5x5 ũ���� ǥ�� ��ȯ
 *		2. Ű�� �� ���ھ� ���鼭 ���� ��ĭ ���� ���پ� ä�� (���� ������ �ô� ���ĺ��� �ѹ� �� �����ϸ� �����ϰ� ���� ���� ��)
 *		3. Ű�� �� ���� ĭ�� ���´ٸ� ���� �������� ���� ���ĺ��� ������� ä��
 *		4. ��ȣȭ �Ϸ��� �޼����� �� ���� �� ���� (���� LL(������ OW)�� ���� ���� ���ڷ� �̷���� ���̶�� LX LO�̰� ���� XX��� X ��� Q)
 *			4-1. ���� ���ĺ� ���� ������ �ڿ� X�� ����
 *		5. 4���� ���� ���� ��ȣȭ
 *			5-1. ���� �� ���ڰ� ǥ���� ���� x�� �����ϸ� ���������� ��ĭ �̵��� ĭ�� ���� ���ڷ� ��ȣȭ(���� y�� 5��� y�� 1�� ��)
 *			5-2. ���� ��츦 �������� �����鼭 �� ���ڰ� ���� y�� �����ϸ� �Ʒ��� ��ĭ �̵��� ĭ�� ���� ���ڷ� ��ȣȭ (���� x�� 5�� x�� 1�� ��)
 *			5-3. ���� ��츦 �������� �ʰ� �� ���ڰ� ���� �ٸ� x, y�� ���� �Ѵٸ� �� ���ڰ� ��ġ�ϴ� ĭ�� y�� ��ȯ��
 * 
 * �Է�: J�� ������ ���ĺ� �빮�ڷ� �̷���� �޼���
 *	J�� ������ ���ĺ� �빮�ڷ� �̷���� Ű
 * 
 * ���: ��ȣȭ�� ���
 * 
 * Ǯ��: ���ĺ� �ϳ��� ��� �迭 ����� ������ flag[27]�� �����ϰ�, �빮�� ���ĺ� char - '@'�� int ��ȯ�� 10���� (A = 1, B = 2...)�� ���� Ȱ���� flag[ky[i]-'@']�� üũ
 *	5x5�� ���ڸ� �Է��� �� map�� �̿��� ���ڿ� x,y ��ǥ�� ����������
 *	���� ���ڸ� ���ڿ� �Է��� �� cnt / 5, cnt % 5�� �̿��Ͽ� x,y�� ã�� ��
 *	string(1, a) + 'a'�� �̿��Ͽ� ���ڿ��� ����� �̸� ť�� ����
 *	ť�� ����� ���ڿ��� ���� ���ڷ� ���� map�� �̿��� x,y ��ǥ�� ã��
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