#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
#include <vector>
#define rep(i,n) for (ll i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define base10_4 10000      //1e4
#define base10_5 100000     //1e5
#define base10_6 1000000    //1e6
#define base10_7 10000000   //1e7
#define base10_8 100000000  //1e8
#define base10_9 1000000000 //1e9

#define MOD 1000000007
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;

vector<ll> inv,fact,invfact;
void setupCombination(ll n_max,ll mod){
    fact.resize(n_max+1);
    inv.resize(n_max+1);
    invfact.resize(n_max+1);
    fact[0]=inv[0]=invfact[0]=1;
    inv[1]=1;
    for(ll i=0;i<n_max;i++){
        fact[i+1]=fact[i]*(i+1)%mod;
        if(i>0)inv[i+1]=mod-inv[mod%(i+1)]*(mod/(i+1))%mod;
        invfact[i+1]=invfact[i]*inv[i+1]%mod;
    }
}
ll getCombination(ll n,ll k,ll mod){
    if(n<0||k<0||k>n)return 0;
    return (fact[n]*invfact[n-k]%mod)*invfact[k]%mod;
}

/*
max 448,000,000
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/
ll getMod(ll value,ll mod){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    cin >> K;


    ll allnum = N*M;
    setupCombination(allnum+10,MOD);
    ll base = getCombination(allnum-2,K-2,MOD);
    base = getMod(base,MOD);

    ll ans = 0;
    for( ll yoko = 0 ; yoko <N ; yoko++ ){
        for( ll tate = 0 ; tate <M ; tate++ ){
            ll count = (N-yoko) * (M-tate);
            if(tate*yoko>0) count *=2;
            ll distance = yoko + tate;
            //cout << distance << " : " << count << endl;
            ll dA = count * distance;
            dA = getMod(dA,MOD);

            ans += dA;
            ans = getMod(ans,MOD);
        }
    }

    ans = ans * base;
    ans = getMod(ans,MOD);
    cout << ans << endl;

  

}