#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int k, w, h;
int dxh[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dyh[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dxm[4] = { 0, 1, 0, -1 };
int dym[4] = { 1, 0, -1, 0 };
int arr[201][201];
int a[31][201][201];

int bfs() {
    queue <tuple<int, int, int>> q;

    for (int i = 0; i < k + 1; i++) {
        a[i][0][0] = 1;
        q.push({ i,0,0 });
    }

    while (!q.empty()) {
        int kk, xx, yy;
        tie(kk, xx, yy) = q.front(); q.pop();

        if (xx == h - 1 && yy == w - 1)
            return a[kk][xx][yy] - 1;

        if (kk < k) {
            for (int i = 0; i < 8; i++) {
                int x = xx + dxh[i];
                int y = yy + dyh[i];

                if (x < 0 || y < 0 || x > h - 1 || y > w - 1 || arr[x][y] == 1 || a[kk + 1][x][y] != 0) continue;
                a[kk + 1][x][y] = a[kk][xx][yy] + 1;
                q.push({ kk + 1, x, y });
            }
        }

        for (int i = 0; i < 4; i++) {
            int x = xx + dxm[i];
            int y = yy + dym[i];

            if (x < 0 || y < 0 || x > h - 1 || y > w - 1 || arr[x][y] == 1 || a[kk][x][y] != 0) continue;
            a[kk][x][y] = a[kk][xx][yy] + 1;
            q.push({ kk,x,y });
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> w >> h;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> arr[i][j];

    cout << bfs();

    return 0;
}
