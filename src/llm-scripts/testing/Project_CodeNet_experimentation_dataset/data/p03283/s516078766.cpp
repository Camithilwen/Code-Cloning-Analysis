#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef tuple<long double,ll,ll> T;
const ll mod=1e9+7,INF=mod*mod*3;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair

ll N,M,Q;
vector<ll> V[505];

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>M>>Q;
rep(i,M){
	ll L,R;
	cin>>L>>R;
	V[L].pb(R);
}
rep1(i,N+1){
	if(V[i].size()) sort(V[i].begin(),V[i].end());
}
rep(i,Q){
	ll ans=0;
	ll p,q;
	cin>>p>>q;
	for(ll j=p;j<=q;j++){
		ll sz=V[j].size();
		ll k=upper_bound(V[j].begin(),V[j].end(),q)-V[j].begin();
		ans+=k;
	}
	cout<<ans<<endl;
}



}
	