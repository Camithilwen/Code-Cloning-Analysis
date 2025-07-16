#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
using vll=vector<ll>;
using vvll=vector<vll>;
using vi=vector<int>;
using vvi=vector<vector<int>>;
using vb=vector<bool>;
using pii=pair<int,int>;
using vpii=vector<pair<int,int>>;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmay(T& a, T b) {if (a < b) {a = b;return true;}return false;}

//pow(llpow,modpow)
long long modinv(long long a, long long m) {long long b = m, u = 1, v = 0;while (b) {long long t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}

#define rep(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)
//試験導入
#define irep(i, end_i, begin_i) for (ll i = (ll)begin_i-1; i >= (ll)end_i; i--)

long long INF = 1LL<<60;
int main( ){
    int n;
    cin>>n;
    vpii rxy(n),byx(n);
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        pii p=make_pair(x,y);
        rxy[i]=p;
    }
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        pii p=make_pair(y,x);
        byx[i]=p;
    }
    vb fixedr(n,false);
    int cnt=0;
    sort(rxy.begin(),rxy.end());
    sort(byx.begin(),byx.end());
    rep(bi,0,n){
        int  bx=byx[bi].second;
        int  by=byx[bi].first;
        int rfi=-1,vrf=0;
        rep(ri,0,n){
            if(fixedr[ri])continue;
            int rx,ry;
            rx=rxy[ri].first;
            ry=rxy[ri].second;
            if(rx<bx&&ry<by){
                rfi=ri;
            }
        }
        if(rfi!=-1){
            cnt++;
            fixedr[rfi]=true;
        }
    }
    cout<<cnt<<endl;
    return 0;
}


