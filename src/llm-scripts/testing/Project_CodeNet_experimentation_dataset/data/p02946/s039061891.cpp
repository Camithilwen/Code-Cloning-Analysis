#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int k, x;
  cin >> k >> x;

  int l = max(-1000000, x-(k-1));
  int r = min(100000, x+(k-1));

  for(int i = l; i <= r ; ++i){
    cout << i << " ";
  }
  cout << endl;
  return 0;
}