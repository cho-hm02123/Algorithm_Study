# Basic
----
### 1. 시간복잡도
#####  O(1) < O(logN) < O(N) < O(NlogN) < O(n^2^) < O(2^N^) < O(N!)

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
