#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;

int main()
{
  int n, k;
  while(cin >> n, n) {
    cin >> k;
    set<string> SET;
    vector<string> vs(n); FOR(i,0,n) cin >> vs[i];
    FOR(i,0,1<<n) {
      vector<int> v;
      int cnt = 0;
      FOR(j,0,n) {
        if((i>>j)&1) {
          cnt++;
          v.push_back(j);
        }
      }
      if(cnt != k) continue;
      do {
        string s = "";
        FOR(l,0,k) s = s + vs[v[l]];
        SET.insert(s);
      } while(next_permutation(v.begin(), v.end()));
    }
    cout << SET.size() << endl;
  } 
  
  return 0;
}