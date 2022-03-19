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
## 최단경로 (플로이드 알고리즘)
### Quest
* 주어진 그래프에서 모든 정점의 쌍에 대한 최단경로 구하기

#### ❗ 용어 정리
* ##### 👉 G = (V, E)
  * **V : 정점 E : 간선**
  * **G : 방향, 가중치 그래프**
  * **최단경로** 
    * 단순경로
    * 같은 정점을 두번 거치지 않음 
* ##### 👉 그래프 표현법
  * **인접행렬**
    * size of D = V²
* ##### 👉 플루이드 알고리즘
  * <img src="https://media.giphy.com/media/PlwtyaKyAWdDhtYIfh/giphy.gif">
  * **특징**
    1. 모든 정점의 각각각각..  최단거리를 구하고 싶다면 사용하는것
    2. 음수 가중치도 허용한다.
    3. DP에 의거한다.
  * **D (인접 행렬/인접리스트)**
    * 각 정점의 쌍이 가지는 최단경로의 길이
    * D[i][j] : Vi~ Vj까지 최단경로 재귀 관계식
    * 
        ```txt
        갱신 : 
            경로 1
                X -> Y (다이렉트)
                DP[i][j] = DP[i][j]
                    (VS)
            경로 2
                X -> 거쳐가는 최단 경로 -> Y
                DP[i][j] = DP[i][k] = DP[k][j]
        ```
    * 루프의 우선순위
      1. 거쳐가는 노드
      2. 출발 노드
      3. 도착 노드
      * ```cpp
        for(int k = 0; k < N; k++) // k 거쳐가는 노드
            for(int i = 0 ; i < N; i++) //i 출발 노드
               for(int j = 0 ; j < N; j++) //j 도착 노드
                   DP[i][j] = min(DP[i][j], DP[i][k]+DP[k][j])
        ```
    * 경로 리스트 얻기
        1. 시작 경로 찍기
           * u
        2. 중간 경로 리스트 얻기
           1. P[i][j] = -1 이면
              * vi ~ vj가 최선
           2. P[i][j] = k 라면
              * inorder으로 k 탐색
        3. 마지막 경로 찍기
           * v
#### ❗ 입력과 출력
* input 
    : W = 인접행렬

* output 
    : D = 플루이드 워셜 전체 정점 행렬