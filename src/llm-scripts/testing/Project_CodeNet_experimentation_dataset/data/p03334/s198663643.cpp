#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>
#include <iomanip>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

int fld[700][700];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N,D[2];cin>>N>>D[0]>>D[1];
  int d[2]={0,0};
  repeat(k,2){
    while(!(D[k]&1)){
      d[k]++;
      D[k]/=2;
    }
    D[k]<<=d[k];
  }
  //debugArray(d,2);
  vector<Pii> ans;
  repeat(i,2*N){
    repeat(j,2*N){
      bool isok=true;
      repeat(k,2){
        if(d[k]&1){
          isok &= !((i/(1<<((d[k]-1)/2)))&1);
        }else{
          isok &= !((i/(1<<(d[k]/2))+j/(1<<(d[k]/2)))&1);
        }
      }
      if(isok){
        fld[i][j]=1;
        ans.push_back({i,j});
      }
    }
  }
  /*
  if(ans.size()<N*N){
    cerr<<"!!!!!!!"<<endl;
    return 0;
  }
  */
/*
  repeat(i,2*N){
    repeat(j,2*N){
      cerr<<fld[i][j];
    }
    cerr<<endl;
  }
*/
  repeat(i,N*N){
    cout << ans[i].first<<" "<<ans[i].second<<endl;
  }
  return 0;
}
