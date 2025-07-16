#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
const int maxn=100010;
int k,n,N,tmp,ans,jc[maxn],iv[maxn],ivjc[maxn],cnt;
int C(int x,int y) {
	if (x<y||y<0) return 0;
	return (ll)jc[x]*ivjc[x-y]%mod*ivjc[y]%mod;
}
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
int main() {
	
	read(k); read(n);
	jc[0]=iv[0]=ivjc[0]=jc[1]=iv[1]=ivjc[1]=1;
	for (int i=2;i<=10000;i++) {
		jc[i]=(ll)jc[i-1]*i%mod;
		iv[i]=(ll)(mod-mod/i)*iv[mod%i]%mod;
		ivjc[i]=(ll)ivjc[i-1]*iv[i]%mod;
	}
	for (int m=2;m<=2*k;m++) {
		cnt=0;
		for (int i=1;i<=k;i++)
			if (i<=m-i&&m-i<=k) cnt++;
		ans=0;
		for (int i=0;i<=cnt;i++) {
			N=n-i*2;
			if (N<0) break;
			tmp=(ll)C(N+k-1,k-1)*C(cnt,i)%mod;
			if (i&1^1) update(ans,tmp);
			else update(ans,mod-tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/