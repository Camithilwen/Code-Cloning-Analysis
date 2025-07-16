#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> s(m);
  vector<int> c(m);
  rep(i, m){
    cin >> s[i] >> c[i];
  }
  bool zero=true;
    rep(i, m){
      if(c[i]!=0){
        zero=false;
        break;
      }
    }

  if(zero && n==1){
    cout << "0" << endl;
    return 0;
  }
  repo(i, 999){
    int i2=i;
    bool nflag=true;
    rep(j, n){
      if(i2==0){
        nflag=false;
        break;
      }
      i2/=10;
    }
    if(i2!=0){
      nflag=false;
    }
    if(!nflag){
      continue;
    }
    bool scflag=true;
    rep(j, m){
      int i3=i;
      int sn=n-s[j];
      rep(k, sn){
        i3/=10;
      }
      i3%=10;
      if(i3!=c[j]){
        scflag=false;
        break;
      }
    }
    if(scflag){
      cout << i << endl;
      return 0;
    }
  }
  cout << "-1" << endl;
  return 0;
}
