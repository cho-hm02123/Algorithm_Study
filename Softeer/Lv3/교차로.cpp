/* https://softeer.ai/practice/6256 [HSAT 3ȸ ���� �ڵ� ������ ����] ������
* 
*  2h01m41s		�ð��ʰ� ��ģ���� + ���� ���� ���������
* 
* ����: �����ο����� ������ ����
*	�ڵ������� �浹�� ������ �� �ֵ��� ���� ������ �����ֵ�, �ʹ� ���� �������� �ʰ�
*	�������� �� �� ������ �ڽ� ���� ������ �����ο� ���� ������ 1�� ���� ������� ����
*	���� 4���� ������ ��� ���� ������ ��� ������ ������ �� ����
*	N���� ������ A, B, C, D ��ġ�� ������ ������ ��, i��° ������ t_i�ʿ� w_i ��ġ�� �����Ͽ� �ش� ������ �� �� �ٿ� �ִ´�. (ȥ�� ������ ���� ���� �ð��� �� ��ġ�� ������ �� �ִ� ������ �ִ� �Ѵ�
*	�� �ʸ��� ������ ������ ����, �� ��ġ�� �� �� ���� �����ʿ� ���� �ִ��� Ȯ�� �� ������ ������ ������ ���
*	�� ġ���� �����θ� ����ϴ� �ð��� �������� ���
* 
* �Է�: N(2 �̻� 200,000����)
*	N���� �� �� i��° �ٿ� t_i�� w_i
* 
* ���: N���� ����� ��� i�� ������ ����ϸ� ����ϴ� �ð�, ������� ���Ѵٸ� -1
* 
* Ǯ��: ���� �迭�� �ʿ� ����
*	1. �� �����ο� ���� ��ȣ�� �ð��� ������ �� ť�� ����
*	2. ���� �ð��� 0����
*	3. �ð��� 1�� ������Ű�� �ð� �ʰ��� ���Ƿ� timeshift �Լ��� ����
*		3-1. ���� ������ ť front ������ �ð� �ּҰ��� �� �ð����� ũ�� ���� �ð��� �ش� �ð����� �ٲ� (���� �ð��� ������ �ð� �ּҺ��� �۴ٴ°� �����ο� ���� �Ѵ뵵 ���ٴ� ��)
*	4. �����ο� ����ϰ� �ִ� ������ ������ �� �ִ��� �Ǵ��ϴ� �Լ� ����
*		4-1. ���� �����ο� ��� ������ �ְ� ������ �����ο� ��������� ������ flag�� true��
*		4-2. ��� ������ ���ٴ� �� �ش� ������ ť�� ��� �ְų� ť front�� �ð��� ���� �ð����� ũ�� (ť front�� �ð��� ���� �ð����� ũ�� ���� ����Ϸ� �ȿ� ���� ��, �����)
*	5. ������ �̵���Ű�� �Լ� ����
*		5-1. 4�� ���� ������ ������ (flag�� 1�̸� �̵��� �� ����)
*		5-2. ���� ������ �� �ִ� ���� ������ �������� �̹Ƿ� ���� (3���� �ð��� ��� ������Ʈ ���ֹǷ� ť�� ���� ��������� ���ο� ��� ������ ���� ��Ȳ�� �߻����� ����)
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 200000
#define MAX_T 0x7fffffff

struct tn {
	int n, t;
};

int n, cur;
int rst[MAX + 2];
queue <tn> q[4]; // ������ ��ȣ A = 3, B = 2, ... char - 'A'

int timeshift() {
	int time_a, time_b, time_c, time_d;
	if (!q[0].empty()) time_d = q[0].front().t; else time_d = MAX_T;
	if (!q[1].empty()) time_c = q[1].front().t; else time_c = MAX_T;
	if (!q[2].empty()) time_b = q[2].front().t; else time_b = MAX_T;
	if (!q[3].empty()) time_a = q[3].front().t; else time_a = MAX_T;

	int new_time = min({ time_a, time_b, time_c, time_d });
	if (new_time < cur) return cur;
	return new_time;
}

void judgego(bool state[]) {
	for (int i = 0; i < 4; i++) {
		if (!q[i].empty() && q[i].front().t <= cur) {
			if (q[(i + 1) % 4].empty())
				state[i] = true;
			else if (q[(i + 1) % 4].front().t > cur)
				state[i] = true;
		}
	}
}

bool gocar(bool state[]) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (state[i]) {
			rst[q[i].front().n] = cur;
			q[i].pop();
		}
		else
			cnt++;
	}
	if (cnt == 4) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		char b;
		cin >> a >> b;
		int c = b - 'A';
		q[3-c].push({i, a});
	}

	fill(rst, rst + n, -1);

	while (!q[0].empty() || !q[1].empty() || !q[2].empty() || !q[3].empty()) {
		bool state[4] = { false, false, false, false };
		cur = timeshift();	// �ð� �̵�(�ȱ׷� �ð��ʰ�)
		judgego(state);		// ���ο� ���� �� �� �ִ��� �Ǵ�
		if (gocar(state))	// ���ΰ� �����θ� ������ �԰� ���ÿ� �������¸� �ݺ��� Ż��
			break;
		cur++;
	}

	for (int i = 0; i < n; i++)
		cout << rst[i] << "\n";

	return 0;
}