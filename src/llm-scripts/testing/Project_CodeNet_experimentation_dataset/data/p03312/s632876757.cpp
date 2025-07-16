#include <bits/stdc++.h>
using namespace std;
long long s[200005],sum[200005],a,b,c,d,maxx,minn,ans=1e18;
long long get(int l,int r){
    return sum[r]-sum[l-1];
}
int n;
int main(){
	scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&s[i]);
        sum[i]=s[i]+sum[i-1];
    }
    int l=1,r=3;
    for(int i=2;i<n-1;i++){
        while(l<=(i-2)&&abs(get(1,l)-get(l+1,i))>=abs(get(1,l+1)-get(l+2,i)))l++;
        while(r<=(n-2)&&abs(get(i+1,r)-get(r+1,n))>=abs(get(i+1,r+1)-get(r+2,n)))r++;
        a=get(1,l);
        b=get(l+1,i);
        c=get(i+1,r);
        d=get(r+1,n);
        maxx=max(max(a,b),max(c,d));
        minn=min(min(a,b),min(c,d));
        ans=min(ans,maxx-minn);
    }
    printf("%lld\n",ans);
}