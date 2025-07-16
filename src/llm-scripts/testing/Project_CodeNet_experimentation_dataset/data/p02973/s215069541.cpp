#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N);
  multiset<ll> B;
  rep(i,N){
    cin >> A.at(i);
    if(i==0){
      B.insert(A.at(i));
    }else{
      auto a=B.lower_bound(A.at(i));
      if(a==B.begin()){
        B.insert(A.at(i));
      }else{
        a--;
        B.erase(a);
        B.insert(A.at(i));
      }
    }
  }
  cout << B.size() << endl;
}