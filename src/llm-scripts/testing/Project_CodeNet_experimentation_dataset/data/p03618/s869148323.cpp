//g++ -std=c++14 test.cpp -o test.out

//問題URL
//https://atcoder.jp/contests/agc019/tasks/agc019_b

//参考：
//https://oraclesqlpuzzle.ninja-web.net/kyoupro/kyoupro-10-019-b.html

//ポイント：
//A[i]とA[j]が同じ文字の時、
//それに内包される文字列を反転させたものと
//A[i],A[j]を含んだ文字列を反転させても被るので除外する
//例えば
//文字列eabceにおいてはabc,eabceどちらを反転させても
//同じecbaeができる

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

string S;

LL ans = 0;

void solve(){
	LL N = S.size();
	ans = N*(N-1)/2;
	vector<LL> alpha(26,0);
	for(int i=0;i<N;i++) alpha[S[i]-'a']++;
	for(int i=0;i<26;i++) ans -= alpha[i]*(alpha[i]-1)/2;
	ans++;
}
 
int main(){
    cin >> S;
 
    solve();

    cout << ans << endl;
    return 0;
}