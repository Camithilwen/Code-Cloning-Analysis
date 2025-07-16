#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define EPS      (double)1e-9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cerr<<' ';cerr<<elem;}cerr<<endl;}

template<typename Type,typename Type_k>
Type ipow(Type n,Type_k k){//n^k. O(log n).
	if(k==0) return 1;
	Type res=ipow(n*n,k/2);
	if(k&1) res*=n;
	return res;
}

int main(){//解説参考.
	llong n;
	cin>>n;
	
	string ans="";
	for(int i=0;n!=0;++i){
		llong tmp=ipow(-2LL,i);
		if(n%(-2*tmp)){
			n-=tmp;
			ans+='1';
		}else ans+='0';
	}
	if(ans=="") ans="0";
	else reverse(ALL(ans));
	
	cout<<ans<<endl;
}