#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
inline int rd() {
    char ch=getchar(); int i=0,f=1;
    while(!isdigit(ch)) {if(ch=='-')f=-1; ch=getchar();}
    while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=getchar();}
    return i*f;
}
const int N=2e5+50;
const LL INF=0x3f3f3f3f3f3f3f3f;
int n,q;
LL bit[2][N],tag,mn=0;
inline void inc(LL *a,int i,LL v) {for(;i<=n;i+=(i&(-i))) a[i]=min(a[i],v);}
inline LL ask(LL *a,int i,LL v=INF) {for(;i;i-=(i&(-i))) v=min(a[i],v); return v;}
int main() {
    n=rd(), q=rd(); 
    int a=rd(), b=rd();
    memset(bit[0],0x3f,sizeof(bit[0]));
    memset(bit[1],0x3f,sizeof(bit[1]));
    inc(bit[0],a,-a); inc(bit[1],n-a+1,a);
    for(int i=1;i<=q;i++) {
        int x=rd();
        LL v=min(ask(bit[0],x)+x,ask(bit[1],n-x+1)-x);
        tag+=abs(x-b); v-=abs(x-b); mn=min(mn,v);
        inc(bit[0],b,v-b); inc(bit[1],n-b+1,v+b);
        b=x;
    }
    printf("%lld\n",mn+tag);
}