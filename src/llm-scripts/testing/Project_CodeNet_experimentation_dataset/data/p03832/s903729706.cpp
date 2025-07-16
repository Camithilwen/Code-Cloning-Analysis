#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////
#define N 100004

ll kai[N];
ll kai2[N];
ll po(ll i,ll p){
    if(p==0)return 1;
    else if(p==1)return mod(i);
    else if(p%2==0)return mod(po(mod(mod(i)*mod(i)),p/2));
    else  return mod(mod(i)*mod(po(i,p-1)));
}
void calc(){
    kai[0]=1;
    kai2[0]=1;
    for(int i=1;i<N;i++){
        kai[i]=mod(kai[i-1]*i);
        kai2[i]=mod(po(kai[i],i_5));
    }
}
ll comb(ll n,ll k){
    if(n==0){
        if(k==0)return 1;
        else return 0;
    }
    else if(n<k)return 0;
    else return mod(mod(mod(kai[n])*mod(kai2[n-k]))*mod(kai2[k]));
}

//#include <time.h>

int main(){
   // clock_t start = clock();    // スタート時間
    calc();
    ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    ll dp[n+5][n+5];
    memset(dp,0,sizeof(dp));
    dp[a][0]=1;
    
    rep(k,a,b){
        rep(j,0,n){
            for(ll p=0;j+p*k<=n&&p<=d;p++){
                ll add=comb(n-j,p*k);
                add=mod(add*dp[k][j]);
                add=mod(add*kai[p*k]);
                add=mod(add*kai2[p]);
                ll w=(ll)po(kai2[k],p);
                add=mod(add*w);
                Add(&dp[k+1][j+p*k],add);
                if(p==0)p=c-1;
            }
        }
    }
    
    /*rep(i,0,b+1){
        rep(j,0,n){
            cout<<dp[i][j]<<"  ";
        }cout<<endl;
    }*/
    
    cout<<mod(dp[b+1][n])<<endl;
    
    //clock_t end = clock();     // 終了時間
   // std::cout << "duration = " << (double)(end - start) / CLOCKS_PER_SEC << "sec.\n";
    return 0;
}


