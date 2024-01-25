/*
문제 : 5일 동안의 근무시작 시간, 근무 마감 시간이 입력으로 들어오며 5일동안의 총 근무 시간을 분으로 출력
입력 : 10:00 19:00

풀이 :
stoi (String을 Int 형으로 바꿔줌)을 사용 (#include <string>)
stringvariable.substr(시작점, 개수) 를 하면 원하는 영역만 추출 가능
*/

#include <iostream>
#include <istream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 5;
    int i = 0;

    while (T-- > 0) {
        string start, end;
        int h1 = 0, m1 = 0, h2 = 0, m2 = 0, time1 = 0, time2 = 0;

        cin >> start >> end;
        h1 = stoi(start.substr(0, 2));
        m1 = stoi(start.substr(3, 2));
        h2 = stoi(end.substr(0, 2));
        m2 = stoi(end.substr(3, 2));

        time1 = h1 * 60 + m1;
        time2 = h2 * 60 + m2;

        i = i + (time2 - time1);
    }

    cout << i;

    return 0;
}
