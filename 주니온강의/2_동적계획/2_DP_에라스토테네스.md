<style>
.imgOption{
    display:flex;
    justify-content:center;
    align-items:center;
    height: 600px; 
}
h2{
    font-weight :bold;
    border : 6px solid #DC143C;
    color : #DC143C !important;
}
h3 {
    font-weight :bold;
    border : 3px solid ;
}
</style>
<!-- 
## 1-5 트로미노 퍼즐
### Quest
#### ❗ 용어 정리
##### 👉 트로미노란?

#### ❗ 입력과 출력
* input 
    : m(보드의 크기) = 4
    row(X위치) = 1 
    col(X위치) = 1

* output 
    : 배열에 트로미노의 번호를 출력

#### ❗ ㄴ, ㄱ (숫자가 적힌 트로미노)로 보드를 채우자
##### 👉 트로미노 퍼즐 분할정복

* [Divide] : 사분면으로 분할 X가 없는 사분면 모서리 채우기
* [Conquer] : 채워진 네개의 사분면 호출

[파이썬 코드](./코드/트로미노.py)
[ C++ 코드](./코드/트로미노.cpp)

### 참고



#### 1. 주니온
#### 2. 알고리즘 도감

<p align="center"> 
  <img src="../2022-02-03-14-55-34.png" alt="text" width=400px />
  <br>본 글에서 사용하는 GIF는 알고리즘 앱 자동재생
</p>
-->

## 2-2 피보나치 수열 & 타일링 문제
### Quest
#### ❗ 용어 정리
##### 👉 피보나치?
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int DP[101010] = {0,};

int fibo(int n)
{
    if (n <= 2)
        return n == 2 ? 1 : n;
    if (DP[n] != 0)
        return DP[n];
    return DP[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
    cin >> N;
    for (int i = 0; i <= N; i++)
        cout << fibo(i) << '\n';
}
```

### 응용문제
##### 👉 1. 11726번 : 2 x N 타일링
```cpp
#include <iostream>
#define ll long long
const int mod = 10007;
using namespace std;
ll DP[1010];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N; cin >> N;
	DP[0] = 0; DP[1] = 1; DP[2] = 2; DP[3] = 3;
	for (int i = 4; i <= N; i++)
		DP[i] = (DP[i - 1] % mod + DP[i - 2] % mod) % mod;
	cout << DP[N] << '\n';
	return 0;
}
```
##### 👉 2. 11726번 : 2 x N 타일링
```cpp
#include <iostream>
#include <algorithm>
#define mod 10007
using namespace std;
int DP[1010];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N; cin >> N;
	DP[0] = 0; DP[1] = 1; DP[2] = 3; DP[3] = 5;
	DP[4] = 11;
	for (int i = 5; i <= N; i++){
		DP[i] = ((DP[i-1]%mod) + (2 * DP[i-2])%mod)%mod;
	}
	cout << DP[N] << '\n';
	return 0;
}

```
##### 👉 3. 2133번 : 타일채우기
```
점화식 : 
    n
        0 -> 1
        1 -> 0
        2 -> 3
    dp[n] = 3 * dp[n-2] + 2(dp[n-4] + dp[n-6] ... + dp[0]) 
```

##### 👉 4.  : 타일채우기 3

1. 시그마로 이루어진 부분은 DP화 시킬수가 있다.
   1. 그렇다면 DP배열을 1개가 아닌 여러개로 설정해서 풀면 빠를수 있을것이다.
    2. 그래서 다음문제는 시간초과를 막기위해
    3. 이중 DP를 사용했다.
        * 이중DP 가 될 시그마의 점화식을 추론할때
           * 컴퓨터를 믿어도 괜찮을것이다 
           * 컴퓨터로 점화식을 찾자 = 규칙성을 찾자
```cpp
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

const int MAX = 1e6 + 1;
const int MOD = 1000000007;

ll DP[MAX][2] = {
    {0, 0},
};
ll N;

ll F_DP(ll _N)
{
    if (DP[_N][0] != 0)
        return DP[_N][0];
    for (int i = 3; i <= _N; i++)
    {
        DP[i][0] = (DP[i - 1][0] * 2 + DP[i - 2][0] * 3) % MOD;
        DP[i][1] = (DP[i - 1][1] + (DP[i - 3][0] * 2)) % MOD;
        DP[i][0] = (DP[i][0] + DP[i][1]) % MOD;
    }
    return DP[_N][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    DP[0][0] = 0;
    DP[1][0] = 2;
    DP[2][0] = 7;
    DP[2][1] = 2;
    cin >> N;
    cout << F_DP(N) << '\n';
    return 0;
}
```

* 2차원 다이나믹 프로그래밍

#### 1. 주니온
#### 2. 알고리즘 도감
#### 3. 안경잡이 개발자 : 동빈나
<p align="center"> 
  <img src="../2022-02-03-14-55-34.png" alt="text" width=400px />
  <br>본 글에서 사용하는 GIF는 알고리즘 앱 자동재생
</p>