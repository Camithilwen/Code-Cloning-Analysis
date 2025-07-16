#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

const long INF = 1e9 + 1;

int main() {
  long n,sum = 0;
  cin >> n;

  for(long i = 1; i <= n; i++) {
    if(i % 3 == 0 || i % 5 == 0) continue;
    sum += i;
  }

  cout << sum << endl;
}