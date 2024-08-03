/* https://www.acmicpc.net/problem/9461

 12m 54s

문제: 삼각형 나선형으로 놓음
    첫 삼각형은 한 변의 길이 1(모두 정삼각형)
    삼각형을 계속 추가
    나선에서 가장 긴 변의 길이를 k라 할 때 변의 길이가 k인 삼각형을 추가
    N이 주어졌을 때 P(N)을 구하는 프로그램

입력: TC, N

출력: 각 TC마다 P(N)출력 "\n"

풀이: Overflow 생각하기
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int tc, n;
long long arr[101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    
    for(int i = 4; i <101; i++)
        arr[i] = arr[i-3] + arr[i-2];

    cin >> tc;
    while(tc--){
        cin >> n;

        cout << arr[n] << "\n";
    }

    return 0;
}
