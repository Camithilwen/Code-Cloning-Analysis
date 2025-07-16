#include <bits/stdc++.h>
using namespace std;

using pp=pair<int,int>;

int main() {
  string S;
  cin >> S;
  string ans="AC";
  if (S[0]!='A') {ans="WA";}
  int c=0, ci;
  for (int i=2; i<S.size()-1; i++) {
    if (S[i]=='C') {
      c++;
      ci=i;
    }
  }
  if (c!=1) {ans="WA";}
  for (int i=0; i<S.size(); i++) {
    if (i==0 || i==ci) {continue;}
    if (S[i]-'Z'<=0) {
      ans="WA";
      break;
    }
  }
  cout << ans << endl;
}