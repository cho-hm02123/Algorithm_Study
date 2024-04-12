#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <map>

using namespace std;
#define X first
#define Y second 

int com, Q, n, m, p, k, s, l;
pair <int, int> point[2002];
map <int, int> id_to_i;
int jump[2002];
long long score[2002];
long long sum;
int d[2002];
bool mov[2002]; // 움직인적 있는지
int id[2002];

struct Rabbit {
	int x, y, jum, id;

	bool operator <(const Rabbit &b) const {
		if (jum != b.jum) return jum > b.jum;
		if (x + y != b.x + b.y) return x + y > b.x + b.y;
		if (x != b.x) return x > b.x;
		if (y != b.y) return y > b.y;
		return id > b.id;
	}
};

bool cmp(Rabbit a, Rabbit b) {
	if (a.x + a.y != b.x + b.y) return a.x + a.y < b.x + b.y;
	if (a.x != b.x) return a.x < b.x;
	if (a.y != b.y) return a.y < b.y;
	return a.id < b.id;
}

Rabbit up(Rabbit cur_R, int dis) {
	Rabbit up_R = cur_R;
	dis %=  2 * (n - 1);

	if (up_R.x - dis <= 1) {
		dis -= (up_R.x - 1);
		up_R.x = 1;
	}
	else {
		up_R.x -= dis;
		dis = 0;
	}

	if (up_R.x + dis >= n) {
		dis -= (n - up_R.x);
		up_R.x = n;
	}
	else {
		up_R.x += dis;
		dis = 0;
	}
	up_R.x -= dis;

	return up_R;
}

Rabbit down(Rabbit cur_R, int dis) {
	Rabbit do_R = cur_R;
	dis %= 2 * (n - 1);

	if (do_R.x + dis >= n) {
		dis -= (n - do_R.x);
		do_R.x = n;
	}
	else {
		do_R.x += dis;
		dis = 0;
	}

	if (do_R.x - dis <= 1) {
		dis -= (do_R.x - 1);
		do_R.x = 1;
	}
	else {
		do_R.x -= dis;
		dis = 0;
	}

	do_R.x += dis;

	return do_R;
}

Rabbit left(Rabbit cur_R, int dis) {
	Rabbit le_R = cur_R;
	dis %= 2 * (m - 1);

	if (le_R.y - dis <= 1) {
		dis -= (le_R.y - 1);
		le_R.y = 1;
	}
	else {
		le_R.y -= dis;
		dis = 0;
	}

	if (le_R.y + dis >= m) {
		dis -= (m - le_R.y);
		le_R.y = m;
	}
	else {
		le_R.y += dis;
		dis = 0;
	}
	le_R.y -= dis;

	return le_R;
}

Rabbit rigth(Rabbit cur_R, int dis) {
	Rabbit ri_R = cur_R;
	dis %=  2 * (m - 1);

	if (ri_R.y + dis >= m) {
		dis -= (m - ri_R.y);
		ri_R.y = m;
	}
	else {
		ri_R.y += dis;
		dis = 0;
	}

	if (ri_R.y - dis <= 1) {
		dis -= (ri_R.y - 1);
		ri_R.y = 1;
	}
	else {
		ri_R.y -= dis;
		dis = 0;
	}

	ri_R.y += dis;

	return ri_R;
}

void init() {
	cin >> n >> m >> p;
	for (int i = 1; i < p + 1; i++) {
		cin >> id[i] >> d[i];
		id_to_i[id[i]] = i;
		point[i] = make_pair(1, 1);
	}
}

void run() {
	cin >> k >> s;
	priority_queue <Rabbit> pq;

	for (int i = 1; i < p + 1; i++)
		mov[i] = false;
	for (int i = 1; i < p + 1; i++) {
		Rabbit new_R;
		new_R.x = point[i].X;
		new_R.y = point[i].Y;
		new_R.jum = jump[i];
		new_R.id = id[i];

		pq.push(new_R);
	}

	while (k--) {
		Rabbit cur_R = pq.top(); pq.pop();

		int dis = d[id_to_i[cur_R.id]];
		Rabbit next_R = cur_R;
		next_R.x = 0;
		next_R.y = 0;

		Rabbit up_R = up(cur_R, dis);
		if (cmp(next_R, up_R)) next_R = up_R;
		Rabbit do_R = down(cur_R, dis);
		if (cmp(next_R, do_R)) next_R = do_R;
		Rabbit le_R = left(cur_R, dis);
		if (cmp(next_R, le_R)) next_R = le_R;
		Rabbit ri_R = rigth(cur_R, dis);
		if (cmp(next_R, ri_R)) next_R = ri_R;

		next_R.jum++;
		pq.push(next_R);

		point[id_to_i[next_R.id]] = make_pair(next_R.x, next_R.y);
		jump[id_to_i[next_R.id]]++;
		mov[id_to_i[next_R.id]] = true;

		score[id_to_i[next_R.id]] -= (next_R.x + next_R.y);
		sum += next_R.x + next_R.y;
	}

	Rabbit com_R;
	com_R.x = 0;
	com_R.y = 0;

	while(!pq.empty()) {
		Rabbit cur_R = pq.top(); pq.pop();
		if (!mov[id_to_i[cur_R.id]]) continue;
		if (cmp(com_R, cur_R)) com_R = cur_R;
	}

	score[id_to_i[com_R.id]] += s;
}

void mul() {
	int a;
	cin >> a >> l;

	d[id_to_i[a]] = d[id_to_i[a]] * l;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> Q;

	while(Q--) {
		cin >> com;
		
		if (com == 100)
			init();
		else if (com == 200)
			run();
		else if (com == 300)
			mul();
		else if (com == 400) {
			long long mm = 0;
			for (int j = 1; j < p + 1; j++)
				mm = max(mm, score[j] + sum);
			cout << mm;
		}
	}

	return 0;
}
