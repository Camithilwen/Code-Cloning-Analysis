#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

string transform(string t, ll x, ll y){
  for (ll i = 0; i < t.size(); i++){
    if (t[i] == 'R' && x < 0){
      t[i] = 'L'; 
    }
    else if (t[i] == 'L' && x < 0){
      t[i] = 'R'; 
    }
    else if (t[i] == 'U' && y < 0){
      t[i] = 'D'; 
    }
    else if (t[i] == 'D' && y < 0){
      t[i] = 'U'; 
    }
  }
  return t;
}

int main(void){
  ll sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  
  tx -= sx;
  ty -= sy;

  sx = tx;
  sy = ty;

  tx = abs(tx);
  ty = abs(ty);

  string t = "";
  // 1周目
  for (ll i = 0; i < ty; i++){
    t += "U";
  }
  for (ll i = 0; i < tx; i++){
    t += "R";
  }
  for (ll i = 0; i < ty; i++){
    t += "D";
  }
  for (ll i = 0; i < tx; i++){
    t += "L";
  }

  // 1周目
  t += "L";
  for (ll i = 0; i < ty + 1; i++){
    t += "U";
  }
  for (ll i = 0; i < tx + 1; i++){
    t += "R";
  }
  t += "D";
  t += "R";
  for (ll i = 0; i < ty + 1; i++){
    t += "D";
  }
  for (ll i = 0; i < tx + 1; i++){
    t += "L";
  }
  t += "U";

  cout << transform(t, sx, sy) << endl;
  for (ll i = 0; i < ty; i++){
    t += "D";
  }
  for (ll i = 0; i < tx; i++){
    t += "L";
  }



  return 0;
}
