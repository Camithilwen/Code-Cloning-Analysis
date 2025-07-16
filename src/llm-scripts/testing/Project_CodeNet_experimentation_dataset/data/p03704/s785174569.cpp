#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define eb emplace_back
template<class T>void chmax(T &a,T b){if(a<b)a=b;}
template<class T>void chmin(T &a,T b){if(a>b)a=b;}
constexpr int INF=1000000000000000000;
constexpr int mod=1000000007;
constexpr double eps=1e-8;
const double pi=acos(-1);
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int Random(int mi,int ma){
    random_device rnd;
    mt19937 mt(rnd());//32bit
    //[mi,ma]
    uniform_int_distribution<int>engine(mi,ma);
    return engine(mt);
}
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
bool prime(int a){
    if(a==1)return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0)return false;
    }
    return true;
}
int modpow(int a,int b){
    if(b==0)return 1;
    if(b%2)return modpow(a,b-1)*a%mod;
    int memo=modpow(a,b/2);
    return memo*memo%mod;
}
vector<int>kaijo,invkaijo;
void init_fact(int n){
    kaijo.resize(n+1);
    invkaijo.resize(n+1);
    kaijo[0]=1;
    for(int i=1;i<=n;i++){
        kaijo[i]=kaijo[i-1]*i;
        kaijo[i]%=mod;
    }
    rep(i,n+1)invkaijo[i]=modpow(kaijo[i],mod-2);
}
int comb(int a,int b){
    if(a<b)return 0;
    if(a<0||b<0)return 0;
    return kaijo[a]*invkaijo[a-b]%mod*invkaijo[b]%mod;
}
int inv(int x){
    x=modpow(x,mod-2);
    return x;
}
int n,d,ans;
string s;
int p[110];
void func(int i,int D,int ret){
    if(i==(n+1)/2-1){
        if(D==0){
            if(n%2)ret*=10;
            ans+=ret;
        }
        return;
    }
    {
        //+
        int m=(D+INF)%10;
        int cnt=10-m;
        if(i==n-1)cnt--;
        func(i-1,(D-p[i]*m)/10,ret*cnt);
    }
    {
        //-
        if((D+INF)%10==0)return;
        int m=10-(D+INF)%10;
        int cnt=10-m;
        //if(i==n-1)cnt--;
        func(i-1,(D+p[i]*m)/10,ret*cnt);
    }
}
signed main(){
    cin.tie(0);ios::sync_with_stdio(false);
    cin>>d;
    if(d%9){
        puts("0");
        return 0;
    }
    d/=9;
    for(n=2;n<=18;n++){
        fill(p,p+17,0);
        p[(n+1)/2]=(n%2?11:1);
        for(int i=(n+1)/2+1;i<n;i++)p[i]=(p[i-1]*10+1)*10+1;
        func(n-1,d,1);
        //cout<<d<<" "<<ans<<endl;
        /*if(n==5){
            cout<<p[n-3]<<" "<<p[n-2]<<" "<<p[n-1]<<endl;
        }*/
    }
    cout<<ans<<endl;
    return 0;
}
