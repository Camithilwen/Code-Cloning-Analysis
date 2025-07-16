#include<bits/stdc++.h>
#define mems(a,x) memset(a,x,sizeof(a))
#define first fi
#define second se
using namespace std;
typedef long long ll;
const int mod=1e9+7,N=105;
const double eps=1e-8,pi=3.1415926535898;
ll inv(ll x){return x==1?x:(mod-mod/x)*inv(mod%x)%mod;}
ll inv(ll x,ll mod){return x==1?x:(mod-mod/x)*inv(mod%x,mod)%mod;}
ll qpow(ll a,ll n){ll ans=1;while(n){if(n&1) ans=ans*a%mod;a=a*a%mod;n>>=1;}return ans;}
ll mul(ll a,ll b){ll ans=0;while(b){if(b&1) ans=(ans+a)%mod;a=(a+a)%mod;b>>=1;};return ans;}
ll qpow(ll a,ll n,ll mod){ll ans=1;while(n){if(n&1) ans=ans*a%mod;a=a*a%mod;n>>=1;}return ans;}
ll mul(ll a,ll b,ll mod){ll ans=0;while(b){if(b&1) ans=(ans+a)%mod;a=(a+a)%mod;b>>=1;};return ans;}
struct vec
{
    double x,y;
    int id;
    vec(double x=0,double y=0):x(x),y(y){}
    vec operator+(const vec&o)const{ return vec(x+o.x,y+o.y);}
    vec operator-(const vec&o)const{ return vec(x-o.x,y-o.y);}
    double operator*(const vec&o)const{ return x*o.x+y*o.y;}
    double operator^(const vec&o)const{ return x*o.y-y*o.x;}
    vec operator/(const double&o)const{ return vec(x/o,y/o);}
    vec operator*(const double&o)const{ return vec(x*o,y*o);}
    void sc(){scanf("%lf%lf",&x,&y);}
    double len(){return sqrt(x*x+y*y);}
}a[N],s[N];
int n,top;
bool cmp(vec x,vec y)
{
    double k1=atan2(x.y-a[1].y,x.x-a[1].x),k2=atan2(y.y-a[1].y,y.x-a[1].x);
    if(fabs(k1-k2)<eps) return x.x<y.x;
    return k1<k2;
}
double ans[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) a[i].sc(),a[i].id=i;
    for(int i=1;i<=n;i++)
        if(a[i].y<a[1].y||a[i].y==a[1].y&&a[i].x<a[1].x)
        swap(a[i],a[1]);
    sort(a+2,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        while(top>=2&&((s[top-1]-a[i])^(s[top]-a[i]))<=0) top--;
        s[++top]=a[i];
    }
    if(top==1) ans[s[1].id]=1;
    else if(top==2) ans[s[1].id]=ans[s[2].id]=0.5;
    else
        for(int i=1;i<=top;i++)
        {
            vec l,r;
            if(i==1) l=s[top];
            else l=s[i-1];
            if(i==top) r=s[1];
            else r=s[i+1];
            double res=(r-s[i])*(l-s[i]);
            res/=(r-s[i]).len()*(l-s[i]).len();
            res=pi-acos(res);
            res/=2*pi;
            ans[s[i].id]=res;
        }
    for(int i=1;i<=n;i++)
        printf("%.10f\n",ans[i]);
}
