#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
const int N=1e6+10;
int n,q[N],ans;char s[N],t[N];
int main(){
    scanf("%d%s%s",&n,s+1,t+1);
    int flag=0;
    rep(i,1,n) if(s[i]^t[i]){flag=1;break;}
    if(!flag) return puts("0"),0;
    int i=n,j=n,l=1,r=0;
    while(i){
        while(i>1&&t[i]==t[i-1]) --i;
        //printf("%d %d\n",i,j);
        while(j&&(s[j]!=t[i]||j>i)) --j;
        if(!j) return puts("-1"),0;
        while(l<=r&&q[l]-(r-l+1)>=i) ++l;
        if(i!=j) q[++r]=j;
        ans=max(ans,r-l+2);--i;
    }
    printf("%d\n",ans);
    return 0;
}