#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

const ll modseed = pow(10,9) + 7;

template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

ll calculateMod(ll n, ll expo, ll modSeed){
  ll ret = 1;
  rep(i, expo){
    ret *= n;
    ret = ret%modSeed;
  }
  return ret;
}

int main(){
    ll N;
    cin >> N;
    auto inputs = getValues<ll>(N);
    vector<ll> steps(N,0);
    ll ans = 0;
    rep(i, N){
      if(i==0){
        continue;
      }
      ll maenohito = steps.at(i-1) + inputs.at(i-1);
      ll sub = inputs.at(i) - maenohito;
      if(sub < 0){
        steps.at(i) = -sub;
        ans += steps.at(i);
      }
    }
    printl(ans);
}
