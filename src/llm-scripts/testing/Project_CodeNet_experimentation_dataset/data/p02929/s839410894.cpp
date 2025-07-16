#include<iostream>
#include<cstdio>
const int N=2e5+5;
char s[N];
typedef long long ll;
const ll mod=1e9+7;
int d[N];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    if(s[1]=='W') return !printf("0");
    d[1]=0;
    for(int i=2;i<=n+n;i++) {
        if(s[i]==s[i-1]) d[i]=d[i-1]^1;
        else d[i]=d[i-1];
    }
    int num[2]={0,0};
    for(int i=1;i<=n+n;i++) num[d[i]]++;
    if(num[0]!=n) return !printf("0");
    ll ans=1;
    int cnt=0;
    for(int i=1;i<=n+n;i++) {
        if(d[i]) ans=ans*cnt%mod,cnt--;
        else cnt++;
        if(cnt<0) return !printf("0");
    }
    for(int i=1;i<=n;i++) ans=ans*i%mod;
    printf("%lld\n",ans);
    return 0;
}
