#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  string S;
  cin>>S;
  int ans=0,sc=0;
  for(auto c:S){
    if(c=='S'){
      sc++;
      ans++;
    }else{
      if(sc>0){
        ans--;
        sc--;
      }else{
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
