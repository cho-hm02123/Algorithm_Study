/*
오른쪽 -> 동쪽
위쪽 -> 북쪽
(r,c) -> x(북에서 떨어진 거리),y(서에서 떨어진 거리)
처음 주사위가 1이 위를 보게, 3이 동쪽을 보게 (x,y)에 놓여있고 주사위 모든 면에 0이 써있음
지도(NxM)에는 각 칸에 정수가 쓰여있음 
주사위를굴려 이동할 때 이동한 칸에 써있는 수가 
0이면 주사위 바닥의 수가 칸에 복사됨
0이 아니면 칸에 있는 수가 주사위 바닥에 복사되고 칸의 수는 0이 됨

입력 : 세로 n, 가로 m, 처음 주사위 놓여있는 좌표, 명령 개수 k, 
       지도에 쓰여있는 숫자 (0~9)
       이동 명령 (동쪽 1, 서쪽 2, 북쪽 3, 남쪽 4)

출력 : 이동할 때 마다 윗면에 쓰인 수 \n (단, 범위 벗어나면 출력하지 말것)

주사위 구조
  2
4 1 3
  5
  6
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, k, x, y;
int arr[21][21];              // 맵
int num[7];                   // 주사위 값
int dx[5] = {0, 0, 0, -1, 1}; // x동서북남
int dy[5] = {0, 1, -1, 0, 0};
int di[7] = {0, 1, 2, 3, 4, 5, 6}; // 0, 위, 북, 동, 서, 남, 아래

void east(){
    int cdi[7] = {0, di[4], di[2], di[1], di[6], di[5], di[3]};
    copy(cdi, cdi+7, di);
}

void west(){
    int cdi[7] = {0, di[3], di[2], di[6], di[1], di[5], di[4]};
    copy(cdi, cdi+7, di);
}

void north(){
    int cdi[7] = {0, di[5], di[1], di[3], di[4], di[6], di[2]};
    copy(cdi, cdi+7, di);
}

void south(){
    int cdi[7] = {0, di[2], di[6], di[3], di[4], di[1], di[5]};
    copy(cdi, cdi+7, di);
}

void cal(int d){
    int xx = x + dx[d];
    int yy = y + dy[d];

    if(xx < 0 || yy < 0 || xx > n-1 || yy > m-1) return;

    x = xx;
    y = yy;

    if(d == 1)
        east();
    if(d == 2)
        west();
    if(d == 3)
        north();
    if(d == 4)
        south();

    if(arr[x][y] == 0)
        arr[x][y] = num[di[7]];
    else{
        num[di[7]] = arr[x][y];
        arr[x][y] = 0;
    }

    cout << num[di[1]] << "\n";

    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x >> y >> k;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    while(k--){
        int d;
        cin >> d;
        cal(d);
    }

    return 0;
}
