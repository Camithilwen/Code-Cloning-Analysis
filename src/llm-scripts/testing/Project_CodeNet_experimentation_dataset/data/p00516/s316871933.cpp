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
#include <deque>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;cin>>n>>m;
  int A[n], B[m];
  FOR(i,0,n)cin>>A[i];
  FOR(i,0,m)cin>>B[i];
  int cnt[n+1];
  int ans = -1, num = 0;
  CLR(cnt);
  FOR(i,0,m){
      FOR(j,0,n){
          if(A[j] <= B[i]){
              cnt[j+1]++;
              if(cnt[j+1] > cnt[ans]) ans = j + 1;
              break;
          }
      }
  }
  cout << ans << endl;
}
