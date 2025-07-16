/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 62;
const ll MOD = 1e9 + 7;
 
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
 
ll nCr(ll n, ll r){
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
 
//-----------------------ここから-----------
ll h, w, k;
ll memo[110][10];

ll rec(ll i, ll j){
    if(i == 0 && j == 0) return 1;
    if(i == 0) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    ll res = 0;
    //cout << i << " " << j << endl;
    for(ll bit = 0; bit < (1LL << (w - 1)); bit++){
        bool ok = true;
        for(ll ii = 0; ii < w - 2; ii++){
            if((bit & (1LL << ii)) && (bit & (1LL << (ii + 1)))){
                ok = false;
                break;
            }
        }
        if(ok){
            if(bit & (1LL << j) && j + 1 < w){
                res += rec(i - 1, j + 1);
            } else if(bit & (1 << (j - 1)) && j - 1 >= 0){
                res += rec(i - 1, j - 1);
            } else {
                res += rec(i - 1, j);
            }
            res %= MOD;
        }
    }
    return memo[i][j] = res;

}
int main(void){

    cin >> h >> w >> k;
    
    rep(i, 110) rep(j, 10) memo[i][j] = -1;
    cout << rec(h, k - 1) % MOD << endl;

}