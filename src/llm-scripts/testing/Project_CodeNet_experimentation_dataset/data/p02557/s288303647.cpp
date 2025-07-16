#include<bits/stdc++.h>
using namespace std;
typedef long long ll;typedef double db;
typedef pair<int, int> pii;typedef pair<ll, ll> pll;
typedef pair<int,ll> pil;typedef pair<ll,int> pli;
#define Fi first
#define Se second
#define _Out(a)	cerr<<#a<<" = "<<(a)<<endl
const int INF = 0x3f3f3f3f, MAXN = 1e6 + 50;
const ll LINF = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const db Pi = acos(-1), EPS = 1e-6;
void test(){cerr << "\n";}template<typename T,typename...Args>void test(T x,Args...args){cerr<<x<<" ";test(args...);}
inline ll qpow(ll a, ll b){return b?((b&1)?a*qpow(a*a%MOD,b>>1)%MOD:qpow(a*a%MOD,b>>1))%MOD:1;}
inline ll qpow(ll a, ll b,ll c){return b?((b&1)?a*qpow(a*a%c,b>>1,c)%c:qpow(a*a%c,b>>1,c)) %c:1;}
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline ll cede(ll a,ll b){if(b<0)return cede(-a,-b);if(a<0)return a/b;return (a+b-1)/b;}
inline ll flde(ll a,ll b){if(b<0)return flde(-a,-b);if(a<0)return (a-b+1)/b;return a/b;}
inline int sign(db x){return x<-EPS ? -1:x>EPS;}
inline int dbcmp(db l,db r){return sign(l - r);}
namespace Fast_IO{ //orz laofu
    const int MAXL((1 << 18) + 1);int iof, iotp;
    char ioif[MAXL], *ioiS, *ioiT, ioof[MAXL],*iooS=ioof,*iooT=ioof+MAXL-1,ioc,iost[55];
    char Getchar(){
        if (ioiS == ioiT){
            ioiS=ioif;ioiT=ioiS+fread(ioif,1,MAXL,stdin);return (ioiS == ioiT ? EOF : *ioiS++);
        }else return (*ioiS++);
    }
    void Write(){fwrite(ioof,1,iooS-ioof,stdout);iooS=ioof;}
    void Putchar(char x){*iooS++ = x;if (iooS == iooT)Write();}
    inline int read(){
        int x=0;for(iof=1,ioc=Getchar();(ioc<'0'||ioc>'9')&&ioc!=EOF;)iof=ioc=='-'?-1:1,ioc=Getchar();
        if(ioc==EOF)Write(),exit(0);
        for(x=0;ioc<='9'&&ioc>='0';ioc=Getchar())x=(x<<3)+(x<<1)+(ioc^48);return x*iof;
    }
    inline long long read_ll(){
        long long x=0;for(iof=1,ioc=Getchar();(ioc<'0'||ioc>'9')&&ioc!=EOF;)iof=ioc=='-'?-1:1,ioc=Getchar();
        if(ioc==EOF)Write(),exit(0);
        for(x=0;ioc<='9'&&ioc>='0';ioc=Getchar())x=(x<<3)+(x<<1)+(ioc^48);return x*iof;
    }
    void Getstr(char *s, int &l){
        for(ioc=Getchar();ioc==' '||ioc=='\n'||ioc=='\t';)ioc=Getchar();
        if(ioc==EOF)Write(),exit(0);
        for(l=0;!(ioc==' '||ioc=='\n'||ioc=='\t'||ioc==EOF);ioc=Getchar())s[l++]=ioc;s[l] = 0;
    }
    template <class Int>void Print(Int x, char ch = '\0'){
        if(!x)Putchar('0');if(x<0)Putchar('-'),x=-x;while(x)iost[++iotp]=x%10+'0',x/=10;
        while(iotp)Putchar(iost[iotp--]);if (ch)Putchar(ch);
    }
    void Putstr(const char *s){for(int i=0,n=strlen(s);i<n;++i)Putchar(s[i]);}
} // namespace Fast_IO
using namespace Fast_IO;


vector<int>pos[MAXN];
pii cnt[MAXN];
int ccnt[MAXN];
int ans[MAXN];
bool cmp(pii l,pii r){return l.first>r.first;}
void work()
{
    int n=read();
    for(int i=1;i<=n;i++)
    {
        int x=read();
        pos[x].push_back(i);
        cnt[x].first++;
        cnt[i].second=i;
    }
    for(int i=1;i<=n;i++)
    {
        int x=read();
        cnt[x].first++;
        ccnt[x]++;
    }
    int nowat=1;
    sort(cnt+1,cnt+1+n,cmp);
    srand(time(0));
    if(cnt[1].first>n)
    {
        printf("No\n");return ;
    }
    random_shuffle(cnt+1,cnt+1+n);
    int zcnt=0;
    for(int i=1;i<=n;i++)
    {
        int QAQ=cnt[i].second;
        if(cnt[nowat].second==QAQ)nowat++;
        if(nowat>n)nowat=1;
        
        while(ccnt[QAQ])
        {
            while(pos[cnt[nowat].second].size()==0||cnt[nowat].second==QAQ)
            {
                
                nowat++;if(nowat>n)nowat=1;
            }
            ans[pos[cnt[nowat].second].back()]=QAQ;
            pos[cnt[nowat].second].pop_back();
            ccnt[QAQ]--;
        }
    }
    printf("Yes\n");
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    
}


int main()
{
    //std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int T=read();for(int cas=1;cas<=T;cas++)
    //int T;scanf("%d",&T);for(int i=1;i<=T;i++)
    work();
    // Write();
}

/**
1 1
4 0 1
4 0 1000000

*/