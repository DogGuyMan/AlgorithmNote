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

## 2-2 소수판별법
### Quest
#### ❗ 용어 정리
##### 👉 에라스토 테네스 체 O(sqrt(n))
<img src="https://media.giphy.com/media/EKXLomukUTmgfvR0NE/giphy.gif">

**[위키백과 주소](https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4)**

* 에라토스테네스의 체에 맞게 소수를 구함
1. 만일, PrimeArray[i]가 true이면 i 이후의 i 배수는 약수로 i를 가지고 있는 것이 되므로 i 이후의 i 배수에 대해 false값을 준다.
2. PrimeArray[i]가 false이면 i는 이미 소수가 아니므로 i의 배수 역시 소수가 아니게 된다. 그러므로 검사할 필요도 없다. 
3. 또한 i x k (k < i) 까지는 이미 검사되었으므로 
j시작 값은 i x 2에서 i x i로 개선할 수 있다.
```cpp
#include <bits/stdc++.h>
using namespace std;
vector<bool> isPrime(1000001, true);
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, M; cin >> N >> M;
	isPrime[1] = false;
	for (int i = 2; i * i <= M; ++i) {
		if (isPrime[i])
			for (int j = i * i; j <= M; j += i)
				isPrime[j] = false;
	}
	for (int i = N; i <= M; ++i)
		if (isPrime[i])
			cout << i << '\n';
}
```
##### 👉 페르마 테스트


### 참고
#### 1. 주니온
#### 2. 알고리즘 도감
#### 3. 안경잡이 개발자 : 동빈나
<p align="center"> 
  <img src="../2022-02-03-14-55-34.png" alt="text" width=400px />
  <br>본 글에서 사용하는 GIF는 알고리즘 앱 자동재생
</p>

```CS
float GetAccelerration(){

}
```