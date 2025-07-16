#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,INF=mod*mod*3;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair

ll N;
ll p[200005];
ll ans;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N;
rep(i,N) cin>>p[i];
ll pm=INF;
rep(i,N){
	if(pm>=p[i]) pm=p[i];
	if(pm>=p[i]) ans++;
}
cout<<ans<<endl;

}
	