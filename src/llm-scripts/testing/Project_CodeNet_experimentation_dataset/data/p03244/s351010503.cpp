#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vi  = vector<int>;
#define _GLIBCXX_DEBUG
#define IO_STREAM cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define rep(i,sta,end) for(int i=sta;i<end;++i)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
const ll INF = 1000000000000000;
const ll MOD = 1000000007;
const double PI = acos(-1);
//||
#define DBG(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl
//DBG("","","","");

int main(){
	IO_STREAM;
	int n;	cin>>n;
	vector<pair<int,int>>odd(100000);
	vector<pair<int,int>>even(100000);
	set<int>kind;
	rep(i,0,n){
		int v;
		cin>>v;
		kind.insert(v);
		if(i%2==0){
			even[v].first++;
			even[v].second=v;
		}
		else{
			odd[v].first++;
			odd[v].second=v;
		}
	}
	sort(all(even));
	reverse(all(even));
	sort(all(odd));
	reverse(all(odd));
	int ans;
	if(kind.size()==1){
		ans=n/2;
	}
	else{
		ans=100000;
		if(odd[0].second!=even[0].second)	ans=min(ans,n-odd[0].first-even[0].first);
		if(odd[0].second!=even[1].second)	ans=min(ans,n-odd[0].first-even[1].first);
		if(odd[1].second!=even[0].second)	ans=min(ans,n-odd[1].first-even[0].first);
		if(odd[1].second!=even[1].second)	ans=min(ans,n-odd[1].first-even[1].first);
	}
	cout<<ans<<endl;
	return 0;
}
