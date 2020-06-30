# The Coin Change Problem

[HackerRank](https://www.hackerrank.com/) - [The Coin Change Problem](https://www.hackerrank.com/challenges/coin-change/problem)

## Contents

- [The Coin Change Problem](#the-coin-change-problem)
  - [Contents](#contents)
  - [Objectives](#objectives)
  - [Solution](#solution)

## Objectives

Need to complete the `getWays` method below.

``` C++
long getWays(int n, vector<long> c);
```

## Solution

코인을 오름차순으로 정렬 후 작은 금액부터 조합의 수를 계산해나간다. 금액 n을 만들고 싶은 경우, 코인 벡터를 순회하면서 각 값을 만들 수 있는 조합의 수를 모두 더해주면 된다. 이를 점화식으로 표현하면 아래와 같다.

``` C++
if (amount >= coin)
  combination[amount] += combination[amount - coin]
```

아래의 입력이 주어졌을 때 combination[4]는 아래와 같이 계산할 수 있다.

``` text
4 3
1 2 3
```

0 | 1 | 2 | 3 | 4 | state
---|---|---|---|---|---
1|0|0|0|0|초기 상태
1|1|1|1|1|coin = 1
1|1|2|2|3|coin = 2
1|1|2|3|4|coin = 3
