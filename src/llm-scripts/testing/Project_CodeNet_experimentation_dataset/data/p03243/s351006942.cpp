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
  string n;
  cin >> n;

  while(1) {
    if(n[0] == n[1] & n[1] == n[2]){
      cout << n << endl;
      return 0;
    }
    else {
      int t = stoi(n);
      t++;
      n = to_string(t);
    }
  }
}