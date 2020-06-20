/**
 * 해커랭크 
 * The Coin Change Problem
 * https://www.hackerrank.com/challenges/coin-change/problem
 */

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */

long getWays(int n, vector<long> c) {

    long cache[251] = {0, }; 
    cache[0] = 1;

    sort(c.begin(), c.end(), less<long>());
    
    for (int i = 0; i < c.size(); i++) { 
        int currentCoin = c[i];
        for (int amount = 1; amount <= n; amount++) { 
            if (amount >= currentCoin) { 
                cache[amount] += cache[amount - currentCoin];
            }
        }
    }

    return cache[n];
}

int main()
{
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int n, m;
    vector<long> c;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        long l;
        cin >> l;
        c.push_back(l);
    }

    cout << getWays(n, c) << endl;

    return 0;
}