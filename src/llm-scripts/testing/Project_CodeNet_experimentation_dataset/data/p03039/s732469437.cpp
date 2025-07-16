#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main() {
	ll h,w,k;
	cin>>h>>w>>k;
    COMinit();	
	ll ans=0;
	ll H=(h-1)*h*(h+1)/6%inf*w%inf*w%inf;
	H*=COM(h*w-2,k-2);
	H%=inf;
	ll W=(w-1)*w*(w+1)/6%inf*h%inf*h%inf;
	W*=COM(h*w-2,k-2);
	W%=inf;
	ans+=H+W;
	ans%=inf;
    cout <<ans;
    // 計算例
//    cout << COM(100000, 50000) << endl;	
	// your code goes here
	return 0;
}