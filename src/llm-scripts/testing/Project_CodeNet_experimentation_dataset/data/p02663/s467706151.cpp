#include <bits/stdc++.h>
#include<math.h>
using namespace std;
using ll = long long;

int main(){ 
  int  h1, m1, h2, m2 ,k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  int h3 = h2 -1;
  int m3 = m2 + 60;
  int a = (h3-h1)*60+(m3-m1);
  cout << max(a-k, 0) << endl;
  return 0;
} 