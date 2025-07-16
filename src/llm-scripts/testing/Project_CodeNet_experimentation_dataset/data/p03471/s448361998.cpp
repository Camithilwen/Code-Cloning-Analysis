#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  int N,y;
  cin >> N >> y;
  for(int i = 0; i<= N; i++){
    for(int j = 0; i+j<= N; j++){
      if(10000*i+5000*j+(N-i-j)*1000==y){
        cout << i << " " << j << " " << N-i-j << endl;
        return 0;
      }
    }
  }
  
  cout << "-1 -1 -1" << endl;
}      