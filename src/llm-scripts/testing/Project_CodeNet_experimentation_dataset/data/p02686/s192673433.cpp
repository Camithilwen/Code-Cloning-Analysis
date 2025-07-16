#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*

【Yesになるべき。NoでもACしたパターン】
4
(
)((
))((((
))))
*/

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  ll N; cin >> N;
  ll L=0, R=0;
  vector<pair<ll,ll>> plus(0, {0,0}), minus(0, {0,0});
  rep(i, N){
    string S; cin>>S;
    ll q=0, p=0, ssz = S.size();
    for (ll j=0; j<ssz; j++){
      if (S[j] == '(')
        p++;
      else{
        if (p) p--;
        else q++;
      }
    }
    if (q==0)
      R += p;
    else if (p==0)
      L += q;
    else{
      ll tmp = p-q; //プラスなら '(' が回復
      if (tmp > 0)
        plus.push_back({q, p});
      else
        minus.push_back({q, p});
    }
  }
  bool ans = true;
  sort(all(plus));
  sort(all(minus));
  reverse(all(minus));
  ll psz = plus.size();
  //まず回復パターン。弱い攻撃から受ける
  rep(i, psz){
    R -= plus[i].first;
    if (R < 0){
      ans = false;
      break;
    }
    R += plus[i].second;
  }
  //防御パターン。大きい攻撃から受ける
  ll msz = minus.size();
  rep(i, msz){
    R -= minus[i].first;
    if (R < 0){
      ans = false;
      break;
    }
    R += minus[i].second;
  }
  R -= L;
  if (R != 0)
    ans = false;
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
