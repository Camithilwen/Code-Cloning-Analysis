#include <bits/stdc++.h>
using namespace std;

int N;long long base=1000000007LL;

int main() {
  cin >> N;
  long long A[3][N];long long count=3LL;
  for (int i=0;i<N;i++) {
    for (int j=0;j<3;j++) {
      A[j][i]=0LL;
    }
  }
  for (int i=0;i<N;i++) {
    long long x;cin >> x;
    if (i==0) {
      A[0][0]=1LL;
      if (x!=0) count=0LL;
    }
    else {
      long long y=0LL;bool tuika=false;
      for (int j=0;j<3;j++) {
        if (A[j][i-1]==x) {
          y++;
          if (!tuika) {
            A[j][i]=A[j][i-1]+1LL;
            tuika=true;
          }
          else A[j][i]=A[j][i-1];
        }
        else A[j][i]=A[j][i-1];
      }
      count*=y;
      count=count%base;
    }
  }
  cout << count << endl;
}