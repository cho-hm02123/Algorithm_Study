/* https://www.acmicpc.net/problem/13460

 1h 19m 45s

문제 : 직사각형 보드 세로 N, 가로 M 
       빨간 구슬, 파란 구슬을 하나씩 넣은 다음 빨간 구슬을 구멍을 통해 빼냄 -> 파란 구슬이 나오면 안됨
       가장 바깥은 모두 막혀져 있고, 보드에 구멍 하나 있음
       기울여서 구슬 움직임 왼쪽, 오른쪽, 위쪽, 아래쪽으로 기울이기 가능
       공은 동시에 움직임, 파란 구슬이 구멍에 빠지면 실패, 동시에 구멍에 빠져도 실패
       최소 몇번 만에 빨간 구슬을 뺄 수 있는지

입력 : n,m
      보드 상태 '.' > 빈칸 / '#' > 벽 / 'O' > 구멍 / 'R' 빨간 공 / 'B' 파란 공

출력 : 최소 몇번 만에 구슬을 뺄 수 있는지. 만약 10번 이하로 움직여서 뺄 수 없으면 -1 출력

풀이 : 벽을 몇개 부수면서 가는 문제 풀이 아이디어랑 비슷함
       구멍이 어디 있는지에 따른 경우의 수는 생각할 필요 없음
       빨간 구슬, 파란 구슬의 위치에 따라 cnt를 업로드 들린 곳은 한번 더 들리지 않는다.
       파란 공이 나갔다고 무작정 -1을 출력하는 실수를 하지 말아야 함 그 경우 말고 다른 경우로 탈출 할 수 있을 수 있음 그러니 해당 경우는 그냥 continue
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

struct ball{
    int Rx, Ry, Bx, By;
};

int n, m;
char arr[11][11];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int flag[11][11][11][11]; // 횟수 저장 빨 파
ball sv;

queue <ball> q;

int bfs(){
    q.push(sv);
    flag[sv.Rx][sv.Ry][sv.Bx][sv.By] = 0;

    while(!q.empty()){
        ball cur = q.front(); q.pop();
        int cnt = flag[cur.Rx][cur.Ry][cur.Bx][cur.By];

        if(cnt >= 10) return -1;

        for(int i =0; i < 4; i++){
            ball aa = cur;
            int nr = 0, nb = 0;
            while(arr[aa.Rx+dx[i]][aa.Ry+dy[i]] == '.'){
                aa.Rx += dx[i];
                aa.Ry += dy[i];
                nr++;
            }
            while(arr[aa.Bx+dx[i]][aa.By+dy[i]] == '.'){
                aa.Bx += dx[i];
                aa.By += dy[i];
                nb++;
            }

            if(arr[aa.Bx+dx[i]][aa.By+dy[i]] == 'O') continue;
            if(arr[aa.Rx+dx[i]][aa.Ry+dy[i]] == 'O') return cnt+1;
            
            if(aa.Rx == aa.Bx && aa.Ry == aa.By){
                if(nr > nb){
                    aa.Rx -= dx[i];
                    aa.Ry -= dy[i];
                }
                else{
                    aa.Bx -= dx[i];
                    aa.By -= dy[i];
                }
            }

            if(flag[aa.Rx][aa.Ry][aa.Bx][aa.By] != -1) continue;
            flag[aa.Rx][aa.Ry][aa.Bx][aa.By] = cnt +1;
            q.push(aa);            
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 11; i++)
        for(int j = 0;j < 11; j++)
            for(int h = 0; h < 11; h++)
                for(int k = 0; k < 11; k++)
                    flag[i][j][h][k] = -1;

    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];

            if(arr[i][j] == 'B'){
                sv.Bx = i;
                sv.By = j;
                arr[i][j] = '.';
            }
            else if(arr[i][j] == 'R'){
                sv.Rx = i;
                sv.Ry = j;
                arr[i][j] = '.';
            }
        }

    cout << bfs();

    return 0;
}
