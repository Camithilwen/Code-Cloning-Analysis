#include <bits/stdc++.h>
#define rep(i,a,n) for (int i = (a); i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  ll n;
  cin >> n;
  string s;
  while(n>0){
    int r = n%26;
    char c;
    if(r>0) c = 'a' + r - 1;
    else c = 'z';
    s += c;
    n /= 26;
    if(r==0) n--;
  }
  reverse(s.begin(),s.end());
  cout << s << endl;
  return 0;
}