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

풀이 : 4 2
       1 1 2 2 
       1 2 2 2 
       2 2 2 2 
       2 2 2 2  의 (0,0), (0,1), (1,0) 처럼 겹쳐도 상관 없음 < 이 조건 안주어진게 개에바 이거 제시 안하면 문제 자체가 달라지는데;;
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n, l, cnt;
int arr[101][101];

int cal(vector <int>& v) {
    int len = 1;
    int id = 0;

    while (id < n - 1) {
        if (abs(v[id] - v[id + 1]) > 1) return 0;
        if (v[id] == v[id + 1]) {
            id++;
            len++;
        }
        else if (v[id] < v[id + 1]) {
            if (len < l) return 0;
            id++;
            len = 1;
        }
        else if (v[id] > v[id + 1]) {
            if (id + l >= n) return 0;
            for (int i = id + 1; i < id + l+1; i++)
                if (v[i] != v[id+1]) return 0;

            id += l;
            len = 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++) {
        vector <int> v;
        for (int j = 0; j < n; j++) v.push_back(arr[i][j]);
        cnt += cal(v);
    }

    for (int j = 0; j < n; j++) {
        vector <int> v;
        for (int i = 0; i < n; i++) v.push_back(arr[i][j]);
        cnt += cal(v);
    }

    cout << cnt;

    return 0;
}
