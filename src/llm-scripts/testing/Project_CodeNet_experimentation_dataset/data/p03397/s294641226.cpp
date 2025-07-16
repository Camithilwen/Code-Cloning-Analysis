#include <bits/stdc++.h>
using namespace std;
#define lor(a,b,c) for(register int a=b;a<=c;++a)
#define ror(a,b,c) for(register int a=c;a>=b;--a)
typedef long long ll;

const int N=3e5+5;
const ll MOD=1e9+7;

char s[N]; int n;
ll f[N][3][3],ans;

inline void inc(ll &a,ll b){
	(a+=b)>=MOD?a-=MOD:a;
}

inline void trans(int &a,int &b,int c){
	if(!c){
		++b; if(b>=3) b-=2;
	}
	else{
		if(b) --b;
		else ++a,a=min(a,2);
	}
}

int main(){

	scanf("%s",s+1); n=strlen(s+1);
	f[0][0][0]=1ll;
	lor(k,1,n){
		if(s[k]!='0'){
			lor(i,0,2) lor(j,0,2){
				int a=i,b=j; trans(a,b,1);
				inc(f[k][a][b],f[k-1][i][j]);
			}
		}
		if(s[k]!='1'){
			lor(i,0,2) lor(j,0,2){
				int a=i,b=j; trans(a,b,0);
				inc(f[k][a][b],f[k-1][i][j]);
			}			
		}
	}
	lor(i,0,2) lor(j,0,i) inc(ans,f[n][i][j]);
	printf("%lld\n",ans);

	return 0;
}