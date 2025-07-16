#include<bits/stdc++.h>
#include<atcoder/fenwicktree>
using ll = int_fast64_t;
#define REP(i,b,e) for(ll i=b; i<e; i++)

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	atcoder::fenwick_tree<ll> bit(n);
	REP(i, 0, n){
		ll a;
		scanf("%ld", &a);
		bit.add(i, a);
	}

	REP(i, 0, q){
		ll t, x, y;
		scanf("%ld %ld %ld", &t, &x, &y);
		if(t==0) bit.add(x, y);
		else printf("%ld\n", bit.sum(x, y));
	}
	return 0;
}

