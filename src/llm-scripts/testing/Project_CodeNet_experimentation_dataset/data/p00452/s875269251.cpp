#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<ll, P> E;
#define MOD (1000000007ll)
#define l_ength size
#define PI 3.14159265358979

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	b += MOD;
	a += b;
	a %= MOD;
}

int n,s;
ll m,p[1234567];

ll search(ll x){
	int l,r,mid;
	if(x>m){
		return 0ll;
	}
	l = 0; r = s;
	while((r-l)>1){
		mid = (l+r)/2;
		if(x+p[mid]>m){
			r = mid;
		}else{
			l = mid;
		}
	}
	return ((x+p[r]>m)?(x+p[l]):(x+p[r]));
}

int main(void){
	int i,j;
	ll ans;
	cin >> n >> m;
	while(!(n==0&&m==0ll)){
		ans = 0ll; s = n*n+n+1;
		for(i=0; i<n; ++i){
			cin >> p[i];
		}
		for(i=0; i<n; ++i){
			for(j=0; j<n; ++j){
				p[n+i*n+j] = p[i]+p[j];
			}
		}
		p[s-1] = 0ll;
		sort(p,p+s);
		for(i=0; i<s; ++i){
			ans = max(ans,search(p[i]));
		}
		cout << ans << endl;
		cin >> n >> m;
	}
	return 0;
}

