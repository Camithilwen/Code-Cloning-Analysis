#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG



int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> save(N+1, -1);

  for(ll i=0; i<M; i++){
    ll a, b;
    cin >> a >> b;
    if(save[a] == -1){
        save[a] = b;
    }else if (save[a] == b)
    {
        save[a] = b;
    }else{
        cout  << "-1" << endl;
        return 0;
    }
  }
  if(save[1] == 0 && N!=1){
      cout  << "-1" << endl;
      return 0;
  }

  for(ll i=1; i<=N; i++){      
      if(save[i]!=-1){
          cout << save[i];
      }else{
          if(i==1){
              if(N==1) cout << 0;
              else  cout << 1;
          }

          else cout << 0;
      }
  }
  
 
  cout << endl;
  return 0;
}
