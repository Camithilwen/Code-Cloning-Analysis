#include<bits/stdc++.h>
#define pir pair<int,int>
#define qmin(x,y) (x=min(x,y))
#define qmax(x,y) (x=max(x,y))
#define rsort(x,y) sort(x,y),reverse(x,y)
#define fr first
#define se second
using namespace std;
typedef long long ll;
const int Maxn=4100000;
const int inf=0x3f3f3f3f;

int n,x[Maxn],y[Maxn],dir[Maxn],bj[Maxn];
vector<pir> v[Maxn];

int getadir() {
    char ch=getchar();
    while(!isalpha(ch)) ch=getchar();
    switch(ch) {
        case 'U' : return 0;
        case 'R' : return 1;
        case 'D' : return 2;
        case 'L' : return 3;
    }
}

signed main() {
    // freopen("test.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&x[i],&y[i]);
        dir[i]=getadir();
    }
    int ans=inf;
    for(int i=1;i<=n;i++) if((dir[i]&1)==0) v[x[i]].push_back(make_pair(y[i],i)),bj[x[i]]=1;
    for(int i=1;i<Maxn;i++) if(bj[i]) {
        sort(v[i].begin(),v[i].end());
        int temp=0;
        for(pir j:v[i]) {
            if(dir[j.se]==2) {
                if(temp) qmin(ans,j.fr-y[temp]);
            }
            else temp=j.se;
        }
    }
    for(int i=1;i<Maxn;i++) if(bj[i]) v[i].clear(),bj[i]=0;
    for(int i=1;i<=n;i++) if(dir[i]&1) v[y[i]].push_back(make_pair(x[i],i)),bj[y[i]]=1;
    for(int i=1;i<Maxn;i++) if(bj[i]) {
        sort(v[i].begin(),v[i].end());
        int temp=0;
        for(pir j:v[i]) {
            if(dir[j.se]==3) {
                if(temp) qmin(ans,j.fr-x[temp]);
            }
            else temp=j.se;
        }
    }
    for(int i=1;i<Maxn;i++) if(bj[i]) v[i].clear(),bj[i]=0;
    for(int i=1;i<=n;i++) v[x[i]+y[i]].push_back(make_pair(x[i],i)),bj[x[i]+y[i]]=1;
    for(int i=1;i<Maxn;i++) if(bj[i]) {
        sort(v[i].begin(),v[i].end());
        int tempx=0,tempy=0;
        for(pir j:v[i]) {
            if(dir[j.se]==0) {
                if(tempy) qmin(ans,(j.fr-x[tempy])*2);
            }
            else if(dir[j.se]==1) tempy=j.se;
            else if(dir[j.se]==2) tempx=j.se;
            else if(tempx) qmin(ans,(j.fr-x[tempx])*2);
        }
    }
    for(int i=1;i<Maxn;i++) if(bj[i]) v[i].clear(),bj[i]=0;
    for(int i=1;i<=n;i++) v[x[i]-y[i]+2000000].push_back(make_pair(x[i],i)),bj[x[i]-y[i]+2000000]=1;
    for(int i=1;i<Maxn;i++) if(bj[i]) {
        sort(v[i].begin(),v[i].end());
        int tempx=0,tempy=0;
        for(pir j:v[i]) {
            if(dir[j.se]==3) {
                if(tempy) qmin(ans,(j.fr-x[tempy])*2);
            }
            else if(dir[j.se]==0) tempy=j.se;
            else if(dir[j.se]==1) tempx=j.se;
            else if(tempx) qmin(ans,(j.fr-x[tempx])*2);
        }
    }
    for(int i=1;i<Maxn;i++) if(bj[i]) v[i].clear(),bj[i]=0;
    if(ans==inf) return 0*puts("SAFE");
    ans*=5;
    printf("%d\n",ans);
    return 0;
}