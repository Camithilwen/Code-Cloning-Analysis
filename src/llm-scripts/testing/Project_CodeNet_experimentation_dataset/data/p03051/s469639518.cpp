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
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

const int M=2000000;
ll n,a[M],b[M];

int main(){
	cin>>n;
	ll g=0,cnt=0,res=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		g^=x;
		if(g==0){
			cnt++;
			if(i==n-1){
				for(auto j:a) (res+=j)%=mod;
				(res+=1)%=mod;
			}
			ll t=a[g]+1;
			(a[g]+=t)%=mod;
		}
		else{
			ll t=(a[g]*cnt-b[g]+1+mod)%mod;
			(a[g]+=t)%=mod;
			(b[g]+=t*cnt)%=mod;
			if(i==n-1) res=t;
		}
	}
	cout<<res<<endl;
}