#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;

	cin >> T;
	cin.ignore();													// ���� �ʱ�ȭ

	while (T--){

		string str;
		getline(cin, str);											// ������� �ѹ��� string �ޱ�
		str += '\n';												// ������ ���п����� �߰�
		stack<char>s;

		for (char ch : str) {										// string�� char �� ����
			if (ch == ' ' || ch == '\n') {
				while(!s.empty()) {									
					cout << s.top();								// ���� ������ stack�� ������ �ܾ� �����鼭 ���
					s.pop();
				}
				cout << ch;											// ���� ���
			}
			else 
				s.push(ch);
		}
	}

	return 0;
}