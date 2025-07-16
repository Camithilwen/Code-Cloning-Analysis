#include<bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
#define fs first
#define sd second
const int N=2e5;
const long long oo=1e16+5;
int du[]={-1,0,0,1};
int dv[]={0,-1,1,0};
const long long mod=1e9+7;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
long long sqr(long long x) {return x*x;}
int getbit(int state, int i) {return ((state>>i)&1);}

int n,nq,A,B,q[N+5];
long long res=oo;
struct IT
{
    long long f[4*N+5];
    long long lz[4*N+5];
    long long a[N+5];
    void build(int id, int l, int r)
    {
        if (l>r) return;
        if (l==r) {f[id]=a[l]; return;}
        int mid=(l+r)/2;
        build(id*2,l,mid); build(id*2+1,mid+1,r);
        f[id]=min(f[id*2],f[id*2+1]);
    }
    void down(int id)
    {
        long long val=lz[id]; lz[id]=0;
        f[id*2]+=val; f[id*2+1]+=val;
        lz[id*2]+=val; lz[id*2+1]+=val;
    }
    void update(int id, int l, int r, int u, long long val)
    {
        if (l>u || r<u || l>r) return;
        if (l==r)
        {
            f[id]=min(f[id],val);
            return;
        }
        int mid=(l+r)/2;
        down(id);
        update(id*2,l,mid,u,val); update(id*2+1,mid+1,r,u,val);
        f[id]=min(f[id*2],f[id*2+1]);
    }
    long long get(int id, int l, int r, int u, int v)
    {
        if (l>r || l>v || r<u) return oo;
        if (u<=l && r<=v) return f[id];
        int mid=(l+r)/2;
        down(id);
        return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }
} tru,cong;
int main()
{
	//freopen("Many Moves.inp","r",stdin);
	//freopen("Many Moves.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin>>n>>nq;
    cin>>A>>B;
    for (int i=1;i<=n;i++)
    {
        tru.a[i]=abs(B-i)-i;
        cong.a[i]=abs(B-i)+i;
    }
    tru.build(1,1,n); cong.build(1,1,n);
    q[0]=A;
    for (int i=1;i<=nq;i++)
    {
        cin>>q[i];
        long long val=abs(q[i]-q[i-1]);
        long long now=min(tru.get(1,1,n,1,q[i])+q[i], cong.get(1,1,n,q[i],n)-q[i]);
        tru.f[1]+=val; cong.f[1]+=val;
        tru.lz[1]+=val; cong.lz[1]+=val;
        tru.update(1,1,n,q[i-1],now-q[i-1]);
        cong.update(1,1,n,q[i-1],now+q[i-1]);
    }
    for (int i=1;i<=n;i++)
    {
        res=min(res,tru.get(1,1,n,i,i)+i);
    }
    cout<<res;
	return 0;
}
