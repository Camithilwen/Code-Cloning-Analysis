#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 200000 + 10;
char s[N]; int n;
int lef[N];
int main() {
	scanf("%d%s", &n,s+1);	
	if(s[1] == 'W') return !printf("0\n");
	lef[1]=1;
	for(int i=2;i<=2*n;i++){
		if(s[i]==s[i-1]) lef[i]=1^lef[i-1];
		else lef[i]=lef[i-1];
	}

	int cnt=0,ans=1;
	for(int i=1;i<=2*n;i++){
		//printf("# %d\n", lef[i]);
		if(lef[i]){cnt++;}
		else {	
			ans=1LL*ans*cnt%MOD;
			if(cnt==0)return !printf("0\n");
			cnt--;
		}
	}
	if(cnt)return !printf("0\n");
	for(int i=1;i<=n;i++)ans=1LL*ans*i%MOD;
	cout<<ans<<endl;
}