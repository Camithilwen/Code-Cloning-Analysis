//Be Name Khoda, Besmellah Rahmane Rahim, In The Name Of God;
//#include<bits/stdc++.h>
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
#include <stdio.h>
#include <string.h>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>
#include <fstream>

using namespace std;
 
using namespace std;

const int N = 1e6 + 5;
const int mod = 998244353;


long long fact[N];
int n, m;

void pre()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] = fact[i] % mod;
    }
}

int power(int a, int b)
{
    if (!b)
    {
        return 1;
    }
    long long ans = power(a, b / 2);
    ans = ans * ans;
    ans = ans % mod;
    if (b % 2)
    {
        ans = ans * a;
        ans = ans % mod;
    }
    return ans;
}


long long choose(int a, int b)
{
    if (b > a)
    {
        return 0;
    }
    long long ans = fact[a];
    ans = ans * power(fact[b], mod - 2);
    ans = ans % mod;
    ans = ans * power(fact[a - b], mod - 2);
    ans = ans % mod;
    return ans;
}




int main() 
{
    pre();
    //cout << choose(5, 2) << endl;
    cin >> n >> m;
    long long ans = 0;
    for (int i = 1; i <= n && i <= m; i++) 
    {
        long long tmp = choose(i * 2, i) * choose(n + m - 2 * i, n - i);
        tmp = tmp % mod;
        ans += tmp;
        ans = ans % mod;
    }
    long long tmp = choose(n + m, n) * 2;
    tmp = power(tmp, mod - 2);
    ans = ans * tmp;
    ans = ans % mod;
    ans += max(n, m);
    ans = ans % mod;
    cout << ans << endl;
}





