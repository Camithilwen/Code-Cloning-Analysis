#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N;
  cin >> N;

  vc S;

  if(N == 0){
    cout << 0 << endl;
    return 0;
  }
  
  while(N != 0){
    if(N % (-2) == 0){
      S.push_back('0');
    } else{
      S.push_back('1');
      N--;
    }

    N /= -2;
  }

  rep_inv(i, S.size() - 1, -1) cout << S[i];

  cout << "\n";
  
  return 0;
}
