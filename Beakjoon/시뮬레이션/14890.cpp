/* https://www.acmicpc.net/problem/14890


문제 : NxN 지도, 각 칸에 높이가 적혀있음, 길 == 한 줄 (행 or 열지 전부)로 한쪽 끝에서 다른 쪽 끝까지
       ex) 길 최대 수 = 2N
       길을 지나갈 수 있으려면 길에 속한 몯ㄴ 칸의 높이가 다 같아야 함
       또는 경사로를 둬 지나갈 수 있는 길을 만들 수 있음
       경사로 높이는 항상 1이며 길이는 L

       경사로 가능
       - 경사로는 낮은 칸에 놓이며 L개의 연속된 칸에 경사로 바닥이 접해야 함
       - 낮은 칸과 높은 칸의 높이 차가 1이어야 함
       - 경사로를 놓을 낮은 칸의 높이는 모두 같아야 하며 L개의 칸이 연속되어야 함

       경사로 불가능
       - 경사로 위에 또 경사로 두기
       - 낮은 칸 높은 칸 차가 1이 아님
       - 낮은 지점 칸 높이가 모두 같지 않거나 L개가 연속되지 않음
       - 경사로를 놓다가 범위를 벗어남

입력 : N, L, 지도 높이

출력 : 지나갈 수 있는 길의 개수
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, l, cnt;
int arr[101][101];
int flag[101][101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    int k,num;
    for(int i = 0; i < n; i++){
        num = 0;
        for(int j = 0; j < n; j++){
            if(j == 0)
                k = arr[i][j];

            if(abs(arr[i][j] - k) == 1){
                k = arr[i][j];
                num = 0;
            }
        }
    }

    return 0;
}
