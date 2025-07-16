#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N= 998244353;

ll m_pow(ll n, ll k){
    if(k==0) return 1;
    else{
        ll a = (m_pow(n,k/2)*m_pow(n,k/2))%N;
        if(k%2==0) return a;
        else return (a*n)%N;
    }
}

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> mod_pow(n,1),combi(k+1,1);
    for(int i=1; i<n; i++){
        mod_pow.at(i) = mod_pow.at(i-1)*(m-1);
        mod_pow.at(i) %= N;
        if(i>k) continue;
        combi.at(i) = ((n-i)*combi.at(i-1))%N;
        combi.at(i) *= m_pow(i,N-2);
        combi.at(i) %= N;
    }
    ll ans = 0;
    for(int i=0; i<=k; i++){
        ll plus= (m*mod_pow.at(n-1-i))%N;
        plus = (plus*combi.at(i))%N;
        ans += plus;
        ans %= N;
    }
    cout << ans << endl;
    /*
    for(int i=0; i<k+1; i++){
        cout << combi.at(i) << endl;
    }*/

}