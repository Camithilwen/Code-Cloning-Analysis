#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

int main(){
  int n,k;
  while(cin>>n>>k){
    if(n==0) break;
    vector<int> seq(n);
    set<string> ans;
    REP(i,n) cin>>seq[i];
    for(int i = 0; i < 1<<n; i++){
      int cnt = 0;
      REP(j,n){
        cnt += (i>>j)&1;
      }
      if(cnt != k) continue;
      vector<int> selected;
      REP(j,n) if((i>>j)&1){
        selected.push_back(seq[j]);
      }
      sort(selected.begin(), selected.end());
      do{
        stringstream ss;
        REP(j,selected.size()) ss << selected[j];
        ans.insert(ss.str());
      }while(next_permutation(selected.begin(), selected.end()));
    }
    printf("%d\n",(int)ans.size());
  }
  return 0;
}