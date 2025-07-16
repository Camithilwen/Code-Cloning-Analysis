#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

#define rep(i,n) for(ll i=0;i<ll(n);i++)
#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const double pi = 3.14159265358979;

vector<pair<ll, ll>> pf(ll n){
    vector<pair<ll, ll>> res;
    for (ll i = 2; i*i <= n; i++){
        if (n%i != 0){
            continue;
        }
        else{
            ll ex = 0;
            while (n%i == 0){
                ex++;
                n /= i;
            }
            res.push_back({i, ex});
        }
    }
    if (n != 1){
        res.push_back({n, 1});
    }
    return res;

    //素因数分解
    //入力:ll
    //出力:vector<pair<ll, ll>>
    //res[i].first == i番目に小さい素因数
    //res[i].second == res[i].firstの指数
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a,b;
    cin >> a >> b;

    ll g = gcd(a,b);

    vector<pair<ll, ll>> x = pf(g);

    cout << x.size()+1 << endl;


}