#include<bits/stdc++.h>
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
 
template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr long long inf = 3e18;


class BIT{
	int N;
	vector<int>bit;
	void add_(int x,int y){
		while(x<=N){
			bit[x]+=y;x+=x&-x;
		}
	}
	int sum_(int x){
		int res=0;
		while(x>0){
			res+=bit[x];x-=x&-x;
		}
		return res;
	}
public:
	int lower_bound(int w){
		if(w<=0)return -1;
		int x=0;
		int k=1;while(k*2<=N)k*=2;
		for(;k>0;k/=2){
			if(x+k<=N&&bit[x+k]<w){
				w-=bit[x+k];
				x+=k;
			}
		}
		return x;
	}
	void add(int x,int y){add_(x+1,y);}
	int sum(int l,int r){return sum_(r)-sum_(l);}
	BIT(int x):N(x),bit(x+1){}
};
signed main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int N,Q;cin>>N>>Q;
	BIT bit(N);
	rep(i,N){int a;cin>>a;bit.add(i,a);}
	while(Q--){
		int t;cin>>t;
		if(!t){
			int p,x;cin>>p>>x;bit.add(p,x);
		}else {
			int l,r;cin>>l>>r;cout<<bit.sum(l,r)<<"\n";
		}
	}
}