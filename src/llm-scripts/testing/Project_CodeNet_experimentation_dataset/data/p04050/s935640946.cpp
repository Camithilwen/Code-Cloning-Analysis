#include<bits/stdc++.h>
#define ll long long
#define inf(x) (ll)(1e##x)
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
int n,m;
vector<int> v[3];
int main(){
	read(n);read(m);
	for(int i=1;i<=m;i++){
		int x;read(x);
		v[x&1].push_back(x);
	}
	if(v[1].size()>2){puts("Impossible");return 0;}
	if(m==1){
		int p=v[0].size()?v[0][0]:v[1][0];
		cout<<p<<'\n';
		cout<<p/2+1<<'\n';
		if(p&1){
			for(int i=1;i<=p/2;i++) cout<<2<<' ';
			cout<<1<<'\n';
		}
		else{
			for(int i=1;i<=p/4;i++) cout<<2<<' ';
			cout<<1<<' ';
			for(int i=1;i<=(p-2)/4;i++) cout<<2<<' ';
			cout<<1<<'\n';
		}
		return 0;
	}
	if(v[1].size()) v[2].push_back(v[1][0]);
	for(int x:v[0]) v[2].push_back(x);
	if(v[1].size()>1) v[2].push_back(v[1][1]);
	for(int x:v[2]) cout<<x<<' ';cout<<'\n';
	cout<<v[2].size()-(v[2].back()==1)<<'\n';
	cout<<v[2][0]+1<<' ';
	for(int i=1;i+1<v[2].size();i++) cout<<v[2][i]<<' ';
	if(v[2].back()>1) cout<<v[2].back()-1<<'\n';
	return 0;
}