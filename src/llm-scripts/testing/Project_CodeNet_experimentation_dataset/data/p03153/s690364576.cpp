#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
typedef long long ll;
struct edge{
    ll x,y,z;
}e[maxn*4];
ll ans,pre[maxn],fa[maxn],n,a[maxn],b[maxn],c[maxn],d,p,q;
int l[maxn],r[maxn];

int ffind(int x){
    if (pre[x]==x) return x;
    pre[x]=ffind(pre[x]); return pre[x];
}

void union_(int u,int v){
    pre[v]=u;
    b[u]=min(b[u],b[v]);
    c[u]=min(c[u],c[v]);
}

bool cmp(edge x,edge y){
    return x.z<y.z;
}

ll cost(int u,int v){
    return 1ll*abs(u-v)*d+a[u]+a[v];
}
ll f[maxn],g[maxn];

int main(){
    cin >> n >> d; int cnt=0;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) fa[i]=pre[i]=i,b[i]=a[i]-d*i,c[i]=a[i]+d*i;
    int tot=n;
    while (tot>1){
        int p=1; ll res=b[fa[1]];
        for (int i=2;i<=tot;i++){
            ll tmp=c[fa[i]];
            f[i]=tmp+res,g[i]=p;
            if (b[fa[i]]<res) res=b[fa[i]],p=i;
        }
        int q=n; res=c[fa[tot]];
        for (int i=tot-1;i;i--){
            ll tmp=b[fa[i]];
            if (i==1||tmp+res<f[i]) f[i]=tmp+res,g[i]=q;
            if (c[fa[i]]<res) res=c[fa[i]],q=i;
        }
        for (int i=1;i<=tot;i++){
            int u=ffind(fa[i]),v=ffind(fa[g[i]]);
            if (u!=v) union_(u,v),ans+=f[i];
        }
        tot=0;
        for (int i=1;i<=n;i++){
            fa[++tot]=ffind(i);
            while (i<n&&ffind(i+1)==fa[tot]) i++;
        }
    }
    cout << ans << endl;
}
