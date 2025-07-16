#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define sum(a) accumulate(a.begin(),a.end(),0LL)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

ll mod = 1e9+7;
vector<ll> cnt(1e3+1,0);

void disassenmble(ll n){
   for(long long i = 2; i * i <= n; i++){
       if(n % i != 0){ continue; }
       ll ex = 0;
       while(n % i == 0){
           ex++;
           n /= i;
       }
       cnt[i] += ex;
   }
   if(n != 1) ++cnt[n];
}

int main(){
    ll n; cin >> n;

    ll ans = 1;
    for(long long i = 1; i <= n; i++) disassenmble(i);
    for(long long i = 2; i <= n; i++){
        if(cnt[i]) ans = (ans * (cnt[i] + 1)) % mod;
    }
    //for(long long i = 0; i <= n; i++){ cout << cnt[i] << " ";} cout << endl;
    put(ans);
}