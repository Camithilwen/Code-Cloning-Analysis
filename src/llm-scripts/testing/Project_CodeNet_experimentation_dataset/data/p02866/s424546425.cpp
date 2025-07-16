#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 998244353

ll ch[100010];

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		ch[now]++;
		if(i==0&&now!=0){
			cout << 0;
			return 0;
		}
	}
	if(ch[0]!=1){
		cout << 0;
		return 0;
	}
	ll cnt=ch[0];
	ll ans=1;
	for(ll i=1;;i++){
		if(ch[i]==0){
			cout << 0;
			return 0;
		}
		ans*=modpow(ch[i-1], ch[i], 998244353); 
		ans%=inf;
		cnt+=ch[i];
		if(cnt==n){
			break;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}