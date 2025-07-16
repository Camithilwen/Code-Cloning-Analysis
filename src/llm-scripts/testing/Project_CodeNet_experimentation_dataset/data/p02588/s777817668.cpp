#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fod(i,a,b) for(int i=a;i>=b;i--)
#define me0(a) memset(a,0,sizeof(a))
#define me1(a) memset(a,-1,sizeof(a))
#define op freopen("in.txt", "r", stdin)
#define op1 freopen("C:\\acm\\Cproj\\in.txt","r",stdin);
#define pr freopen("C:\\acm\\Cproj\\out.txt","w",stdout)
#define pr2 freopen("C:\\acm\\Cproj\\std.txt","w",stdout)
#define pii pair<int,int>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long LL;
template <class T>
void read(T &val) { T x = 0; T bz = 1; char c; for (c = getchar(); (c<'0' || c>'9') && c != '-'; c = getchar()); if (c == '-') { bz = -1; c = getchar(); }for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48; val = x * bz; }
const int maxn = 3e5 + 11;
const int mod=998244353;

double eps = 1e-9;

unordered_map<int,int>mpp2[1000],mpp5[1000];
int mx;
LL cal2(int a,int b){
    LL res = 0;
    fo(i,0,a) {
        for(auto to:mpp2[i]){
            if(i+b+to.first>=0) res+=to.second;
        }
    }
    fo(i,a+1,mx){
        for(auto to:mpp2[i]){
            if(a+b+to.first>=0) res+=to.second;
        }
    }
    return res;
}
LL cal5(int a,int b){
    LL res = 0;
    fo(i,0,a) {
        for(auto to:mpp5[i]){
            if(i+b+to.first>=0) res+=to.second;
        }
    }
    fo(i,a+1,mx){
        for(auto to:mpp5[i]){
            if(a+b+to.first>=0) res+=to.second;
        }
    }
    return res;
}


char s[maxn];
int main(){
//    op;
    int n;
    read(n);
    LL ans = 0;
    fo(i,1,n){
        scanf("%s",s);

        int len = strlen(s);
        LL nw = 0;
        int d=0;

        fo(i,0,len-1){
            if(s[i]=='.') d = i-len+1;
            else{
                nw = nw*10+s[i]-'0';
            }
        }
        int n2=0,n5=0;
        while(nw%2==0) n2++,nw/=2;
        while(nw%5==0) n5++,nw/=5;


        int mi = min(n2,n5);
        n2-=mi;n5-=mi;
        mx=max(mx,n2);
        mx=max(mx,n5);
        d+=mi;


        if(n2){
            ans+=cal5(n2,d);
        }
        else{
            ans+=cal2(n5,d);
        }
        mpp2[n2][d]++;
        mpp5[n5][d]++;
    }
    printf("%lld\n",ans);
    return 0;
}