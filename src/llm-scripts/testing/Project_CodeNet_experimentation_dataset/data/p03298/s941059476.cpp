#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
static const ll mod = 1e9 + 7;
static const ll INF = 1LL << 50;
using namespace std;

//red:0 blue:1
signed main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	ll n;
	string s;
	cin>>n>>s;
	vector<string>red(1<<n,""),blue(1<<n,"");
	map<pair<string,string>,ll>mp;
	for(int i=0;i<(1<<n);++i){//前半分全列挙
		for(int j=0;j<n;++j){
			if(i>>j&1){
				red[i]+=string{s[n-1-j]};
			}
			else blue[i]+=string{s[n-1-j]};
		}
		//前半分について逆から読んだ赤、青と、後ろ半分についての青、赤が一致しているか調べる
		string ope="",ope2="";
		for(int j=0;j<n;++j){
			if(i>>j&1){
				ope+=string{s[n+j]};
			}
			else ope2+=string{s[n+j]};
		}
		mp[make_pair(ope,ope2)]++;
	}
	ll ans=0;
	for(int i=0;i<(1<<n);++i){
		ll x=mp[make_pair(blue[i],red[i])];
		ans+=x;
	}
	cout<<ans<<endl;
	return 0;
}
