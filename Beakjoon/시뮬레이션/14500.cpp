/* https://www.acmicpc.net/problem/14500
* 
*  53m 19s
* 
* 문제: 정사각형 변끼리 닿아 있어야 함 꼭짓점 안됨
*		테트로미토 5가지 중 하나를 놓아서 놓인 칸에 쓰인 수가 최대가 되도록
*		회전, 대칭 가능
* 
* 입력: 종이 가로 세로 N, M (500 이하)
*		종이에 쓰여있는 수
* 
* 출력 : 최댓값
* 
* 풀이 : 그냥 다 저장
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

int n, m;
int mm = -1;
int arr[501][501];
vector <pair<int, int>> v = {   {0,0}, {1,0}, {2,0}, {2,1},
							    {0,0}, {1,0}, {0,1}, {0,2},
							    {0,0}, {0,1}, {1,1}, {2,1},
							    {1,0}, {1,1}, {1,2}, {0,2},
							    {0,0}, {1,0}, {2,0}, {0,1},
							    {0,0}, {1,0}, {1,1}, {1,2},
							    {2,0}, {2,1}, {1,1}, {0,1},
								{0,0}, {0,1}, {0,2}, {1,2},
							    {0,0}, {1,0}, {2,0}, {3,0},
								{0,0}, {0,1}, {0,2}, {0,3},
								{0,0}, {0,1}, {1,0}, {1,1},
								{0,0}, {1,0}, {1,1}, {2,1},
								{1,0}, {1,1}, {0,1}, {0,2},
								{2,0}, {1,0}, {1,1}, {0,1},
								{0,0}, {0,1}, {1,1}, {1,2},
								{0,0}, {0,1}, {1,1}, {0,2},
								{0,0}, {1,0}, {1,1}, {2,0},
								{1,0}, {0,1}, {1,1}, {1,2},
								{1,0}, {0,1}, {1,1}, {2,1} };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int k = 0; k < v.size(); k += 4)
		for(int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int sum = 0;

				for (int h = 0; h < 4; h++) {
					int x = i + v[k + h].X;
					int y = j + v[k + h].Y;

					if (x < 0 || y < 0 || x > n - 1 || y > m - 1) break;

					sum += arr[x][y];
				}
				mm = max(mm, sum);
			}

	cout << mm;

	return 0;
}
