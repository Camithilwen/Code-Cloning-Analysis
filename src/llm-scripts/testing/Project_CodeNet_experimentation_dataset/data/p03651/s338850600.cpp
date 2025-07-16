#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)	
#define REP(i,b) FOR(i,0,b)
int read(){
	int i;
	scanf("%lld",&i);
	return i;
}
using vi=vector<int>;
#define PB push_back
#define ALL(x) x.begin(),x.end()

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

signed main(){
	int n=read(),k=read();
	vi a(n);
	REP(i,n)a[i]=read();
	int mx=*max_element(ALL(a));
	FOR(i,1,n)
		a[0]=gcd(a[0],a[i]);
	if(k%a[0]==0&&k<=mx)
		cout<<"POSSIBLE"<<endl;
	else
		cout<<"IMPOSSIBLE"<<endl;
}
