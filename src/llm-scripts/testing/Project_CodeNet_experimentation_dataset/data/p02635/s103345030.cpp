#include <bits/stdc++.h>
using namespace std;
#define int long long
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define fasty ios_base::sync_with_stdio(0),cin.tie(0);
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define mt make_tuple
#define all(a) a.begin(),a.end()
#define reset(f, x) memset(f, x, sizeof(f))
#define gg exit(0);

const int M=998244353;

int k,n;
int f[333][333][333];
string s;
vector<int> val;

void add(int &a,int b){
    a=(a+b)%M;
}

main(){
    #define task "TASK"
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        //freopen(task".out","w",stdout);
    }
    cin>>s>>k; n=s.size(), s=" "+s, k=min(k,(int)s.size());
    int i=1;
    while(i<=n){
        int j=i;
        while(s[j]=='1') j++;
        val.pb(j-i);
        i=j+1;
    }
    if(s[n]=='0') val.pb(0);
    n=val.size();
    f[n][0][0]=1;
    fordec(i,n,1) forinc(j,0,k) forinc(t,0,j) if(f[i][j][t]){
        for(int p=1;p+j<=k && p<=val[i-1];p++){
            //if(i==n) cerr<<p<<" ";
            add(f[i-1][j+p][t+p],f[i][j][t]);
        }
        for(int p=1;p<=t;++p){

            add(f[i-1][j][t-p],f[i][j][t]);
        }
        add(f[i-1][j][t],f[i][j][t]);
    }
    int tot=0;
    forinc(j,0,k)
        add(tot,f[0][j][0]);
    cout<<tot;
}
