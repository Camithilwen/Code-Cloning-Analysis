#include<bits/stdc++.h>
#define ll int
#define ld long double 
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace :: std;

const ll maxn=2010;


char jad[maxn][maxn];
ll ava[maxn];
ll l[maxn];
ll r[maxn];

ll finds(ll n){
	stack<ll> stk;
	for(ll i=0;i<n;i++){
		while(!stk.empty() && ava[stk.top()]>=ava[i]){
			stk.pop();
		}
		if(stk.empty()){
			l[i]=-1;
		}else{
			l[i]=stk.top();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		stk.pop();
	}
	for(ll i=n-1;i>=0;i--){
		while(!stk.empty() && ava[stk.top()]>=ava[i]){
			stk.pop();
		}
		if(stk.empty()){
			r[i]=n;
		}else{
			r[i]=stk.top();
		}
		stk.push(i);
	}
	ll ans=0;
	for(ll i=0;i<n;i++){
		ans=max(ans,(ava[i]+1)*(r[i]-l[i]));
	}
	return ans;
}
bool good(ll i,ll j){
	int t=0;
	if(jad[i][j]=='#'){
		t^=1;
	}
	if(jad[i+1][j]=='#'){
		t^=1;
	}
	if(jad[i][j+1]=='#'){
		t^=1;
	}
	if(jad[i+1][j+1]=='#'){
		t^=1;
	}
	if(t&1){
		return 0;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll w,h;
	cin>>w>>h;
	for(ll i=0;i<w;i++){
		for(ll j=0;j<h;j++){
			cin>>jad[i][j];
		}
	}	
	ll ans=w;
	for(ll i=0;i<w-1;i++){
		for(ll j=0;j<h-1;j++){
			if(good(i,j)){
				ava[j]++;
			}else{
				ava[j]=0;
			}
		}
		ans=max(ans,finds(h-1));
	}




	cout<<ans;

}
