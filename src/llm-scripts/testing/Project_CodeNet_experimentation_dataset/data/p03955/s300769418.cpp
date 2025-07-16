//Zory-2019
#include<bits/stdc++.h>
using namespace std;
namespace mine
{
    typedef long long ll;
    #define pr pair<int,int>
    #define FR first
    #define SE second
    #define MP make_pair
    #define PB push_back
    #define vc vector
    #define all(x) (x).begin(),(x).end()
    #define sz(x) ((int)(x).size())
    #define bin(x) (1ll<<(x))
    #define GG(x) if(x) {puts("error");exit(666);}
    #define fo(i,l,r) for(int i=(l),I=(r);i<=I;i++)
    #define fd(i,r,l) for(int i=(r),I=(l);i>=I;i--)
    ll qread()
    {
        ll ans=0,f=1;char c=getchar();
        while(c<'0' or c>'9') {if(c=='-')f=-1;c=getchar();}
        while('0'<=c and c<='9') ans=ans*10+c-'0',c=getchar();
        return ans*f;
    }
    void write(ll num)
    {
        if(num<0) putchar('-'),num=-num;
        if(num>=10) write(num/10);
        putchar('0'+num%10);
    }
    void write1(ll num){write(num);putchar(' ');}
    void write2(ll num){write(num);putchar('\n');}
    template<typename T> void chmax(T &x,const T y) {x=(x>y?x:y);}
    template<typename T> void chmin(T &x,const T y) {x=(x<y?x:y);}
    ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}

    const int INF=0x3f3f3f3f;
    const int MOD=1e9+7;
    int mm(const int x){return x>=MOD?x-MOD:x;}
    template<typename T> void add(T &x,const int &y){x=(x+y>=MOD?x+y-MOD:x+y);}
    ll qpower(ll x,ll e,int mod=MOD){ll ans=1;GG(e<0)while(e){if(e&1)ans=ans*x%mod;x=x*x%mod;e>>=1;}return ans;}
    ll invm(ll x){return qpower(x,MOD-2);}
    const int N=1e6+10;

    struct BIT
    {
        int bit[N];BIT(){memset(bit,0,sizeof bit);}
        int lowbit(int x){return x&-x;}
        void add(int x,int c){while(x<N)bit[x]+=c,x+=lowbit(x);}
        int ask(int x){int ans=0;while(x>=1)ans+=bit[x],x-=lowbit(x);return ans;}
    }bit[2];
    int fm[3][N];int getid(int num){return 1+(num-1)/3;}
    void gg(){puts("No");exit(0);}
    int inv[2],flip[2];
	void main()
	{
        int n=qread();fo(op,0,2) fo(i,1,n) fm[op][i]=qread();
        fo(i,1,n)
        {
            if(getid(fm[0][i])!=getid(fm[1][i]) or getid(fm[1][i])!=getid(fm[2][i])) gg();
            bool x=fm[0][i]<fm[1][i] and fm[1][i]<fm[2][i],y=fm[0][i]>fm[1][i] and fm[1][i]>fm[2][i];
            if(!x and !y) gg();flip[i&1]+=y;
            int id=getid(fm[0][i]);if((id&1)^(i&1)) gg();
            inv[i&1]+=bit[i&1].ask(n-id+1),bit[i&1].add(n-id+1,1);
        }
        if((inv[0]&1)^(flip[1]&1) or (inv[1]&1)^(flip[0]&1)) gg();
        puts("Yes");
	}
};//(ans+MOD)%MOD
signed main()
{
    srand(time(0));
    mine::main();
}
