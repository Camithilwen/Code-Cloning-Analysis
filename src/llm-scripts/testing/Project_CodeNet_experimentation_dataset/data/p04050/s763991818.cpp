#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<long long,long long> pll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,j,k)  for(register int i=(int)(j);i<=(int)(k);i++)
#define rrep(i,j,k) for(register int i=(int)(j);i>=(int)(k);i--)

ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

const int maxn=200;
int n,m;
int a[maxn];

int main(){
#ifdef LZT
//	freopen("in","r",stdin);
#endif
	int num=0;
	n=read();m=read();
	rep(i,1,m){
		a[i]=read();
		if(a[i]&1) num++;
	}
	if(num>2){
		puts("Impossible");
		return 0;
	}
	for(int i=1;i<=m;i++)
		if(a[i]&1){
			if(a[1]&1) swap(a[i],a[m]);
			else swap(a[i],a[1]);
		}
	rep(i,1,m) cout<<a[i]<<' ';
	cout<<endl;
	a[1]++;a[m]--;
	if(a[m]==0) m--;
	if(m>=2){
		cout<<m<<endl;
		rep(i,1,m) cout<<a[i]<<' ';
		cout<<endl;
	}
	else{
		if(n<=2){
			cout<<1<<endl;
			cout<<n<<endl;
		}
		else{
			cout<<2<<endl;
			cout<<n-1<<' '<<1<<endl;
		}
	}
	return 0;
}
