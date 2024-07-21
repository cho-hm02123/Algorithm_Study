/* https://www.acmicpc.net/problem/3190
* 문제 : NxN 보드 위에서 게임, 몇몇 칸에는 사과가 있음
*		 보드 상하좌우 끝엔 벽이 있음
*		 처음 뱀의 길이는 1, 오른쪽을 향하고 있음
*		1. 뱀이 몸 길이를 늘릴 땐 머리를 다음 칸에 위치
*		2. 벽이나 자기 몸에 부딪히면 게임이 끝남
*		3. 이동한 칸에 사과가 있으면 사과는 없어지고 꼬리는 안움직임 > 몸길이가 1 늘어남
*		4. 사과가 없으면 몸 길이를 줄여 꼬리가 위치한 칸 비움 > 몸 길이가 변하지 않는다.
*		 사과 위치와 뱀 이동 경로가 주어질 때 게임이 몇초에 끝나는지
* 
* 입력 : 보드 크기 N, 사과 개수 k
*		 k줄에 걸쳐 사과 위치
*		 뱀의 방향 전환 정보 x, c -> 게임 시작으로 부터 x초가 끝난 후 (왼 : L, 오 : D 방향으로 90도 회전)
* 
* 출력 : 게임이 몇초에 끝나는지
* 
*     위
* 좌      오
*    아래
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, k, l, cnt;
int hd; // 0: 위, 1 : 오 , 2 : 아래, 3 : 좌
bool arr[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
deque <pair<int,int>> q;

bool cal(int tm, char c) {
	while (1) {
		cnt++;
        int hx = q.front().X + dx[hd];
        int hy = q.front().Y + dy[hd];

        if(hx < 1 || hy < 1 || hx > n || hy > n) return false;

        for(int i = 0; i < q.size(); i++)
                if(q[i].X == hx && q[i].Y == hy) return false;

        if(arr[hx][hy])
            arr[hx][hy] = 0;
        else
            q.pop_back();

        q.push_front({hx,hy});

        if(cnt == tm){
            if(c == 'L'){
                if (hd == 0)
                    hd = 3;
                else
                    hd--;
            }
            else if(c == 'D'){
                if (hd == 3)
                    hd = 0;
                else
                    hd++;
            }
            return true;
	    }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	hd = 1;
    q.push_front({1,1});

	cin >> n >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
	}

	cin >> l;
	while (l--) {
		int x; 
		char c;
		cin >> x >> c;

		if (!cal(x, c)){
            cout << cnt;
            return 0;
        }
	}

    while (1) {
		cnt++;
        int hx = q.front().X + dx[hd];
        int hy = q.front().Y + dy[hd];

        if(hx < 1 || hy < 1 || hx > n-1 || hy > n-1){
            cout << cnt;
            return 0;
        };

        for(int i = 0; i < q.size(); i++)
                if(q[i].X == hx && q[i].Y == hy){
                    cout << cnt;
                    return 0;
                }

        if(arr[hx][hy])
            arr[hx][hy] = 0;
        else
            q.pop_back();

        q.push_front({hx,hy});
	}

	return 0;
}
