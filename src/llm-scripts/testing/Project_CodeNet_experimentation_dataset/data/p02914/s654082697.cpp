#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<ll,pll> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

const int M=60,N=100000;
ll n,cnt[M],ID=0;
vl a;
vp d;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	a=vl(n);
	vector<bitset<N+1>> b;
	for(auto &i:a){
		cin>>i;
		for(int j=0;j<M;j++) if(i&1ll<<j) cnt[j]++;
	}
	ll sum=0;
	for(int i=M-1;i>=0;i--){
		ll cnt=0,t=1ll<<i;
		bitset<N+1> c;
		c[N]=1;
		for(int j=0;j<n;j++) if(a[j]&t){
			c[j]=1;
			cnt++;
		}
		if(cnt%2==1){
			sum+=t;
			continue;
		}
		sort(d.begin(),d.end());
		for(auto p:d){
			int tmp=p.first,id=p.second;
			if(c[tmp]) c^=b[id];
		}
		bitset<N+1> beet;
		beet[N]=1;
		if(c==beet) continue;
		int I;
		for(int j=0;j<=N;j++) if(c[j]){
			d.push_back({j,ID});
			ID++;
			b.push_back(c);
			I=j;
			break;
		}
		for(int j=0;j<d.size();j++){
			int tmp=d[j].first,id=d[j].second;
			if(tmp<I&&b[id][I]) b[id]^=c;
		}
		sum+=t*2;
	}
	cout<<sum<<endl;
}