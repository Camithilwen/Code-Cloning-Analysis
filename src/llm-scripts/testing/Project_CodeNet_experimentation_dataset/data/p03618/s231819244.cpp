#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int res=0;
    char c;
    bool zf=0;
    while(((c=getchar())<'0'||c>'9')&&c!= '-');
    if(c=='-')zf=1;
    else res=c-'0';
    while((c=getchar())>='0'&&c<='9')res=(res<<3)+(res<<1)+c-'0';
    if(zf)return -res;
    return res;
}
int tot[26];
signed main(){
	string ss;cin>>ss;int n=ss.size(),s=0;
	for(register int i=0;i<n;i++)tot[ss[i]-'a']++,s++;
	long long ans=1ll*s*(s-1)/2;for(register int i=0;i<26;i++)ans-=1ll*tot[i]*(tot[i]-1)/2;printf("%lld\n",ans+1);
	return 0;
}