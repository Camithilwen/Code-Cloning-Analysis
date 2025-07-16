#include <bits/stdc++.h>
using namespace std;

const int MAX = 3000005;
const int MOD = 998244353;

long long fac[MAX]; //i!%MOD=fac[i]
long long finv[MAX]; //pow(i!,-1)%MOD=finv[i]
long long inv[MAX]; //pow(i,-1)%MOD=inv[i]

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

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(int argc, char const *argv[])
{
	COMinit();
	int n,m;
	cin>>n>>m;
	long long ans=COM(3*m+n-1,n-1);
	for (int i = 2*m+1; i <= 3*m; ++i)
	{
		ans-=(long long)n*COM(3*m+n-2-i,n-2)%MOD;
		ans%=MOD;
	}
	for (int i = 0; i < m; ++i)
	{
		ans-=COM(n-1+i,n-1)*COM(n,3*m-2*i)%MOD;
		ans%=MOD;
	}
	ans+=MOD;
	ans%=MOD;
	cout<<ans<<endl;
	return 0;
}
