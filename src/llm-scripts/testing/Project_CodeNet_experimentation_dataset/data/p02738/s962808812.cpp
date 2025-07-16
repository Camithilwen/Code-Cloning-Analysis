#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
int n,MOD;
ll fac[SZ],rfac[SZ];
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
ll rw[4];
ll C(int a,int b)
{
	return fac[a]*rfac[a-b]%MOD*rfac[b]%MOD;
}
ll f[6005][2005*6];
int main()
{
	cin>>n>>MOD;
	fac[0]=1;
	for(int i=1;i<SZ;++i)
		fac[i]=fac[i-1]*i%MOD;
	rfac[SZ-1]=qp(fac[SZ-1],MOD-2);
	for(int i=SZ-1;i;--i)
		rfac[i-1]=rfac[i]*i%MOD;
	int N=n*3;
	f[0][N]=1;
	for(int i=0;i<N;++i)
		for(int j=0;j<=N*2;++j) if(f[i][j])
			for(int s=1;s<=3&&i+s<=N;++s)
				(f[i+s][j+(s==1)-(s==2)]+=f[i][j]*fac[i+s-1]%MOD*rfac[i])%=MOD;
	ll aa=0;
	for(int j=N;j<=N*2;++j)
		(aa+=f[N][j])%=MOD;
	aa=(aa%MOD+MOD)%MOD;
	cout<<aa<<"\n";
}
