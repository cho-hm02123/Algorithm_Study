/* https://softeer.ai/practice/6257 [HSAT 4ȸ ���� �ڵ� ������ ����] ��ٹ��� ��� ���� �����ϱ�
* 
* 1h 20m 08s
* 
* ����: ��� ������ ��ȣ ������� ����ؾ� �� �̶� �� ������ ������ �� �� ������ ���� �� ���� (���� ������)
*	������ ����ó�� �� ó�� �� ������ ���� �ʰ� ���� (���ο� ������)
*	�� �����忡 �� ������ �ٽ� ���� ���������� �̵��� �� ���� (���� �����忡�� �� ���������� �̵��ϴ� ���� ����)
*	�ӽ� �������� Ȱ���Ͽ� ������������ ������ ����� �� �ִ��� �˾� �� �� �Ұ����� ��찡 ����� ��� (0�̸� ����)
*		��) i < j < k�� ���� a_i < a_j �̰�, a_i > a_k
* 
* �Է�: ������ ũ�� N (3�̻� 5000 ����)
*	n���� ����
* 
* ���: ���� �ٸ� (i,j,k) ���� ���� ����
* 
* Ǯ��: O(5000 * 5000 * 3) = 0.75s
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

# define MAX 5000

int n, ans;
int arr[MAX + 2];
int judik[MAX + 2][MAX + 2];
long long rst[MAX+2][MAX+2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n - 2; i++)		// i, k ���� �� (���� a_i > a_k�� �����ϸ� judik�� 1)
		for (int k = i + 2; k < n; k++)
			if (arr[i] > arr[k]) judik[i][k] = 1;

	for (int i = 0; i < n - 2; i++) {	// ���� �Է��� 4 2 5 3 1�̸� a_i = 4�� �� a_j = 5�� a_k �� 3, 1�� 2�� �̹Ƿ� ���� ������� ��
		long long sum = 0;
		for (int k = i + 2; k < n; k++) {
			rst[i][k] = judik[i][k] + sum;
			sum += judik[i][k];
		}
	}

	long long ans = 0;
	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			if (arr[i] < arr[j]) ans += rst[i][n - 1] - rst[i][j];

	// �� ���� i = 0, j = 2 �� �� (0, 2, 4), (0, 2, 5) ���� �̶� ��ü a_i > a_k ���� rst[i][n-1] ���� �� ������ ���� �� rst[i][j]�� ���ָ� i = 0, j = 2 �� �� ����� ��
	// �״ϱ� ��ü���� ���� ���� ���츦 ���ָ鼭 ������ i < j < k�� ���� a_i < a_j �̰�, a_i > a_k�� ������ ��츦 ����

	cout << ans;
	return 0;
}