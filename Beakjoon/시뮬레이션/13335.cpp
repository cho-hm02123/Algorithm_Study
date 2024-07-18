/* https://www.acmicpc.net/problem/13335
* 강위 다리를 n개의 트럭이 지나가려고 함
* 트럭의 순서는 못바꾸고, 트럭 무게는 다를 수 있으며, 다리위엔 w대의 트럭만 올라갈 수 있음.
* 다리 길이는 w단위 길이. 각 트럭은 하나의 단위 시간동안 하나의 단위 길이만큼 이동할 수 있음.
* 다리 위 트럭으ㅟ 무게 합은 L 이하여야 함. -> 다리 위에 완전히 올라가지 못한 트럭 무게는 제외함
* 
* 입력 : n, w, L
*		 a1 ~ an (트럭의 무게)
* 
* 출력 : 모든 트럭이 다리를 건너는 최단시간
* 
* 풀이 : 다리 칸 수 배열 생성 -> 시간 지남에 따라 밀거임
         주의 : 먼저 밀고 무게 계산 해야함
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int n, w, l;
int cnt;
int len[101];
queue <int> q;

void rt(){
    for(int i = w; i >= 1; i--)
        len[i] = len[i-1];
}

void cal(){ // 무게 계산
    cnt++;
    int sum = 0;
    rt();
    for(int i = 1; i <= w; i++)
     sum += len[i];
     if(sum + q.front() <= l){
        len[1] = q.front();
        q.pop();
     }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> w >> l;
	for (int i = 1; i < n + 1; i++) {
		int k;
		cin >> k;
		q.push(k);
	}

    while(!q.empty()){
        cal();
    }

    for(int i = 1; i <= w; i++){
        if(len[i] != 0) {
            cnt += w-i+1;
            break;
        }
    }

    cout << cnt;

	return 0;
}
