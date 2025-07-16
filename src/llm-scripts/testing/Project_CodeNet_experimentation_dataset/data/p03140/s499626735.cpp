#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define pi 3.14159265358979323846264338327950L
using namespace std;

int main() {
  int N, ans;
  string A, B, C;
  cin >> N >> A >> B >> C;
  ans=0;
  for (int i=0; i<N; i++) {
    if (A[i]==B[i] && B[i]==C[i]) {
      ans=ans;
    }
    else {
      if (A[i]==B[i] || B[i]==C[i] || C[i]==A[i]) {
        ans=ans+1;
      }
      else {
        ans=ans+2;
      }
    }
  }
  cout << ans << endl;
}
