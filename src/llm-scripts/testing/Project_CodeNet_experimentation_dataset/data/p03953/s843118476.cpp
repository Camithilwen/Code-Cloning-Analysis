#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int n,m,a[maxn],ans[maxn],res[maxn],tmp[maxn];
long long k;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    for(int i=1;i<n;++i)ans[i]=i;
    scanf("%d%lld",&m,&k);
    for(int i=1;i<=m;++i){
        int x;
        scanf("%d",&x);
        swap(ans[x],ans[x-1]);
    }
    for(int i=1;i<n;++i)res[i]=i;
    while(k){
        if(k&1)
            for(int i=1;i<n;++i)res[i]=ans[res[i]];
        for(int i=1;i<n;++i)tmp[i]=ans[ans[i]];
        for(int i=1;i<n;++i)ans[i]=tmp[i];
        k>>=1;
    }
    long long sum=a[1];
    for(int i=1;i<=n;++i){
        printf("%lld.0\n",sum);
        sum+=a[res[i]+1]-a[res[i]];
    }
}