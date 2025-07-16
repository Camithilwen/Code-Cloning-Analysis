#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2>
typedef long long LL;
const LL P = 1e9+7;
const int INF = 0x3fffffff;
const int N = 25;
mt19937 rng(time(0));

int x,y,ans;

int calc(int x){
	if(x==1) return 300000;
	if(x==2) return 200000;
	if(x==3) return 100000;
	return 0;
}

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("test.in","r",stdin);
	#endif
	cin>>x>>y;
	ans = calc(x) + calc(y);
	if(x==1 && y==1) ans += 400000;
	cout<<ans<<endl;
	return 0;
}