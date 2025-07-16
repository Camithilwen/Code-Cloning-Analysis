#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;}
ll lcm(ll x, ll y) {return x/gcd(x,y)*y;}

// 素因数分解 O(√n)
// たとえば 60 = 2^2 x 3 x 5 だったら {(2, 2), (3, 1), (5, 1)} を返す
// 素因数の個数はlogn
vector<pair<ll,ll>> prime_factorize(ll n){
    vector<pair<ll,ll>> res;
    for(ll p=2;p*p<=n;p++){
        if(n%p!=0) continue;
        int num=0; // 指数
        while(n%p==0){
            num++;
            n/=p;
        }
        res.push_back({p,num});
    }
    if(n!=1) res.push_back({n,1});
    return res;
}


int main(){
    ll a,b;
    cin>>a>>b;

    ll g=gcd(a,b);

    if(g==1){
        cout<<1<<endl;
        return 0;
    }

    auto pf=prime_factorize(g);
    cout<<pf.size()+1<<endl;
}
