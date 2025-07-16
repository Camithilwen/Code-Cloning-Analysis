#include <bits/stdc++.h>
 
#ifdef NON_SUBMIT
#define TEST(n) (n)
#define tout cerr
#else
#define TEST(n) ((void)0)
#define tout cin
#endif
 
using namespace std;
 
const int MOD=1e9+7;
int D[1<<20], Dsum[1<<20], Dminus[1<<20], PS[500001];
 
long long mod(long long a)
{
	if(a>=0) return a%MOD;
	return ((-a/MOD+1)*MOD+a)%MOD;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt","r",stdin));
	TEST(freopen("output.txt","w",stdout));
	TEST(freopen("debug.txt","w",stderr));
	int N, PX=0, A;
	cin>>N; PS[0]=1;
	for(int i=1;i<=N;i++) {
		cin>>A;
		if(PX^=A) {
			D[PX]=mod(1+1LL*Dsum[PX]*PS[i-1]-1LL*Dminus[PX]);
			Dsum[PX]=(Dsum[PX]+D[PX])%MOD;
			Dminus[PX]=(Dminus[PX]+1LL*D[PX]*PS[i-1])%MOD;
		}
		else PS[i]=1;
		PS[i]+=PS[i-1];
	}
	if(PX) cout<<D[PX]<<'\n';
	else {
		int ans=1;
		for(int i=2;i<PS[N];i++) ans=(2*ans)%MOD;
		for(int i=(1<<20)-1;i;i--) ans=(ans+Dsum[i])%MOD;
		cout<<ans<<'\n';
	}
	return 0;
}