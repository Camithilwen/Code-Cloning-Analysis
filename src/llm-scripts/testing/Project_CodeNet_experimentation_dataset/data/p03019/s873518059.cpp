//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
using namespace std;
const ll MAX_N=1e5,MAX_X=1e5;
ll N,X,psm[MAX_N+2],inx[MAX_N+1];
typedef tuple<ll,ll,ll> TUP;
TUP blu[MAX_N+1];

ll tsm(ll i){
	return get<1>(blu[i])*get<0>(blu[i])+get<2>(blu[i])*(X-get<0>(blu[i]));
}
ll ptsm(ll i,ll n){
	return get<1>(blu[i])*min(n,get<0>(blu[i]))+get<2>(blu[i])*(n-min(n,get<0>(blu[i])));
}
bool C(ll x){
	ll n=x/X,m=x%X;
	ll sm=0;
	REP(i,N+1){
		ll tmp=psm[n];
		if(i<n){
			tmp-=tsm(i);
			tmp+=ptsm(i,m);
			tmp+=tsm(n);
		}else{
			tmp+=ptsm(i,m);
		}
		sm=max(sm,tmp);
	}
	REP(i,N)sm-=get<1>(blu[i])*get<0>(blu[i]);
	return sm>=0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>X;
	REP(i,N)cin>>get<0>(blu[i])>>get<1>(blu[i])>>get<2>(blu[i]);
	blu[N]=make_tuple(0,0,0);
	REP(i,N+1)inx[i]=i;
	sort(blu,blu+N+1,[](TUP x,TUP y){
		return get<1>(x)*get<0>(x)+get<2>(x)*(X-get<0>(x))
			>get<1>(y)*get<0>(y)+get<2>(y)*(X-get<0>(y));
	});
	psm[0]=0;
	REP(i,N+1){
		psm[i+1]=psm[i]+tsm(i);
	}
	ll lb=-1,ub=N*X;
	while(ub-lb>1){
		ll m=(lb+ub)>>1;
		if(C(m)){
			ub=m;
		}else{
			lb=m;
		}
	}
	cout<<ub<<endl;
}