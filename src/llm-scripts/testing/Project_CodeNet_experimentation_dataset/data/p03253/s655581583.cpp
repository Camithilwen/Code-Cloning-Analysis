#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

const int mod = (int)1e9 + 7;
const int mod2 = 998244353;

ll exp(ll taban, ll us) {
    ll carpan = taban % mod;
    ll temp = us;
    ll res = 1;
    while(temp){
        if(temp % 2) res = (res*carpan) % mod;
        temp /= 2;
        carpan = (carpan*carpan) % mod;
    }
    return res;
}
 
ll ebob(ll a, ll b){
    if(!a)return b;
    return ebob(b%a, a);
}

ll ekok(ll a, ll b){
    return (a*b)/ebob(a, b);
}
ll fact[(int)2e5+5];
ll komb(ll a, ll b){
	return fact[a+b] * exp(fact[a]*fact[b], mod-2) % mod;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	fact[0] = 1;
	for(int i = 1; i <= 2e5; i++) fact[i] = (fact[i-1]*i) % mod;
	int n, m; cin>>n>>m;
	unordered_map<int, int> cnt;
	for(int i = 2; i*i <= m; i++){
		while(m % i == 0){
			m /= i;
			cnt[i]++;
		}
	}
	if(m > 1) cnt[m]++;
	ll ans = 1;
	for(auto x: cnt){
		ans = (ans * komb(n-1, x.second)) % mod;
	}
	cout<<ans<<endl;
}