#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
   string S;
   cin >> S;
   string T = S.substr(2, S.size()-3);
   int count = 0;
   rep(i, T.size()) if( T[i] == 'C' ) count++;
   int o = 0;
   rep(i, S.size()) if( S[i] < 'a' || S[i] > 'z' ) o++;
   if( S.substr(0,1) == "A" && count == 1 && o == 2 ) cout << "AC" << endl;
   else cout << "WA" << endl;
}