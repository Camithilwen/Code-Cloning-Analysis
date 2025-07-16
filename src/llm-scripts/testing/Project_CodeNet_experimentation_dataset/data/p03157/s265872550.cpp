#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll par[314514];
ll ran[314514];
ll n=314514;
ll root(ll x){
	return par[x]==x?x:par[x]=root(par[x]);
}
void unite(ll x,ll y){
	x=root(x);
	y=root(y);
	if(x==y)return;
	if(ran[x]<ran[y])par[x]=y;
	else{
		par[y]=x;
		if(ran[x]==ran[y])ran[x]++;
	}
}
string s[410];
ll cnt[2][314514];
int main(){
	for(int i=1;i<=n;i++)par[i]=i;
	ll h,w;
	cin>>h>>w;
	ll dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
	for(int i=0;i<h;i++)cin>>s[i];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			for(int k=0;k<4;k++){
				if(i+dy[k]<0||i+dy[k]>=h||j+dx[k]<0||j+dy[k]>=w)continue;
				if(s[i][j]!=s[i+dy[k]][j+dx[k]])unite(500*i+j,500*(i+dy[k])+j+dx[k]);
			}
		}
	}
	for(int i=0;i<h;i++)for(int j=0;j<w;j++){
		if(s[i][j]=='.')cnt[0][root(500*i+j)]++;
		else cnt[1][root(500*i+j)]++;
	}
	ll ans=0;
	for(int i=0;i<h;i++)for(int j=0;j<w;j++){
		ans+=cnt[0][500*i+j]*cnt[1][500*i+j];
	}
	cout<<ans<<endl;
	return 0;
}
