#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main(){
	string s; cin>>s;
  if (s[0] == 'R' && s[1] == 'R' && s[2] == 'R') cout << 3 << endl;
  else if ((s[0] == 'R' && s[1] == 'R') || (s[1] == 'R' && s[2] == 'R')) cout << 2 << endl;
  else if (s[0] == s[1] && s[1] == s[2] && s[0] == 'S') cout << 0 << endl;
  else cout << 1 << endl;
}
