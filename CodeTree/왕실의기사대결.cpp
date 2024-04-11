#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
#define X first
#define Y second

int l, n, q, num, d, p;
int fig[41][41];            //벽, 함정 정보 저장
int flag[41][41];           //기사 위치 저장 -> 기사 영역에 기사 번호 입력
vector <pair<int, int>> vp; //기사 좌측 상단 좌표 저장
vector <pair<int, int>> vb; //기사 가로 세로 길이 저장
int core[31] = {0, };       // 체력 저장
int dem[31] = {0, };        // 데미지 저장
int dx[4] = {-1, 0, 1, 0};  
int dy[4] = {0, 1, 0, -1};
int tf;
vector <int> v;             //대결 시 밀린 기사 번호 저장
bool check[31] = { 0, };    //대결 시 vector v 에 번호 저장하기 전 저장했던 기사인지 표시

//턴 돌때마다 기사 위치 업데이트 및 체크, vector v 초기화
void dr() {
	tf = 0;
	v.clear();
	for (int i = 1; i < l + 1; i++)
		for (int j = 1; j < l + 1; j++)
			flag[i][j] = 0;

	for (int i = 1; i < p+1; i++) {
		check[i] = 0;
		for (int x = 0; x < vb[i].X; x++)
			for (int y = 0; y < vb[i].Y; y++)
				flag[vp[i].X + x][vp[i].Y + y] = i;
	}
}

// 대결시 기사가 이동할 수 있는지 판단
void domi(int nn) {
	int xp = vp[nn].X + dx[d];
	int yp = vp[nn].Y + dy[d];
	int all0 = 0;

	check[nn] = 1;
	for (int i = 0; i < vb[nn].X; i++)
		for (int j = 0; j < vb[nn].Y; j++) { //기사 좌측 상단 좌표에 가로 세로 1씩 증가시키면서 전수 조사 
			if (xp+i < 1 || yp+j < 1 || xp+i > l || yp+j > l) { //범위 넘어가면 기사 이동 못시키므로 밀랴고 했던 기사 번호 초기화하고 return
				v.clear();
				tf = 10;
				return;
			}
			else if (fig[xp + i][yp + j] == 2) { // 벽일때 위와 행동 동일
				v.clear();
				tf = 10;
				return;
			}
			else if (flag[xp + i][yp + j] == 0 || flag[xp + i][yp + j] == nn){ //자기 자신이거나 비어잇을 때
				all0++;
			}
			else if (flag[xp + i][yp + j] > 0) { //밀 기사 있으면 기사 번호 저장하고 해당 함수 다시 호출해서 검사
				if (check[flag[xp + i][yp + j]] == 0) {
					check[flag[xp + i][yp + j]] = 1;
					v.push_back(flag[xp + i][yp + j]);
					domi(flag[xp + i][yp + j]);
				}
			}
		}
}

void f() {
	int all0=0;
	int xp = vp[num].X + dx[d]; //명령으로 밀쳤을 때 좌상단 위치
	int yp = vp[num].Y + dy[d];

	check[num] = 1;
	for (int i = 0; i < vb[num].X; i++)
		for (int j = 0; j < vb[num].Y; j++) { //기사 좌측 상단 좌표에 가로 세로 1씩 증가시키면서 전수 조사 
			if (xp + i < 1 || yp + j < 1 || xp + i > l || yp + j > l) return; //범위 넘어가면 기사 이동 못시키므로 밀랴고 했던 기사 번호 초기화하고 return
			else if (fig[xp + i][yp + j] == 2) return; // 벽일때 위와 행동 동일
			else if (flag[xp + i][yp + j] == 0 || flag[xp+i][yp+j] == num)
				all0++; //자기 자신이거나 비어있으면 all0 증가 시킴 나중에 all0가 자기 넓이와 동일하면 아무도 못밀고 이동만 함
			else if(flag[xp + i][yp + j]>0){ //밀 수 있는 기사 있을 때
				if (check[flag[xp + i][yp + j]] == 0) {
					check[flag[xp + i][yp + j]] = 1;
					v.push_back(flag[xp + i][yp + j]);
					domi(flag[xp + i][yp + j]);
					if(tf == 10)
					return;
				}
			}
		}
	if (all0 == vb[num].X * vb[num].Y) { //바로 옆에 다른 기사 없고 벽도 없고 해서 그냥 혼자 이동만 함
		vp[num].X = xp;
		vp[num].Y = yp;
		return;
	}
	else if (v.size() == 0) return; //밀었는데 연쇄작용 하다가 다른 기사가 더 밀려날 곳이 없어서 자신도 못 움직임
	else if (v.size() > 0) { //연쇄작용 성공
		vp[num].X = xp; // 내 좌상단 좌표 변경해줌
		vp[num].Y = yp;
		for (int i = 0; i < v.size(); i++) { //연쇄작용으로 밀릴 기사 좌표 조정해줄거임
			int cnt = 0;
			vp[v[i]].X = vp[v[i]].X + dx[d]; //좌표 조정
			vp[v[i]].Y = vp[v[i]].Y + dy[d];

			for(int j = 0; j < vb[v[i]].X; j++)
				for (int h = 0; h < vb[v[i]].Y; h++)
					if (fig[vp[v[i]].X + j][vp[v[i]].Y + h] == 1) // 밀린 위치에 해당하는 함정 수 저장
						cnt++;
			dem[v[i]] += cnt; // 총 받은 데미지 저장

			if (core[v[i]] - dem[v[i]] < 0 || core[v[i]] - dem[v[i]] == 0) { //총 받은 데미지가 체력 이상일 때 
				vp[v[i]].X = 0;
				vp[v[i]].Y = 0; //좌상단 좌표를 (0,0)
				vb[v[i]].X = 0;
				vb[v[i]].Y = 0; // 가로 세로 길이를 0으로 하여 기사를 없애버림 -> 번호 유지할 수 있게 삭제 안하고 0처리
				dem[v[i]] = 0; // 나중에 살아남은 기사가 받은 데미지만 출력하므로 죽은 기사 데미지는 0으로 해줌
			}
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vp.push_back({ 0,0 });
	vb.push_back({ 0,0 });
	int cnt=0;

	cin >> l >> n >> q;
	for (int i = 1; i < l + 1; i++)
		for (int j = 1; j < l + 1; j++)
			cin >> fig[i][j];
	
	for (int i = 1; i < n+1; i++) {
		int a, b;
		cin >> a >> b;
		vp.push_back({ a,b });
		cin >> a >> b;
		vb.push_back({ a, b });
		cin >> core[i];
	}
	p = vp.size();
	dr();

	for (int i = 0; i < q; i++) {
		cin >> num >> d;
		if (vp[num].X == 0 || vp[num].Y == 0) continue;
	
		f();
		dr();
	}

	for (int i = 1; i < n+1; i++){
		if(vp[i].X == 0) continue;
		cnt += dem[i];
	}
	cout << cnt;

	return 0;
}
