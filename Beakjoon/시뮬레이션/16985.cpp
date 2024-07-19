/* https://www.acmicpc.net/problem/16985
문제 : 3차원 미로 탈출
      5x5x5 사이즈 미로, 흰칸(1) -> 들어갈 수 있음, 검은칸(0) -> 못들어감
      판을 시계, 반시계 방향으로 회전할 수 있음
      회전을 완료한 후 판을 쌓을거임 만들어진 5X5X5가 대회 미로
      입구 : 참가자가 임의로 정한 꼭짓점
      출구 : 입구와 면을 공유하지 않는 꼭짓점 즉, 대각선 아래
      현재 칸에서 면으로 인접한 흰칸으로 이동 가능
      본인이 설계한 미로를 가장 적은 이동 횟수로 탈출하면 우승 -> 탈출이 불가할 수도 있음

입력 : 25줄에 걸쳐 판의 상태 0은 검은 칸 1은 흰칸

출력 : 최단 이동거리 출력 단, 불가할 경우 -1 출력

풀이 : 경우의 수가 4*4*4*4*4*5!인 미친 문제
       판 쌓는 5! 당 1024개의 경우의 수가 존재함으로 순열을 이용해서 판을 쌓을 순서를 정하고 
       어떻게 돌릴지 정해야함
       위 두가지를 합치는데 어려웠음
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int arr[4][5][5][5]; // 회전 수, z, x, y
int carr[5][5][5];
int dx[6] = {0, 1, 0, -1, 0, 0}; // 동, 남, 서, 북, 위, 아래
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int mm = 0x7fffffff;

struct s {
    int x, y, z;
};

void rot(){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 3; j++){

            for(int a = 0; a < 5; a++)
                for(int b = 0; b < 5; b++)
                    arr[j+1][i][4-b][a] = arr[j][i][a][b];
        }
}

void cal(){
    if(!carr[0][0][0] || !carr[4][4][4])
        return;

    queue <s> q;
    s var;
    var.x = 0;
    var.y = 0;
    var.z = 0;
    carr[0][0][0] = 1;
    q.push(var);

    while(!q.empty()){
        s cur = q.front(); q.pop();
        if(cur.z == 4 && cur.x == 4 && cur.y == 4){
            mm = min(mm, carr[cur.z][cur.x][cur.y]-1);
            return;
        }

        for(int i = 0; i < 6; i++){
            s ll;
            ll.z = cur.z + dz[i];
            ll.x = cur.x + dx[i];
            ll.y = cur.y + dy[i];

            if(ll.z < 0 || ll.x < 0 || ll.y < 0 || ll.z > 4 || ll.x > 4 || ll.y > 4 || !carr[ll.z][ll.x][ll.y]) continue;
            if(carr[ll.z][ll.x][ll.y] <= carr[cur.z][cur.x][cur.y]+1) continue;

            carr[ll.z][ll.x][ll.y] = carr[cur.z][cur.x][cur.y] + 1;
            q.push(ll);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            for(int h = 0; h < 5; h++){
                int a;
                cin >> a;
                
                if(a == 1)
                    arr[0][i][j][h] = 0x7fffffff;
                else
                    arr[0][i][j][h] = 0;
            }

    rot();
    
    int num[5] = {0, 1, 2, 3, 4};
    do{
        for(int t = 0; t < 1024; t++){ // 4*4*4*4*4로 순열 한 세트 당 경우의 수 총 1024개
            int l = t;
            for(int j = 0; j < 5; j++){ // carr엔 0 ~ 4층 까지, arr엔 순열 num[0] ~ num[4] 층 넣어줌
                int p = l % 4;          // 몇번 돌린 판인지
                l = l/4;                // 다음 판의 돌림 수 정함
                for(int h = 0; h < 5; h++)
                    for(int k = 0; k < 5; k++)
                    carr[j][h][k] = arr[p][num[j]][h][k];
            }
            cal();
        }
    }while(next_permutation(num, num+5));

    if(mm == 0x7fffffff)
        cout << "-1";
    else
        cout << mm;

    return 0;
}
