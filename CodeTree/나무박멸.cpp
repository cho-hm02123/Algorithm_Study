#include <istream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>

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
