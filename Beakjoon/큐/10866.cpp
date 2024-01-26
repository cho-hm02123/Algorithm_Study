#include <iostream>
#include <string>
using namespace std;

const int MAX = 10000;

struct Deque {
	int data[MAX];
	int begin, end;

	Deque() {
		begin = 0;
		end = 0;
	}

	void push_front(int num) {
		data[begin] = num;
		begin = (begin - 1 + MAX) % MAX;
	}
	void push_back(int num) {
		end = (end + 1) % MAX;
		data[end] = num;
	}
	bool empty() {
		if (end == begin)
			return true;
		else
			return false;
	}
	int pop_front() {
		if (empty()) {
			return -1;
		}
		else {
			begin = (begin + 1) % MAX;
			return data[begin];
		}
	}
	int pop_back() {
		if (empty()) {
			return -1;
		}
		else {
			int save = data[end];
			end = (end - 1 + MAX) % MAX;
			return save;
		}
	}
	int size() {
		return (end - begin + MAX) % MAX;
	}
	int fornt() {
		if (empty()) {
			return -1;
		}
		else {
			return data[(begin + 1) % MAX];
		}
	}
	int back() {
		if (empty()) {
			return -1;
		}
		else {
			return data[end];
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Deque dq;

	int N;
	cin >> N;

	while (N--) {
		int num;
		string mod;
		cin >> mod;

		if (mod == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (mod == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (mod == "pop_front") {
			if (dq.empty())
				cout << "-1" << '\n';
			else {
				cout << dq.fornt() << '\n';
				dq.pop_front();
			}
		}
		else if (mod == "pop_back") {
			if (dq.empty())
				cout << "-1" << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (mod == "size")
			cout << dq.size() << '\n';
		else if (mod == "empty") {
			if (dq.empty())
				cout << "1" << '\n';
			else
				cout << "0" << '\n';
		}
		else if (mod == "front") {
			if (dq.empty())
				cout << "-1" << '\n';
			else
				cout << dq.fornt() << '\n';
		}
		else if (mod == "back") {
			if (dq.empty())
				cout << "-1" << '\n';
			else
				cout << dq.back() << '\n';
		}
	}
	return 0;
}
