/*
문제 : 
n*n 칸의 맵.
인접한 네칸 중 나무가 있는 수만큼 나무가 성장.
나무 개수를 인접한 네칸중 제초제, 나무, 벽이 없는 칸수로 나눈 몫만큼 인접한 빈칸에 번식.
제초제는 대각선으로 퍼지며, k 만큼 퍼짐 이때 나무가 없거나 벽이 있으면 그 이후로 안퍼짐.
제초제는 c년 만큼 유지, 나무가 없는 곳은 그 칸만 제초제 뿌려지고 그 후로는 X.

입력 : n, m, k, c 순으로 입력 후 map 정보 입력.

풀이 : 
 인접한 네칸으로 번지는 경우를 위해 int tx[4] = { 1, 0, -1, 0 }, ty[4] = { 0, 1, 0, -1 } 사용.
 대각선으로 번지는 경우를 위해 dx[4] = { -1, -1, 1, 1 }, dy[4] = { -1, 1, -1, 1 } 사용.

1. 입력 받기
2. 나무가 있는 좌표 저장.
3. 나무가 있는 좌표의 인접한 네 칸을 검사하며 성장 시킬지, 번식 시킬지 판단.
  3-1. 번식 시킬 때 사용하기 위해 번식시킬 칸의 수를 cnt에 저장, deque에 번식시킬 좌표와 나무 수 저장. -> cnt를 나중에 알기 때문에 뒤에서부터 pop 하려고 덱 사용.
4. 나무를 번식시킴.
5. 제초제를 뿌릴 곳 찾기.
6. 제초제 수명 줄이기.
7. 제초제 뿌리기.
*/

#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

int dx[4] = { -1, -1, 1, 1 };
int dy[4] = { -1, 1, -1, 1 };
int tx[4] = { 1, 0, -1, 0 };
int ty[4] = { 0, 1, 0, -1 };
int map[21][21] = { 0, };

int re = 0;

int n, m, k, c;

int f() {
   int m1 = -1;
   int m2 = -2;
   pair<int, int> cor = { -1,0 };
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
         int flag[4] = { 0, };
         if (map[i][j] < 0) continue;

         if (map[i][j] == 0) {
            m2 = map[i][j];
            for (int a = 0; a < 4; a++)
               flag[a] = -1;
         }
         else
            m2 = map[i][j];

         for(int h = 1; h < k+1; h++)
            for (int d = 0; d < 4; d++) {
               if (flag[d] != 0) continue;
               int nx = i + h * dx[d];
               int ny = j + h * dy[d];

               if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1) continue;
               if (map[nx][ny] <= 0) {
                  flag[d] = -1;
                  continue;
               }

               if(map[nx][ny] > 0)
                  m2 += map[nx][ny];
            }

         if (m2 > m1) {
            m1 = m2;
            cor.X = i;
            cor.Y = j;
         }
      }
   re += m1;
   for(int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
         if (map[i][j] == -2)
            map[i][j] = 0;
         else if (map[i][j] < -2)
            map[i][j]++;
      }

   if (cor.X == -1) {
      return 0;
   }
   else if (m1 == 0) {
      map[cor.X][cor.Y] = -(c + 1);
      return 0;
   }
   else {
      int flag[4] = { 0, };
      map[cor.X][cor.Y] = -(c + 1);
      for (int h = 1; h < k + 1; h++)
         for (int d = 0; d < 4; d++) {
            if (flag[d] != 0) continue;
            int nx = cor.X + h * dx[d];
            int ny = cor.Y + h * dy[d];

            if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1) continue;
            if (map[nx][ny] == -1) {
               flag[d] = -1;
               continue;
            }
            if (map[nx][ny] == 0 || map[nx][ny] < -1) {
               map[nx][ny] = -(c + 1);
               flag[d] = -1;
               continue;
            }
            else
               map[nx][ny] = -(c + 1);
         }
   }
   return 0;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   cin >> n >> m >> k >> c;

   for(int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         cin >> map[i][j];
         
   queue<pair<int, int>> q;
   deque<pair<int, int>> q2;
   for (int y = 0; y < m; y++) {
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++) {
            if (map[i][j] > 0)
               q.push({ i, j });
         }

      while (!q.empty()) {
         pair<int, int> cur = q.front(); q.pop();
         int cnt = 0;
         for (int d = 0; d < 4; d++) {
            int nx = cur.X + tx[d];
            int ny = cur.Y + ty[d];

            if (nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1) continue;
            if (map[nx][ny] > 0) 
               map[cur.X][cur.Y] ++;
            else if (map[nx][ny] == 0) {
               q2.push_back({ nx, ny });
               cnt++;
            }
         }
         if(cnt > 0)
            q2.push_back({ -1, map[cur.X][cur.Y] / cnt });
      }
      int num = 0;
      while (!q2.empty()) {
         pair<int, int> cur2 = q2.back(); q2.pop_back();
         if (cur2.X == -1)
            num = cur2.Y;
         else
            map[cur2.X][cur2.Y] += num;
      }

      f();
   }
   
   
   cout << re;
   return 0;
}
