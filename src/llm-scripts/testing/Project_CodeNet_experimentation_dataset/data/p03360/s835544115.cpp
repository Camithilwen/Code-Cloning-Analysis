#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
 int a,b,c,k;
 cin >> a >> b >> c >> k;
 rep(i,k){
   if(max({a,b,c}) == a) a *= 2;
   else if(max({a,b,c}) == b) b *= 2;
   else c *= 2;
 }
 cout << a+ b + c << endl;
 } 