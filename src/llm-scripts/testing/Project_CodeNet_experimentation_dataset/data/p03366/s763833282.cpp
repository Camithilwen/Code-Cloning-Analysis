#include <bits/stdc++.h>
#define ll long long
#define N 1000100
ll n,s,ans,x[N],p[N];
using namespace std;
int main(){
    scanf("%lld%lld",&n,&s);
    for (ll i=1;i<=n;i++) scanf("%lld%lld",&x[i],&p[i]);
    for (ll l=1,r=n;l<=r;){
        if (x[l]>=s){ans+=x[r]-s; break;}//所有人都在一边直接开过去
        if (x[r]<=s){ans+=s-x[l]; break;}
        ans+=x[r]-x[l]; //每次来回开一趟
        if (p[l]>=p[r])
            while (l<r && p[l]>=p[r]) p[l]+=p[r],r--;//相同往左开
        else while (l<r && p[l]<p[r]) p[r]+=p[l],l++;
    }
    printf("%lld\n",ans);
    return 0;
}