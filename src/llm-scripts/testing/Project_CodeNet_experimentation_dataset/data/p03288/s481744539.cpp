#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int r;
  cin >> r;
  if(r < 1200){
    cout << "ABC" << endl;
    return 0;
  }
  if(r < 2800){
    cout << "ARC" << endl;
    return 0;
  }
  if(r>=2800){
    cout << "AGC" << endl;
  }
  return 0;
}
