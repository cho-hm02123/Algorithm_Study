# Basic
----
### 1. 시간복잡도
#####  O(1) < O(logN) < O(N) < O(NlogN) < O(n^2^) < O(2^N^) < O(N!)
#####  1초에 약 1억

### 2. 자료형
* 정수형
  * **char**        (1byte) : 2<sup>7</sup> -1  (255)
  * **short**       (2byte) : 2<sup>15</sup> -1 (32767)
  * **int**         (4byte) : 2<sup>31</sup> -1 (2.1x10<sup>9</sup>)
  * **long long**   (8byte) : 2<sup>63</sup> -1 (9.2x10<sup>18</sup>)

* 실수형
  * **float**  : 지수(8), 수(23)
  * **double** : 지수(11), 수(52)
 
  double에 long long 범위를 지정할 수 없음.
 
  오차가 필연적이므로 double을 쓰는게 낫다.

### 3. 함수 인자
함수에 값을 넘겨줄 때 주소를 넘겨주지 않는 한 값이 복사되어 넘어가므로 함수에서 값을 바꿔도 이전 함수의 값이 변하지 않음.

만약 함수에서 값을 바꾸고 싶다면 Reference(**&**) 사용.
 ex. void swap(int &a, int &b)

# STL
----
### 1. Algorithm
  * **sort** : 기본 오름차순 정렬 (작은 것부터 순서대로) > 세번째 인자에 함수를 넣어 원하는 규칙대로 정렬 가능
    * 배열 : sort(arr, arr + 크기)
    * 벡터 : sort(v.begin(), v.end())
   
  * **binary_search** : 이분탐색(O(logN))으로 target의 존재 여부를 알 수 있음 > 존재하면 True, 존재하지 않으면 False  [주의: 오름차순 정렬 되어있어야 함]
    * binary_search(begin(), end(), target)
   
### 2. Map
  * **map** : 왼쪽 값을 Key로, 오른쪽 값을 Value로 사용함 > 트리 형태로 탐색속도 높임 (Key를 기준으로 정렬)
    * 선언 : map<key, value> m;
    * 대입 : m.insert(make_pair('C', 2)); OR m['C'] = 2; (key가 char형, value가 int형 이라 가정하고 예시)
    * 원소 삭제 : m.erase(key);
    * 전체 삭제 : m.clear();
    * value 탐색 : m.find(key); > 존재 시 iterator를 반환, 없으면 m.end() 반환
    * key 탐색 : m.count(key); > 존재하면 1, 아니면 0
    * 기타 : size, empty() 있음
   
### 3. String
  * **lenght** : 문자열의 길이를 반환 > a.lenght();


# Subject
----
### 0x09 BFS
벽을 한번만 부순다거나 하는 제약 조건이 있는 상황에서의 탐색은 배열을 통해 풀이

ex) int arr[2][100][100] 이라는 3차원 배열을 만들고 조건 실행 유무, x좌표, y좌표로 저장 ([Beakjoon/BFS/2206.cpp](https://github.com/cho-hm02123/Algorithm_Study/blob/main/Beakjoon/BFS/2206.cpp))
