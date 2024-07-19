/* https://www.acmicpc.net/problem/14503
로봇 청소기가 청소할 방 : NxM / 각 칸은 벽 또는 빈칸
청소기는 바라보는 방향이 있음 > 동, 서, 남, 북 중 하나
방 좌표는 (r,c) 좌상단이 (0,0) 우하단이 (N-1, M-1)
처음 빈칸은 모두 청소되지 않은 상태
1. 현재 칸이 청소 X -> 청소
2. 칸 주변 4군데 중 청소되지 않은 칸이 없는 경우
    2-1. 바라보는 방향을 유지하고 후진할 수 있으면 후진하고 1.로
    2-2. 뒤가 벽이라 후진할 수 없는 경우 작동을 멈춤
3. 주변 4군데 중 청소되지 않은 칸이 있는 경우
    3-1. 반시계로 90도 회전
    3-2. 바라보는 방향으로 앞이 청소 안된 경우 전진
    3-3. 1.로

입력 : N M
      처음 로봇청소기가 있는 좌표 , 바라보는 방향 d (0 : 북, 1 : 동, 2 : 남, 3 : 서) 
      > 반시계로 90도면 1씩 감소
      방 상태 (0 : 빈칸, 1 : 벽)

출력 : 동작 멈췄을 때 청소한 칸 개수

풀이 : 주의 -> 청소할 칸이 있을 때 직진 우선이 아닌 90도 반시계 먼저 돌아야 함
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, x, y, d;
int cnt;
int arr[50][50];
int rx[4] = {1, 0, -1, 0};
int ry[4] = {0, -1, 0, 1}; // 후진
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1}; // 직진
bool flag[50][50];

bool rr(){
    int xx = x + rx[d];
    int yy = y + ry[d];

    if(xx < 0 || yy < 0 || xx > n-1 || yy > m-1 || arr[xx][yy])
        return false;
    else{
        x = xx;
        y = yy;
        return true;
    }
}

bool cl(){
    if(!flag[x][y] && !arr[x][y]){
        cnt++;
        flag[x][y] = 1;
    }

    int dd = d;
    int k = 4;

    while(k--){
        --dd;
        if(dd < 0)
            dd = 3;

        int xx = x + dx[dd];
        int yy = y + dy[dd];

        if(xx < 0 || yy < 0 || xx > n-1 || yy > m-1) continue;
        if(!flag[xx][yy] && !arr[xx][yy]){
            x = xx;
            y = yy;
            d = dd;
            return true;
        }
    }

    if(rr())
        return true;
    else
        return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x >> y >> d;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    while(1){
        if(!cl())
            break;
    }

    cout << cnt;

    return 0;
}
