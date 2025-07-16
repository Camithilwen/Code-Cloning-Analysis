#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll = long long;

int f(int x){
  if(x < 0){x *= (-1);}
  return x;
}

int main(){
  int n; cin >> n;
  vector<int> v(n+10, 0);
  int time = 0;
  for(int i = 1; i <= n; i++){
    cin >> v[i];
    time += f(v[i] - v[i-1]);
  }
  time += f(v[n]);

  for(int i = 1; i <= n; i++){
    int res = time;
    if(v[i+1] >= v[i] && v[i] >= v[i-1]){cout << res << endl; continue;}
    else if(v[i+1] <= v[i] && v[i] <= v[i-1]){cout << res << endl; continue;}
    else if((v[i] - v[i-1]) * (v[i+1] - v[i-1]) <= 0){
      res -= f(v[i-1] - v[i]) * 2; cout << res << endl; continue;
      }
    else{res -= f(v[i+1] - v[i]) * 2; cout << res << endl; continue;}
  }
}
