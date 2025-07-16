#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
template <class T>
inline void rd(T &x)
{
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)){if(c=='-')f=-1; c=getchar();}
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int N=2e5+10,mod=1e9+7;
char str[N];
int n;
int main() {
	rd(n);
	scanf("%s",str+1);
	int cnt=0,ans=1;
	int cur=0;
	for(int i=1;i<=2*n;++i) {
		int c=str[i]=='B';
		if(c!=cur) cnt++;
		else ans=ans*(ll)cnt%mod,cnt--;
		cur^=1;
	}
	if(cnt!=0) ans=0;
	for(int i=1;i<=n;++i) ans=ans*(ll)i%mod;
	printf("%d",ans);
	return 0;
}