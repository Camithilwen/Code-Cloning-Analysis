#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int read(){
    int x=0;bool f=0;char c=getchar();
    while(c<'0'||c>'9') f|=c=='-',c=getchar();
    while(c>='0'&&c<='9') x=x*10+(c^48),c=getchar();
    return f?-x:x;
}

#define MAXN 100000
#define LL long long

int N,X;
LL Sum[MAXN+5],Org,D[MAXN+5];
struct Range{
    LL tot;
    int l,r,id;
}A[MAXN+5];
bool cmp(Range i,Range j){
    return i.tot>j.tot;
}

bool Check(LL expt){
    LL Max=0;
    LL All=expt/X,Rest=expt%X;
    for(int i=1;i<=N;i++){
        LL l=min(Rest,D[A[i].id]);
        LL tmp=i>All?Sum[All]:(Sum[All+1]-A[i].tot);
        Max=max(Max,tmp+l*A[i].l+(Rest-l)*A[i].r);
    }
    return Max>=Org;
}

int main(){
    N=read(),X=read();
    for(int i=1;i<=N;i++){
        D[i]=read();
        A[i].id=i;
        A[i].l=read(),A[i].r=read();
        A[i].tot=D[i]*A[i].l+(X-D[i])*A[i].r;
        Org+=D[i]*A[i].l;
    }
    sort(A+1,A+N+1,cmp);
    for(int i=1;i<=N;i++)
        Sum[i]=Sum[i-1]+A[i].tot;
    LL Left=-1,Right=(LL)X*N;
    while(Left+1<Right){
        LL mid=(Left+Right)>>1;
        if(Check(mid))
            Right=mid;
        else
            Left=mid;
    }
    printf("%lld",Right);
}
