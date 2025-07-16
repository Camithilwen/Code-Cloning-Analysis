#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N,Q; cin >> N >> Q;
  string S; cin >> S;

  vector<int> ans(N, 0);
  for(int i = 1; i < N; i++){
    if(S[i] == 'C' && S[i-1] == 'A'){
      ans[i] = 1;
    }
  }
  for(int i = 1; i < N; i++){
    ans[i] += ans[i-1];
    // cerr << "i: " << i << " ans[i]: " << ans[i] << endl;
  }

  while(Q--){
    int l,r; cin >> l >> r; l--; r--;
    int ret;
    if(l == 0){
      ret = ans[r];
    } else {
      ret = ans[r] - ans[l-1];
      if(S[l] == 'C' && S[l-1] == 'A'){
        ret--;
      }
    }
    cout << ret << endl;
  }



}

