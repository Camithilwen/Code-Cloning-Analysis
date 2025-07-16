#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using ll = long long;

int main(){
    int D, G, p[11], c[11];
    cin >> D >> G;
    for(int i = 0; i < D; ++i){
        cin >> p[i] >> c[i];
    }
 
    int ans = 1e9;
    rep(tmp, 1<<D){
      int scr = 0, num = 0, max_id = -1;
      rep(i,D){
        if((tmp>>i) & 1){
          scr += 100 * (i+1) * p[i] + c[i];
          num += p[i];
        }else{
          max_id = i;
        }
      }
      if(scr < G){
        int sum = 100 * (max_id + 1);
        int rmn = (G - scr + sum - 1) / sum;
        if(rmn >= p[max_id]){
          continue;
        }
        num += rmn;
      }
      ans = min(ans, num);
    }
    cout << ans << endl;
}