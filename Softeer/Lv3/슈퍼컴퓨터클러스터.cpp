/* https://softeer.ai/practice/6252 [HSAT 4ȸ ���� �ڵ� ������ ����] ������ǻ�� Ŭ������
* 
* 1h 14m 33s	�ƴ� �� return false�� for�� �ȿ� ���� �°� �ۿ� ���� Ʋ��?? �̰� ������ 45�� ��Ƹ���;;
* 
* ����: �������� ��ǻ�͸� �ϳ��� Ŭ�����ͷ� ���� ����� ����
*	Ŭ�������� ������ ��ǻ���� ���� ������ ����, ������ ������ �ö� ���� ���
*	Ŭ�������� ������ ���׷��̵� �� �޶� �ٵ� Ŭ�����͸� �̷�� ������ ��ǻ�� �� ������ ���� ���� ��ǻ���� ������ ���� ��
*	Ŭ�����Ϳ� N���� ��ǻ��, ������ ������ a_i��� ������ ��
*	������ ��ǻ�Ϳ� ����� �鿩 ���׷��̵� ���� ��, �� ��ǻ�͸� �ι� �̻� ���׷��̵� �Ұ�
*	������ d ����Ű�µ� ��� ����� pow(d, 2)��
*	���׷��̵带 ���� ������ b��, ������ ���� ���� ��ǻ���� ������ �ִ�ȭ �ϴ� ���� ��ǥ
*	�ּ��� ���� ������ ����ض�
* 
* �Է�: N, b(long long)
*	N���� ��ǻ�� ����
* 
* ���: ������ ȿ�������� ���� �� ������ ���� ���� ��ǻ���� ���� �ִ밪
* 
* Ǯ��: ���� Ž�� �� 10^5(N) x 10^9(ai) = 10^14�̹Ƿ� 3*10^9 ���� Ŀ �ð� �ʰ� ���� �̺�Ž�� ���
*	�̺� Ž�� �߿��� parametic search�� ���.
*	���� ū ���׷��̵� ������ ��Ʈ(b) �̹Ƿ� en = ��Ʈ(b), st = 0���� �����Ͽ� �̺�Ž��
*	mid + arr[0] ���� ������ ������ ��ǻ�ʹ� ��� ���׷��̵� �ؾ� �ϹǷ� �̶��� ����� ���
*	�ش� ����� b�� �Ѵ����� ���� st, en�� �缳��
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long

int n;
ll arr[100001];
ll b;

bool cal(ll k) {
	ll mini = arr[0] + k;
	ll sum = 0;

	if (k == 0) return true;

	for (int i = 0; i < n; i++) {
		if (arr[i] < mini)
			sum += (ll)pow(mini - arr[i], 2);
		else
			break;
		if (sum > b) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> b;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	ll st = 0;
	ll en = (ll)sqrt(b);

	while (st < en) {
		ll mid = (st + en + 1) / 2;
		if (cal(mid)) // ������ b���� �۰ų� ����
			st = mid;
		else
			en = mid - 1;
	}

	cout << arr[0] + (st + en + 1) / 2;

	return 0;
}