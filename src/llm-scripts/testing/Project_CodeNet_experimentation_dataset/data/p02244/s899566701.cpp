#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int main(){
  int k;
  cin >> k;

  VI col(8,-1);
  REP(i,k){
    int r, c;
    cin>> r >> c;
    col[c] = r;
  }

  VI a = {0,1,2,3,4,5,6,7};
  VI ans;
  do {
    bool ok=true;
    set<int> st;
    REP(i,8){
      if(col[i] != -1 && col[i] != a[i])ok=false;
    }
    if(!ok)continue;

    ok=true;

    REP(i,8){
      FOR(j,i+1,8){
        if(abs(i - j) == abs(a[i] - a[j]))ok=false;
      }
    }

    if(ok){
      ans = a;
      break;
    }

  }while(next_permutation(ALL(a)));

  REP(i,8){
    REP(j,8){
      if(ans[j]==i)cout << "Q";
      else cout << ".";
    }
    cout << endl;
  }
}

