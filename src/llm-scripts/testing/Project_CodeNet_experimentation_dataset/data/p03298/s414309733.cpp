#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair < int , int >
const int seed = 233 , MOD = 20190816170251;
int N; char str[43];
map < PII , int > cnt;

signed main(){
	scanf("%d %s" , &N , str + 1);
	for(int i = 0 ; i < 1 << N ; ++i){
		int p = 0 , q = 0;
		for(int j = 1 ; j <= N ; ++j)
			if(i >> (j - 1) & 1) p = (p * seed + str[j]) % MOD;
			else q = (q * seed + str[j]) % MOD;
		++cnt[PII(p , q)];
	}
	reverse(str + 1 , str + 2 * N + 1); int ans = 0;
	for(int i = 0 ; i < 1 << N ; ++i){
		int p = 0 , q = 0;
		for(int j = 1 ; j <= N ; ++j)
			if(i >> (j - 1) & 1) p = (p * seed + str[j]) % MOD;
			else q = (q * seed + str[j]) % MOD;
		ans += cnt[PII(p , q)];
	}
	cout << ans; return 0;
}