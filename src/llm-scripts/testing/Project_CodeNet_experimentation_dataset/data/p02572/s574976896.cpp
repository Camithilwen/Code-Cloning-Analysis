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
const long INF = 2000000000;

int main() {
  long n;
  cin >> n;
  long a[n];
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  long sum[n];
  sum[n-1] = a[n-1];
  for(int i = n-2; i >= 0; i--)
    sum[i] = sum[i+1] + a[i];
  
  long ans = 0;
  for(int i = 0; i < n-1; i++)
    ans += (sum[i+1] % mod * a[i]) % mod;
  
  cout << ans % mod << endl;
}