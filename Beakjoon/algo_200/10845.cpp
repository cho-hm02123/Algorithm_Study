#include <iostream>
#include <string>
using namespace std;

struct Queue {
	int data[10000];
	int begin, end;

	Queue(){
		begin = 0;
		end = 0;
	}

	void push(int num) {
		data[end] = num;
		end += 1;
	}

	bool empty() {
		if (end == begin)
			return true;
		else
			return false;
	}

	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			begin += 1;
			return data[begin - 1];
		}
	}

	int size() {
		return end - begin;
	}

	int front() {
		if (empty()) {
			return -1;
		}
		else {
			return data[begin];
		}
	}

	int back() {
		if (empty()) {
			return -1;
		}
		else {
			return data[end - 1];
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Queue q;

	int N;
	cin >> N;

	while (N--) {
		string mod;
		cin >> mod;

		if (mod == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (mod == "pop") {
			if (q.empty())
				cout << "-1" << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (mod == "size")
			cout << q.size() << '\n';
		else if (mod == "empty") {
			if (q.empty())
				cout << "1" << '\n';
			else
				cout << "0" << '\n';
		}
		else if (mod == "front") {
			if (q.empty())
				cout << "-1" << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (mod == "back") {
			if (q.empty())
				cout << "-1" << '\n';
			else
				cout << q.back() << '\n';
		}
	}

	return 0;
}
