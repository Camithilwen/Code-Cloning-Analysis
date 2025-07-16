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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  while(cin>>a>>b>>c,a||b||c) {
    int N; cin >> N;
    int info_[4][N];
    FOR(i,0,N) FOR(j,0,4) cin >> info_[j][i];
    int info[a+b+c+1];
    FOR(i,0,a+b+c+1) info[i] = 2;
    // ???????????????????????¨?????????
    FOR(i,0,N) if(info_[3][i] == 1) FOR(j,0,3) info[info_[j][i]] = 1;

    // ?????????????????¨?????????
    FOR(i,0,N) {
      if(info_[3][i] == 0) {
        int cnt = 0;
        FOR(j,0,3) cnt += info[info_[j][i]];
        if(cnt == 4) {
          FOR(j,0,3) if(info[info_[j][i]] == 2) info[info_[j][i]] = 1000;
        }
      }
    }
    FOR(i,1,a+b+c+1) cout << (info[i] == 1000 ? 0 : info[i]) << '\n';
  }
  return 0;
}