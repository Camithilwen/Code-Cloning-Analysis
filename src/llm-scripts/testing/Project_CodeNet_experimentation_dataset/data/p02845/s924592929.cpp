#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()
const ll mod = 1e9+7;

int main(){
  ll N;cin>>N;
  vector<int> A(N);rep(i,N)cin>>A[i];
  map<int,int> m;
  ll ans = 1;
  rep(i,N){
    m[A[i]]++;
    if(A[i]==0){
      ans *= 4 - m[0];
    }
    else{
      ans *= (m[A[i]-1] - m[A[i]] + 1);
    }
    ans %= mod;
  }
  cout << ans << endl;
}